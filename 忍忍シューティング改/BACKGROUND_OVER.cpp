#include "BACKGROUND_OVER.h"
#include"CONTAINER.h"
#include"GAME.h"

BACKGROUND_OVER::BACKGROUND_OVER(GAME* game) : BACKGROUND(game)
{
}

BACKGROUND_OVER::~BACKGROUND_OVER()
{
}

void BACKGROUND_OVER::create()
{
	Data = game()->container()->backgroundOver();
}

void BACKGROUND_OVER::init()
{
	Data.sprite.setTexture(Data.texture);
	Data.sprite.setPosition(Data.pos);
	Data.sprite.setScale(Data.scale);
}

void BACKGROUND_OVER::draw()
{
	game()->window()->draw(Data.sprite);
}

