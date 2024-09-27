#include "PLAYER_BULLETS.h"
#include"CONTAINER.h"
#include"GAME.h"

PLAYER_BULLETS::PLAYER_BULLETS(GAME* game) : BULLETS(game)
{
}


void PLAYER_BULLETS::create()
{
	SetBullets(game()->container()->playerBullet());
}
