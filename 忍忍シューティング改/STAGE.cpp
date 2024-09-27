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
	//�p�^�[��0����ĊJ
	Stage.no = game()->container()->stage().iniNo;

	game()->transition()->inTrigger();//�������n��
	game()->player()->init();
	game()->enemies()->init();
	game()->boss()->init();
	game()->playerBullets()->init();
	game()->izunaBullets()->init();
	game()->enemyBullets()->init();
	game()->powerItems()->init();
	game()->izunaItems()->init();
	game()->explosions()->init();

	//���S���̕���
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
	//�A�C�e���̃h���b�v
	if (game()->container()->powerItem().dropRange >= rand() % 1000)
	{
		sf::Vector2f randPos = { static_cast <float>(rand() % game()->window()->getSize().x), -100.0f }; //(�E�B���h�E�̉��������_���ʒu, -100�Ƀh���b�v)
		game()->powerItems()->launch(randPos,
			game()->container()->powerItem().texture);
	}


	if (game()->container()->izunaItem().dropRange >= rand() % 1000)
	{
		sf::Vector2f randPos = { static_cast <float>(rand() % game()->window()->getSize().x), -100.0f }; //(�E�B���h�E�̉��������_���ʒu, -100�Ƀh���b�v)
		game()->izunaItems()->launch(randPos,
			game()->container()->izunaItem().texture);
	}

	//�Q�[���I�[�o�[���̉��o
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

	//�w�i��draw()��ԍŏ��ɂ��
	game()->backgrounds(curSceneId)->draw();

	//�L�����N�^�[��draw()
	game()->player()->draw();
	//game()->enemies()->draw();
	game()->boss()->draw();
	game()->powerItems()->draw();
	game()->izunaItems()->draw();
	game()->explosions()->draw();
	game()->playerBullets()->draw();
	game()->izunaBullets()->draw();
	game()->enemyBullets()->draw();

	//��ʑJ��
	game()->transition()->draw(); //Transition�͈�ԍŌ�ɌĂԁB�ォ��Ă΂ꂽ���̂���Ԏ�O�ɕ\�������̂ŁB

	if (game()->player()->hp() <= 0)
	{
		game()->window()->draw(Stage.text);
	}
	
}

void STAGE::nextScene()
{
	//�G�̐���0�ȉ��Ȃ�
	if (game()->boss()->hp() <= 0)
	{


		game()->transition()->outTrigger();

		if (game()->transition()->outEndFlag())//�s�������������I�������V�[���J��
		{
			game()->changeScene(GAME::GAME_CLEAR_ID);//GAMECLEAR
		}


		/*
		//�X�e�[�W�ԍ����p�^�[�������Ȃ�
		if (Stage.no < Stage.ptnNo && game()->boss()->hp() > 0)
		{
			Stage.no++;
			game()->enemies()->init();
		}
		//�X�e�[�W���S���I�������
		else if (game()->boss()->hp() <= 0)
		{
			
		}
		*/
	}

	//�̗�0�ŃQ�[���I�[�o�[
	if (game()->player()->hp() == 0)
	{
		game()->transition()->outTrigger();

		if (game()->transition()->outEndFlag())//�s�������������I�������V�[���J��
		{
			game()->changeScene(GAME::GAME_OVER_ID);//GAMEOVER
		}
	}
}

void STAGE::create()
{
	Stage = game()->container()->stage();
}


