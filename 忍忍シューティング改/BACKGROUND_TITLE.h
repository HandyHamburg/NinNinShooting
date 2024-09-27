#pragma once
#include "BACKGROUND.h"
#include<SFML/Graphics.hpp>
class BACKGROUND_TITLE :
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
    BACKGROUND_TITLE(class GAME* game);
    ~BACKGROUND_TITLE();
    void create();
    void init();
    void draw();
};

