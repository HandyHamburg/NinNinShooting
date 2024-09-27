#include "BACKGROUND_STAGE.h"
#include"CONTAINER.h"
#include"GAME.h"

BACKGROUND_STAGE::BACKGROUND_STAGE(GAME* game) : BACKGROUND(game)
{
}

BACKGROUND_STAGE::~BACKGROUND_STAGE()
{
}

void BACKGROUND_STAGE::create()
{
	Data = game()->container()->backgroundStage();
}

void BACKGROUND_STAGE::init()
{
	Data.sprite.setTexture(Data.texture);
	Data.sprite.setPosition(Data.pos);
	Data.sprite.setScale(Data.scale);
}

void BACKGROUND_STAGE::draw()
{
	game()->window()->draw(Data.sprite);
}

