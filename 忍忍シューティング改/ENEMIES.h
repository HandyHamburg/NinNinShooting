#pragma once
#include "GAME_OBJECT.h"
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class ENEMIES : public GAME_OBJECT
{
public:
	struct DATA
	{
		sf::Texture texture;
		sf::Vector2f scale;
		sf::Vector2f originPos;	
		sf::Vector2f vec;
		sf::Vector2f ofstLaunchDist;
		//���[�u�p�^�[������
		bool movePtnOne;
		bool movePtnTwo;
		//���[�u�p�^�[��1
		float refThetaOne;
		sf::Vector2f centerPosOne;
		sf::Vector2f centerMoveSpeedOne;
		float thetaSpeedOne; //�p���x
		float targetPosXOne;
		float targetPosYOne;
		float xRadiusOne; //�ȉ~�̒������a
		float yRadiusOne; //�ȉ~�̒Z�����a
		//���[�u�p�^�[��2
		float refThetaTwo;
		sf::Vector2f centerPosTwo;
		sf::Vector2f centerMoveSpeedTwo;
		float thetaSpeedTwo; //�p���x
		float targetPosXTwo;
		float targetPosYTwo;
		float xRadiusTwo; //�ȉ~�̒������a
		float yRadiusTwo; //�ȉ~�̒Z�����a
		//���[�u�p�^�[��3
		float refThetaThree;
		sf::Vector2f centerPosThree;
		sf::Vector2f centerMoveSpeedThree;
		float thetaSpeedThree; //�p���x
		float targetPosXThree;
		float targetPosYThree;
		float xRadiusThree; //�ȉ~�̒������a
		float yRadiusThree; //�ȉ~�̒Z�����a
		//�G�̐�
		int totalNum;
		int curNum;
		//�����蔻��
		float bcRadius;
		int initHp;
		sf::Color collisionColor;
		sf::Color normalColor;
		float triggerInterval;//�ˌ��Ԋu

		//�_���[�W��
		sf::SoundBuffer soundBufferDamage;
		sf::Sound soundDamage;
		sf::SoundBuffer soundBufferDead;
		sf::Sound soundDead;

	};
private:
	//���ʃf�[�^
	DATA Enemy;

	//�P�̃f�[�^�z��
	struct ENEMY
	{
		sf::Sprite sprite;
		sf::Vector2f pos;
		float ofstTheta;
		float triggerErapsedTime;
		float invincibleRestTime;
		int hp;
	};

	ENEMY* Enemies;
public:
	ENEMIES(class GAME* game);
	~ENEMIES();
	void create();
	void init();
	void update();

	//����
	void moveOne();
	void moveTwo();
	void moveThree();

	void launch();
	void collision();
	void collisionIzunaBullet();
	void collisionExplosion();
	void draw();

	int curNum() { return Enemy.curNum; }
};

