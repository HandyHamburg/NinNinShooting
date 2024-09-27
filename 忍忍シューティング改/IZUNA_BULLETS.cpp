#include "IZUNA_BULLETS.h"
#include"CONTAINER.h"
#include"GAME.h"

IZUNA_BULLETS::IZUNA_BULLETS(GAME* game) : BULLETS(game)
{
}


void IZUNA_BULLETS::create()
{
	SetBullets(game()->container()->izunaBullet());
}
