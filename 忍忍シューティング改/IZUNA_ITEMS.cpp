#include "IZUNA_ITEMS.h"
#include"GAME.h"
#include"CONTAINER.h"

IZUNA_ITEMS::IZUNA_ITEMS(GAME* game) : ITEMS(game)
{

}

void IZUNA_ITEMS::create()
{
	SetItems(game()->container()->izunaItem());
}
