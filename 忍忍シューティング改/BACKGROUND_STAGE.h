#pragma once
#include "BACKGROUND.h"
#include<SFML/Graphics.hpp>
class BACKGROUND_STAGE :
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
    BACKGROUND_STAGE(class GAME* game);
    ~BACKGROUND_STAGE();
    void create();
    void init();
    void draw();
};

