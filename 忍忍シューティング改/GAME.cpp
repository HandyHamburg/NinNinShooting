#include"GAME.h"
#include"SCENE.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"TRANSITION_FADE.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BOSS.h"
#include"PLAYER_BULLETS.h"
#include"IZUNA_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"ITEMS.h"
#include"POWER_ITEMS.h"
#include"IZUNA_ITEMS.h"
#include<iostream>

GAME::GAME()
{
	Window = nullptr;

	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	Transition = new TRANSITION_FADE(this);

	Backgrounds[TITLE_ID] = new BACKGROUND_TITLE(this);
	Backgrounds[STAGE_ID] = new BACKGROUND_STAGE(this);
	Backgrounds[GAME_CLEAR_ID] = new BACKGROUND_CLEAR(this);
	Backgrounds[GAME_OVER_ID] = new BACKGROUND_OVER(this);

	Player = new PLAYER(this);
	Enemies = new ENEMIES(this);
	Boss = new BOSS(this);
	PlayerBullets = new PLAYER_BULLETS(this);
	IzunaBullets = new IZUNA_BULLETS(this);
	EnemyBullets = new ENEMY_BULLETS(this);
	PowerItems = new POWER_ITEMS(this);
	IzunaItems = new IZUNA_ITEMS(this);
	Explosions = new EXPLOSIONS(this);
}

GAME::~GAME()
{
	delete Window;
	delete Container;
	for (int i = 0; i < NUM_SCENES; i++)
	{
		delete Scenes[i];
		delete Backgrounds[i];
	}
	delete Transition;
	delete Player;
	delete Enemies;
	delete Boss;
	delete PlayerBullets;
	delete IzunaBullets;
	delete EnemyBullets;
	delete PowerItems;
	delete IzunaItems;
	delete Explosions;
}

void GAME::pollEvent()
{
	while (Window->pollEvent(Ev))
	{
		switch (Ev.type)
		{
		case sf::Event::Closed:
			Window->close();
			break;
		case sf::Event::KeyPressed:

			if (Ev.key.code == sf::Keyboard::Escape)
				Window->close();
			break;
		}
	}
}

void GAME::changeScene(SCENE_ID sceneId)
{
	CurSceneId = sceneId;
	Scenes[CurSceneId]->init();
	Backgrounds[CurSceneId]->init();
}

//Stage�̃|�C���^��Ԃ���
STAGE* GAME::stage()
{
	return dynamic_cast<STAGE*>(Scenes[STAGE_ID]);
}

bool GAME::keyHoldSetter(bool keyhold)
{
	KeyHold = keyhold;

	return KeyHold;
}

void GAME::run()
{
	//�����̏�����
	srand(static_cast<unsigned> (time(NULL)));

	//�E�B���h�E����
	VideoMode.width = 600; //��600
	VideoMode.height = 800; //�c800
	Window = new sf::RenderWindow(VideoMode, L"�E�E�V���[�e�B���O��", sf::Style::Titlebar | sf::Style::Close);
	Window->setFramerateLimit(60);

	//�f�[�^�̍쐬
	Container->load();

	//�ecreate()��܂��Ă�
	for (int i = 0; i < NUM_SCENES; i++)
	{
		Scenes[i]->create();
		Backgrounds[i]->create();
	}
	Transition->create();
	Player->create();
	Enemies->create();
	Boss->create();
	PlayerBullets->create();
	IzunaBullets->create();
	EnemyBullets->create();
	PowerItems->create();
	IzunaItems->create();
	Explosions->create();

	//�ŏ��̓^�C�g������
	CurSceneId = TITLE_ID;
	Scenes[CurSceneId]->init();
	//�Q�[�����[�v
	while (running())
	{

		//DeltaTimer���Z�b�g
		Timer = DeltaClock.restart().asSeconds();

		//�E�B���h�E������ꂽ���ǂ����̔���
		pollEvent();

		//�܂��N���A����
		Window->clear(sf::Color(255,255,255));

		//���݂̃V�[���̏���(Update�y��Render(�`��))
		Scenes[CurSceneId]->proc();

		//�\��
		Window->display();
	}
}




