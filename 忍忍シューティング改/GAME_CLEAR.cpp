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

	game()->transition()->inTrigger();//�������n��

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

	//�w�i��draw()��ԍŏ��ɂ��
	game()->backgrounds(curSceneId)->draw();

	//GAME_OBJECT�N���X��game()���Ă�ŁAGAME�N���X�̃|�C���^����āAWindow�̃|�C���^����āAdraw()���Ă�
	game()->window()->draw(GameClear.sprite);
	game()->transition()->draw();
}

void GAME_CLEAR::nextScene()
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
		game()->changeScene(GAME::TITLE_ID); //TITLE�ɖ߂�
	}
}

void GAME_CLEAR::create()
{
	GameClear = game()->container()->gameClear();
}


