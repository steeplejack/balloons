//
// Created by Kevin Gori on 04/07/15.
//

#include "sprites.h"
#include <memory>
#include <SFML/Graphics/CircleShape.hpp>

float CIRCLE_DEFAULT_SIZE = 100.f;
float CIRCLE_DEFAULT_SPEED = 1.f;

MyCircle::MyCircle(sf::RenderWindow* window) {
    my_window = window;
    circle = std::make_shared<sf::CircleShape>();
    setRadius(CIRCLE_DEFAULT_SIZE);
    setSpeed(CIRCLE_DEFAULT_SPEED, CIRCLE_DEFAULT_SPEED);
    centre();
}

void MyCircle::setRadius(float rad) {
    auto size = my_window->getSize();
    this->circle->setRadius(rad);
    x_max = size.x - 2 * rad;
    y_max = size.y - 2 * rad;
}

sf::FloatRect MyCircle::getGlobalBounds() {
    circle->getGlobalBounds();
}

void MyCircle::centre() {
    auto size = my_window->getSize();
    auto rad = circle->getRadius();
    float x = size.x - rad;
    float y = size.y - rad;
    setPosition(x, y);
}

void MyCircle::setSpeed(float xspeed, float yspeed) {
    x_speed = xspeed;
    y_speed = yspeed;
}

void MyCircle::setPosition(float x, float y) {
    circle->setPosition(x, y);
    circle->getPosition();
}

void MyCircle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*circle, states);
}

void MyCircle::setFillColor(sf::Color colour) {
    circle->setFillColor(colour);
}

void MyCircle::setDirection(int x, int y) {
    x_direction = x;
    y_direction = y;
}

const sf::Vector2f &MyCircle::getPosition() {
    return circle->getPosition();
}

float MyCircle::getRadius() {
    return circle->getRadius();
}
