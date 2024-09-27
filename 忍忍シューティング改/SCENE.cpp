#include "SCENE.h"
#include "GAME_OBJECT.h"

SCENE::SCENE(GAME* game) : GAME_OBJECT(game)
{
}

SCENE::~SCENE()
{
}

void SCENE::create()
{
}

void SCENE::init()
{
}

void SCENE::proc()
{
	update();
	draw();
	nextScene();
}

void SCENE::update()
{
}

void SCENE::draw()
{
}

void SCENE::nextScene()
{
}
