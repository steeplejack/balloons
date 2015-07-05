#include <SFML/Graphics.hpp>
#include "sprites.h"
#include <random>
#include <list>
#include <iostream>
#include <vector>

std::vector<sf::Color> colours{
    sf::Color::Blue,
    sf::Color::Red,
    sf::Color::Green,
    sf::Color::Magenta,
    sf::Color::Cyan,
    sf::Color::White
};

double XSPEED = 3.0;
double YSPEED = 3.0;
int NUMCIRCLES = 6000;
double CIRCLERADIUS = 60.0;

std::random_device rd;
std::mt19937 gen(rd());

float random_float(float lower, float upper) {
    std::uniform_real_distribution<> rx(lower, upper);
    return (float)rx(gen);
}

float random_int(int lower, int upper) {
    std::uniform_int_distribution<> rx(lower, upper);
    return rx(gen);
}

int random_direction() {
    std::uniform_int_distribution<> rx(0, 1);
    int val = rx(gen);
    return val == 0 ? -1 : 1;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1200), "Do not pop the balloons!");
    std::vector<MyCircle> shapes;

    int active_circles = NUMCIRCLES;
    auto size = window.getSize();

    for (int i=0; i < NUMCIRCLES; ++i) {
        MyCircle shape(&window);
        shape.setRadius(random_float(0.66*CIRCLERADIUS, 1.33*CIRCLERADIUS));
        shape.setPosition(random_float(0, shape.x_max), random_float(0, shape.y_max));
        shape.setFillColor(colours[random_int(0, colours.size()-1)]);
        //shape.setFillColor(sf::Color::Black);
        shape.setDirection(random_direction(), random_direction());
        shape.setSpeed(random_float(0, XSPEED), random_float(0, YSPEED));
        shapes.push_back(shape);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Yellow);
        for (int i=0; i < NUMCIRCLES; ++i) {
            auto pos = shapes[i].getPosition();
            auto rad = shapes[i].getRadius();
            auto x = pos.x;
            auto y = pos.y;

            //Get mouse click
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                auto mouse_pos = sf::Mouse::getPosition(window);
                if (mouse_pos.x > x && mouse_pos.x < x + 2*rad &&
                    mouse_pos.y > y && mouse_pos.y < y + 2*rad) {
                    shapes[i].setFillColor(sf::Color::Transparent);
                    shapes[i].setRadius(0.f);
                    shapes[i].setSpeed(0.f, 0.f);
                    active_circles -= 1;

                    if (active_circles == 0) window.close();
                }
            }

            // From here is the code to make the ball bounce left to right
            if (x >= shapes[i].x_max) {
                shapes[i].x_direction = -1;
            }

            if (x <= 0) {
                shapes[i].x_direction = 1;
            }

            x += shapes[i].x_speed * shapes[i].x_direction;
            // End

            // Copy the above code, but swap Y for X to make the ball bounce up and down
            if (y >= shapes[i].y_max) {
                shapes[i].y_direction = -1;
            }

            if (y <= 0) {
                shapes[i].y_direction = 1;
            }

            y += shapes[i].y_speed * shapes[i].y_direction;

            shapes[i].setPosition(x, y);
            window.draw(shapes[i]);
        }
        window.display();
    }

    return 0;
}