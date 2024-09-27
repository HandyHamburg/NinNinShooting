#pragma once
#include"TITLE.h"
#include"BACKGROUND_TITLE.h"
#include"STAGE.h"
#include"BACKGROUND_STAGE.h"
#include"GAME_CLEAR.h"
#include"BACKGROUND_CLEAR.h"
#include"GAME_OVER.h"
#include"BACKGROUND_OVER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BOSS.h"
#include"TONGUE.h"
#include"BULLETS.h"
#include"ITEMS.h"
#include"EXPLOSIONS.h"
class CONTAINER
{
private:
	struct DATA
	{
		TITLE::DATA title;
		BACKGROUND_TITLE::DATA backgroundTitle;
		STAGE::DATA stage;
		BACKGROUND_STAGE::DATA backgroundStage;
		GAME_OVER::DATA gameOver;
		BACKGROUND_OVER::DATA backgroundOver;
		GAME_CLEAR::DATA gameClear;
		BACKGROUND_CLEAR::DATA backgroundClear;
		PLAYER::DATA player;
		ENEMIES::DATA enemy;
		BOSS::DATA boss;
		TONGUE::DATA tongue;
		BULLETS::DATA playerBullet;
		BULLETS::DATA enemyBullet;
		BULLETS::DATA izunaBullet;
		ITEMS::DATA powerItem;
		ITEMS::DATA izunaItem;
		EXPLOSIONS::DATA explosion;
		
	};
	DATA Data;
public:
	void load();
	void loadGraphic();
	void loadSound();
	void createData();
	const TITLE::DATA& title() { return Data.title; }
	const BACKGROUND_TITLE::DATA& backgroundTitle() { return Data.backgroundTitle; }
	const STAGE::DATA& stage() { return Data.stage; }
	const BACKGROUND_STAGE::DATA& backgroundStage() { return Data.backgroundStage; }
	const GAME_CLEAR::DATA& gameClear() { return Data.gameClear; }
	const BACKGROUND_CLEAR::DATA& backgroundClear() { return Data.backgroundClear; }
	const GAME_OVER::DATA& gameOver() { return Data.gameOver; }
	const BACKGROUND_OVER::DATA& backgroundOver() { return Data.backgroundOver; }
	const PLAYER::DATA& player() { return Data.player; }
	const ENEMIES::DATA& enemy() { return Data.enemy; }
	const BOSS::DATA& boss() { return Data.boss; }
	const TONGUE::DATA& tongue() { return Data.tongue; }
	const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
	const BULLETS::DATA& enemyBullet() { return Data.enemyBullet; }
	const BULLETS::DATA& izunaBullet() { return Data.izunaBullet; }
	const ITEMS::DATA& powerItem() { return Data.powerItem; }
	const ITEMS::DATA& izunaItem() { return Data.izunaItem; }
	const EXPLOSIONS::DATA& explosion() { return Data.explosion; }
};

