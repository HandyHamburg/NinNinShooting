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
	game()->transition()->inTrigger();//�������n��
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
	//GAME_OBJECT�N���X��game()���Ă�ŁAGAME�N���X�̃|�C���^����āAWindow�̃|�C���^����āAdraw()���Ă�
	game()->transition()->draw();
	game()->window()->draw(GameOver.text);
	game()->window()->draw(GameOver.text2);
}

void GAME_OVER::nextScene()
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

	//if (game()->transition()->outEndFlag())//�s�������������I�������V�[���J��
	if(game()->transition()->outEndFlag())
	{
		game()->changeScene(GAME::TITLE_ID);//TITLE�ɖ߂�
	}
}

void GAME_OVER::create()
{
	GameOver = game()->container()->gameOver();
}


