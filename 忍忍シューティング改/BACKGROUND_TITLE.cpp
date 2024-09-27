#include "BACKGROUND_TITLE.h"
#include"CONTAINER.h"
#include"GAME.h"

BACKGROUND_TITLE::BACKGROUND_TITLE(GAME* game) : BACKGROUND(game)
{
}

BACKGROUND_TITLE::~BACKGROUND_TITLE()
{
}

void BACKGROUND_TITLE::create()
{
	Data = game()->container()->backgroundTitle();
}

void BACKGROUND_TITLE::init()
{
	Data.sprite.setTexture(Data.texture);
	Data.sprite.setPosition(Data.pos);
	Data.sprite.setScale(Data.scale);
}

void BACKGROUND_TITLE::draw()
{
	game()->window()->draw(Data.sprite);
}

