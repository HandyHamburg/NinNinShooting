#include "STAGE.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"TRANSITION.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BOSS.h"
#include"PLAYER_BULLETS.h"
#include"IZUNA_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"ITEMS.h"
#include"POWER_ITEMS.h"
#include"IZUNA_ITEMS.h"
#include"EXPLOSIONS.h"
#include<iostream>


STAGE::STAGE(GAME* game) : SCENE(game)
{
}

STAGE::~STAGE()
{

}

void STAGE::init()
{
	//パターン0から再開
	Stage.no = game()->container()->stage().iniNo;

	game()->transition()->inTrigger();//透明化始め
	game()->player()->init();
	game()->enemies()->init();
	game()->boss()->init();
	game()->playerBullets()->init();
	game()->izunaBullets()->init();
	game()->enemyBullets()->init();
	game()->powerItems()->init();
	game()->izunaItems()->init();
	game()->explosions()->init();

	//死亡時の文字
	Stage.text.setFillColor(Stage.textColor);
	Stage.text.setCharacterSize(Stage.charactorSize);
	Stage.text.setPosition(Stage.textPos);
}

void STAGE::update()
{
	game()->player()->update();
	//game()->enemies()->update();
	game()->boss()->update();
	game()->playerBullets()->update();
	game()->izunaBullets()->update();
	game()->enemyBullets()->update();
	game()->powerItems()->update();
	game()->izunaItems()->update();
	game()->explosions()->update();
	//アイテムのドロップ
	if (game()->container()->powerItem().dropRange >= rand() % 1000)
	{
		sf::Vector2f randPos = { static_cast <float>(rand() % game()->window()->getSize().x), -100.0f }; //(ウィンドウの横幅ランダム位置, -100にドロップ)
		game()->powerItems()->launch(randPos,
			game()->container()->powerItem().texture);
	}


	if (game()->container()->izunaItem().dropRange >= rand() % 1000)
	{
		sf::Vector2f randPos = { static_cast <float>(rand() % game()->window()->getSize().x), -100.0f }; //(ウィンドウの横幅ランダム位置, -100にドロップ)
		game()->izunaItems()->launch(randPos,
			game()->container()->izunaItem().texture);
	}

	//ゲームオーバー時の演出
	if (game()->player()->hp() <= 0)
	{
		Stage.text.setFillColor(sf::Color(255, 0, 0, Stage.textOpacity));

		if(Stage.textOpacity < 250)
		{
			Stage.textOpacity += 2;
		}
	}
}


void STAGE::draw()
{
	int curSceneId = game()->curSceneId();

	//背景のdraw()一番最初にやる
	game()->backgrounds(curSceneId)->draw();

	//キャラクターのdraw()
	game()->player()->draw();
	//game()->enemies()->draw();
	game()->boss()->draw();
	game()->powerItems()->draw();
	game()->izunaItems()->draw();
	game()->explosions()->draw();
	game()->playerBullets()->draw();
	game()->izunaBullets()->draw();
	game()->enemyBullets()->draw();

	//画面遷移
	game()->transition()->draw(); //Transitionは一番最後に呼ぶ。後から呼ばれたものが一番手前に表示されるので。

	if (game()->player()->hp() <= 0)
	{
		game()->window()->draw(Stage.text);
	}
	
}

void STAGE::nextScene()
{
	//敵の数が0以下なら
	if (game()->boss()->hp() <= 0)
	{


		game()->transition()->outTrigger();

		if (game()->transition()->outEndFlag())//不透明化処理が終わったらシーン遷移
		{
			game()->changeScene(GAME::GAME_CLEAR_ID);//GAMECLEAR
		}


		/*
		//ステージ番号がパターン未満なら
		if (Stage.no < Stage.ptnNo && game()->boss()->hp() > 0)
		{
			Stage.no++;
			game()->enemies()->init();
		}
		//ステージが全部終わったら
		else if (game()->boss()->hp() <= 0)
		{
			
		}
		*/
	}

	//体力0でゲームオーバー
	if (game()->player()->hp() == 0)
	{
		game()->transition()->outTrigger();

		if (game()->transition()->outEndFlag())//不透明化処理が終わったらシーン遷移
		{
			game()->changeScene(GAME::GAME_OVER_ID);//GAMEOVER
		}
	}
}

void STAGE::create()
{
	Stage = game()->container()->stage();
}


