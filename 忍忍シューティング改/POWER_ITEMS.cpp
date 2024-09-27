#include "POWER_ITEMS.h"
#include"GAME.h"
#include"CONTAINER.h"

POWER_ITEMS::POWER_ITEMS(GAME* game) : ITEMS(game)
{

}

void POWER_ITEMS::create()
{
	SetItems(game()->container()->powerItem());
}
