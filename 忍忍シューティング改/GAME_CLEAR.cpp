#include"GAME_CLEAR.h"
#include"GAME.h"
#include"CONTAINER.h"
#include<iostream>
#include<SFML/System.hpp>
#include"TRANSITION.h"

GAME_CLEAR::GAME_CLEAR(GAME* game) : SCENE(game)
{
}

GAME_CLEAR::~GAME_CLEAR()
{
}

void GAME_CLEAR::init()
{

	GameClear.sprite.setTexture(GameClear.texture);
	GameClear.sprite.setScale(GameClear.scale);
	GameClear.sprite.setOrigin(GameClear.originPos);
	GameClear.sprite.setPosition(GameClear.pos);

	game()->transition()->inTrigger();//透明化始め

	GameClear.sound.play();
}

void GAME_CLEAR::update()
{
	float delta = game()->timer();
	GameClear.angle += GameClear.angleSpeed * delta;
	GameClear.sprite.setRotation(GameClear.angle);

}

void GAME_CLEAR::draw()
{
	int curSceneId = game()->curSceneId();

	//背景のdraw()一番最初にやる
	game()->backgrounds(curSceneId)->draw();

	//GAME_OBJECTクラスのgame()を呼んで、GAMEクラスのポインタ貰って、Windowのポインタ貰って、draw()を呼ぶ
	game()->window()->draw(GameClear.sprite);
	game()->transition()->draw();
}

void GAME_CLEAR::nextScene()
{
	//Zが押されたら処理
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		//KeyHoldがFalseなら処理
		if (game()->keyHoldGetter() == false)
		{
			game()->keyHoldSetter(true);//KeyHoldがtrueになる
			game()->transition()->outTrigger();//不透明化始め
		}
	}
	else
	{
		//Zが押されてなければKeyHoldをfalseに戻す
		game()->keyHoldSetter(false);
	}


	if (game()->transition()->outEndFlag())//不透明化処理が終わったらシーン遷移
	{
		game()->changeScene(GAME::TITLE_ID); //TITLEに戻る
	}
}

void GAME_CLEAR::create()
{
	GameClear = game()->container()->gameClear();
}


