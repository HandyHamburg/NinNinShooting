#pragma once
#include "BACKGROUND.h"
#include<SFML/Graphics.hpp>
class BACKGROUND_CLEAR :
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
    BACKGROUND_CLEAR(class GAME* game);
    ~BACKGROUND_CLEAR();
    void create();
    void init();
    void draw();
};

