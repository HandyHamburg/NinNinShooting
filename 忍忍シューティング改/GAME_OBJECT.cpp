#include "GAME_OBJECT.h"

GAME_OBJECT::GAME_OBJECT(GAME* game)
{
	//受け取ったGameクラスのポインタを自分のPrivateのGAMEクラスポインタのGameにコピー
	Game = game;
}

GAME_OBJECT::~GAME_OBJECT(){}
