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
	game()->transition()->inTrigger();//�������n��

	//Container��load()�����create()���ꂽ�e�萔���Z�b�g
	Title.text.setFont(Title.font);
	Title.text.setFillColor(Title.textColor);
	Title.text.setCharacterSize(Title.charactorSize);
	Title.text.setPosition(Title.pos);
	Title.text.setString(Title.str);

	//TITLE�Ƀ~�`���������o��
	game()->player()->init();
}

void TITLE::update()
{
	game()->player()->update();
}

void TITLE::draw()
{
	//GAME_OBJECT�N���X��game()���Ă�ŁAGAME�N���X�̃|�C���^����āAWindow�̃|�C���^����āAdraw()���Ă�
	game()->window()->draw(Title.text);
	game()->player()->draw();
	game()->transition()->draw();
}

void TITLE::nextScene()
{
	//Z�������ꂽ�珈��
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		//KeyHold��False�Ȃ珈��
		if (game()->keyHoldGetter() == false)
		{
			game()->keyHoldSetter(true);//KeyHold��true�ɂȂ�
			game()->transition()->outTrigger();//�s�������n��
		}
	}
	else
	{
		//Z��������ĂȂ����KeyHold��false�ɖ߂�
		game()->keyHoldSetter(false);
	}

	if (game()->transition()->outEndFlag())//�s�������������I�������V�[���J��
	{
		game()->changeScene(GAME::STAGE_ID);//STAGE�ɍs��
	}
}

void TITLE::create()
{
	Title = game()->container()->title();
}


