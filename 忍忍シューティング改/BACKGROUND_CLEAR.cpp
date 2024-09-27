#include "BACKGROUND_CLEAR.h"
#include"CONTAINER.h"
#include"GAME.h"

BACKGROUND_CLEAR::BACKGROUND_CLEAR(GAME* game) : BACKGROUND(game)
{
}

BACKGROUND_CLEAR::~BACKGROUND_CLEAR()
{
}

void BACKGROUND_CLEAR::create()
{
	Data = game()->container()->backgroundClear();
}

void BACKGROUND_CLEAR::init()
{
	Data.sprite.setTexture(Data.texture);
	Data.sprite.setPosition(Data.pos);
	Data.sprite.setScale(Data.scale);
}

void BACKGROUND_CLEAR::draw()
{
	game()->window()->draw(Data.sprite);
}

