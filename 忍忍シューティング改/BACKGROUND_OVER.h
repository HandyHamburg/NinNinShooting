#pragma once
#include "BACKGROUND.h"
#include<SFML/Graphics.hpp>
class BACKGROUND_OVER :
    public BACKGROUND
{
public:
    struct DATA
    {
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f pos;
        sf::Vector2f scale;
    };
private:
    DATA Data;
public:
    BACKGROUND_OVER(class GAME* game);
    ~BACKGROUND_OVER();
    void create();
    void init();
    void draw();
};

