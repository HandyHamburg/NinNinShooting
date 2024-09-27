#include "GAME_OVER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include<iostream>
#include<SFML/System.hpp>
#include"TRANSITION.h"

GAME_OVER::GAME_OVER(GAME* game) : SCENE(game)
{
}

GAME_OVER::~GAME_OVER()
{
}

void GAME_OVER::init()
{
	game()->transition()->inTrigger();//透明化始め
	GameOver.text2Opacity = game()->container()->gameOver().text2Opacity;
	GameOver.text.setFillColor(GameOver.textColor);
	GameOver.text.setCharacterSize(GameOver.charactorSize);
	GameOver.text.setPosition(GameOver.textPos);
	GameOver.text2.setFillColor(GameOver.text2Color);
	GameOver.text2.setCharacterSize(GameOver.charactorSize2);
	GameOver.text2.setPosition(GameOver.text2Pos);
	GameOver.sound.play();
}

void GAME_OVER::update()
{
	float delta = game()->timer();

	GameOver.text2.setFillColor(sf::Color(255, 0, 0, GameOver.text2Opacity));

	if (GameOver.text2Opacity < 250)
	{
		GameOver.text2Opacity += 1;
	}

	std::cout << GameOver.text2Opacity << "\n";
}

void GAME_OVER::draw()
{
	game()->window()->clear(sf::Color::Black);
	//GAME_OBJECTクラスのgame()を呼んで、GAMEクラスのポインタ貰って、Windowのポインタ貰って、draw()を呼ぶ
	game()->transition()->draw();
	game()->window()->draw(GameOver.text);
	game()->window()->draw(GameOver.text2);
}

void GAME_OVER::nextScene()
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

	//if (game()->transition()->outEndFlag())//不透明化処理が終わったらシーン遷移
	if(game()->transition()->outEndFlag())
	{
		game()->changeScene(GAME::TITLE_ID);//TITLEに戻る
	}
}

void GAME_OVER::create()
{
	GameOver = game()->container()->gameOver();
}


