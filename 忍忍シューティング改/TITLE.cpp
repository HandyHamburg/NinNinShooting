#include"CONTAINER.h"
#include "TITLE.h"
#include"GAME.h"
#include"TRANSITION.h"
#include<iostream>


TITLE::TITLE(GAME* game) : SCENE(game)
{
}

TITLE::~TITLE()
{
}

void TITLE::init()
{
	game()->transition()->inTrigger();//透明化始め

	//Containerにload()およびcreate()された各定数をセット
	Title.text.setFont(Title.font);
	Title.text.setFillColor(Title.textColor);
	Title.text.setCharacterSize(Title.charactorSize);
	Title.text.setPosition(Title.pos);
	Title.text.setString(Title.str);

	//TITLEにミチルっちを出す
	game()->player()->init();
}

void TITLE::update()
{
	game()->player()->update();
}

void TITLE::draw()
{
	//GAME_OBJECTクラスのgame()を呼んで、GAMEクラスのポインタ貰って、Windowのポインタ貰って、draw()を呼ぶ
	game()->window()->draw(Title.text);
	game()->player()->draw();
	game()->transition()->draw();
}

void TITLE::nextScene()
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
		game()->changeScene(GAME::STAGE_ID);//STAGEに行く
	}
}

void TITLE::create()
{
	Title = game()->container()->title();
}


