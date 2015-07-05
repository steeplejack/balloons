//
// Created by Kevin Gori on 04/07/15.
//

#ifndef SFML_GAMEDEV_SPRITES_H
#define SFML_GAMEDEV_SPRITES_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <SFML/Graphics/CircleShape.hpp>

class MyCircle :
        public sf::Drawable {
public:
    MyCircle(sf::RenderWindow* window);
    void setRadius(float rad);
    float getRadius();
    void centre();
    void setSpeed(float xspeed, float yspeed);
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds();
    const sf::Vector2f& getPosition();
    void setFillColor(sf::Color colour);
    void setDirection(int x, int y);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    // Bounds
    float x_min;
    float y_min;

    float x_max;
    float y_max;

    // Position
    float x;
    float y;

    // Movement
    float x_speed;
    float y_speed;

    int x_direction;
    int y_direction;

    // Data
    std::shared_ptr<sf::CircleShape> circle;
    sf::RenderWindow* my_window;
};

#endif //SFML_GAMEDEV_SPRITES_H
