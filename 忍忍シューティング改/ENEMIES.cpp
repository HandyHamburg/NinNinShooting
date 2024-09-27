#include "ENEMIES.h"
#include"GAME.h"
#include"STAGE.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"IZUNA_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"EXPLOSIONS.h"
#include<stdlib.h>
#include<cmath>
#include<iostream>

ENEMIES::ENEMIES(GAME* game) : GAME_OBJECT(game)
{
	 
}

ENEMIES::~ENEMIES()
{
	delete[] Enemies;
}
void ENEMIES::create()
{
	Enemy = game()->container()->enemy();
	Enemies = new ENEMY[Enemy.totalNum];


	//�e�N�X�`���f�[�^���Z�b�g
	for (int i = 0; i < Enemy.totalNum; i++)	
	{
		Enemies[i].sprite.setTexture(Enemy.texture);
		Enemies[i].sprite.setScale(Enemy.scale);
		Enemies[i].sprite.setOrigin(Enemy.originPos);
	}
}

void ENEMIES::init()
{
	//���S�ʒu�ύX
	Enemy.centerPosOne = game()->container()->enemy().centerPosOne;
	Enemy.centerPosTwo = game()->container()->enemy().centerPosTwo;
	Enemy.centerPosThree = game()->container()->enemy().centerPosThree;
	//����߂�
	Enemy.curNum = Enemy.totalNum;
	//�̗͂Ƒ��Έʒu��߂�
	float divInterval = Enemy.triggerInterval / Enemy.totalNum;
	float divTheta = 3.1415926f * 2 / Enemy.totalNum;
	for (int i = 0; i < Enemy.totalNum; i++)
	{
		Enemies[i].triggerErapsedTime = divInterval * i;
		Enemies[i].ofstTheta = divTheta * i;
		Enemies[i].hp = Enemy.initHp;
	}

}


void ENEMIES::update()
{
	switch (game()->stage()->no())
	{
	case 1:
		moveOne();
		break;
	case 2:
		moveTwo();
		break;
	case 3:
		moveThree();
		break;
	}

	launch();
	collision();
	//collisionIzunaBullet();
	//collisionExplosion();
}


void ENEMIES::moveOne()
{
	float delta = game()->timer();

	//�~��Ă��鏈��
	if (Enemy.centerPosOne.y < Enemy.targetPosYOne)
	{
		Enemy.centerPosOne.y += Enemy.centerMoveSpeedOne.y * delta;
	}

	//���E�ɓ�������
	if (Enemy.centerPosOne.y >= Enemy.targetPosYOne)
	{
		if (Enemy.centerPosOne.x <= game()->window()->getSize().x - Enemy.targetPosXOne || Enemy.centerPosOne.x >= Enemy.targetPosXOne)
		{
			Enemy.centerPosOne.x += Enemy.centerMoveSpeedOne.x * delta;
			if (Enemy.centerPosOne.x > game()->window()->getSize().x - Enemy.targetPosXOne || Enemy.centerPosOne.x < Enemy.targetPosXOne)
			{
				Enemy.centerMoveSpeedOne.x = -Enemy.centerMoveSpeedOne.x;
			}
		}
	}

	//�ȉ~�ɉ����ĕ��ԏ���
	for (int i = 0; i < Enemy.curNum; i++)
	{
		float theta = Enemy.refThetaOne + Enemies[i].ofstTheta;
		float px = Enemy.centerPosOne.x + cos(theta) * Enemy.xRadiusOne;
		float py = Enemy.centerPosOne.y + sin(theta) * Enemy.yRadiusOne;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}

	//��]����
	Enemy.refThetaOne += Enemy.thetaSpeedOne * delta;
}


void ENEMIES::moveTwo()
{
	float delta = game()->timer();

	//�~��Ă��鏈��
	if (Enemy.centerPosTwo.y < Enemy.targetPosYTwo)
	{
		Enemy.centerPosTwo.y += Enemy.centerMoveSpeedTwo.y * delta;
	}

	//�ŏ��̗N���ʒu�����ƌ��߂�@ofstTheta���������ŐF�X�ς��̂Œ���


	//�ȉ~�ɉ����ĕ��ԏ���
	for (int i = 0; i < Enemy.curNum; i++)
	{
		float theta = Enemy.refThetaTwo + Enemies[i].ofstTheta;
		float px = Enemy.centerPosTwo.x + cos(theta) * Enemy.xRadiusTwo;
		float py = Enemy.centerPosTwo.y + sin(theta) * Enemy.yRadiusTwo;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}


	//��]����
	Enemy.refThetaTwo += Enemy.thetaSpeedTwo * delta;

}

void ENEMIES::moveThree()
{
	float delta = game()->timer();

	//�~��Ă��鏈��
	if (Enemy.centerPosThree.y < Enemy.targetPosYThree)
	{
		Enemy.centerPosThree.y += Enemy.centerMoveSpeedThree.y * delta;
	}

	if (Enemy.centerPosThree.y >= Enemy.targetPosYThree)
	{
		if (Enemy.centerPosThree.x <= game()->window()->getSize().x - Enemy.targetPosXThree || Enemy.centerPosThree.x >= Enemy.targetPosXThree)
		{
			Enemy.centerPosThree.x += Enemy.centerMoveSpeedThree.x * delta;
			if (Enemy.centerPosThree.x > game()->window()->getSize().x - Enemy.targetPosXThree || Enemy.centerPosThree.x < Enemy.targetPosXThree)
			{
				Enemy.centerMoveSpeedThree.x = -Enemy.centerMoveSpeedThree.x;
			}
		}
	}

	for (int i = 0; i < Enemy.curNum; i++)
	{
		float theta = Enemy.refThetaThree;
		float px = Enemy.centerPosThree.x + cos(theta) * Enemy.xRadiusThree * i / Enemy.totalNum;
		float py = Enemy.centerPosThree.y + sin(theta) * Enemy.yRadiusThree * i / Enemy.totalNum;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}

	Enemy.refThetaThree += Enemy.thetaSpeedThree * delta;
}

//�e���ˏ���
void ENEMIES::launch()
{
	float delta = game()->timer();

	sf::Vector2f playerPos = game()->player()->pos();

	for (int i = 0; i < Enemy.curNum; i++)
	{
		Enemies[i].triggerErapsedTime += delta;
		if (Enemies[i].triggerErapsedTime >= Enemy.triggerInterval)
		{
			sf::Vector2f pos = Enemies[i].pos;
			//���˃x�N�g���v�Z
			float VecX = playerPos.x - pos.x;  //�x�N�g���̈����Z�@A-B B����A�ւ̃x�N�g��
			float VecY = playerPos.y - pos.y;
			float Vec = sqrtf(VecX * VecX + VecY * VecY);
			//���˃x�N�g�����K��
			float normVecX = VecX / Vec;
			float normVecY = VecY / Vec;

			sf::Vector2f launchVec(normVecX, normVecY);
			pos.x = pos.x + launchVec.x * Enemy.ofstLaunchDist.x ;
			pos.y = pos.y + launchVec.y * Enemy.ofstLaunchDist.y ;
			
			game()->enemyBullets()->launch(pos, launchVec,
										   game()->container()->enemyBullet().texture);
			Enemies[i].triggerErapsedTime = 0;
		}
	}
}


void ENEMIES::collision()
{
	float delta = game()->timer();
	BULLETS* bullets = game()->playerBullets();

	float distance = Enemy.bcRadius + bullets->bcRadius();
	float sqDistance = distance * distance; //���̓�悷�邩�́A����Vec = VecX * VecX + VecY * VecY;�@�Ł@��g���ĂȂ����炾���B�����B

	for (int j = Enemy.curNum - 1; j >= 0; j--)
	{
		
			Enemies[j].sprite.setColor(Enemy.normalColor);

			//�ʏ�e�̓����蔻��
			for (int i = bullets->curNum() - 1; i >= 0; i--)
			{
				sf::Vector2f vec = Enemies[j].pos - bullets->pos(i);

				//���@����G�̒e�ւ̃x�N�g���̑傫��
				float VecX = Enemies[j].pos.x - bullets->pos(i).x;
				float VecY = Enemies[j].pos.y - bullets->pos(i).y;
				float Vec = VecX * VecX + VecY * VecY;

				//�����蔻����e�������Ȃ�
				if (Vec < sqDistance)
				{
					Enemy.soundDamage.play();
					Enemies[j].hp--;
					Enemies[j].sprite.setColor(Enemy.collisionColor);
					std::cout << Enemies[j].hp << "\n";
					if (Enemies[j].hp <= 0)
					{
						Enemy.curNum--;
						Enemy.soundDead.play();
						Enemies[j] = Enemies[Enemy.curNum];
					}
					bullets->kill(i);
					i = 0;
				}

			}

			//���e�̓����蔻��
			BULLETS* bullets = game()->izunaBullets();

			float distanceIzuna = Enemy.bcRadius + bullets->bcRadius();
			float sqDistanceIzuna = distanceIzuna * distanceIzuna;

			for (int i = bullets->curNum() - 1; i >= 0; i--)
			{
				sf::Vector2f vec = Enemies[j].pos - bullets->pos(i);

				//���@����G�̒e�ւ̃x�N�g���̑傫��
				float VecX = Enemies[j].pos.x - bullets->pos(i).x;
				float VecY = Enemies[j].pos.y - bullets->pos(i).y;
				float Vec = VecX * VecX + VecY * VecY;

				//�����蔻����e�������Ȃ�
				if (Vec < sqDistanceIzuna)
				{
					Enemy.soundDamage.play();
					game()->explosions()->launch(bullets[i].pos(i));
					Enemies[j].sprite.setColor(Enemy.collisionColor);
					std::cout << Enemies[j].hp << "\n";
					if (Enemies[j].hp <= 0)
					{
						Enemy.curNum--;
						Enemy.soundDead.play();
						Enemies[j] = Enemies[Enemy.curNum];
					}
					bullets->kill(i);
					i = 0;
				}

			}

			//�����̓����蔻��
			EXPLOSIONS* explosions = game()->explosions();

			float distanceExplosion = Enemy.bcRadius + explosions->bcRadius();
			float sqDistanceExplosion = distanceExplosion * distanceExplosion; //���̓�悷�邩�́A����Vec = VecX * VecX + VecY * VecY;�@�Ł@��g���ĂȂ����炾���B�����B

			for (int i = explosions->curNum() - 1; i >= 0; i--)
			{
				sf::Vector2f vec = Enemies[j].pos - explosions->pos(i);

				//���@����G�̒e�ւ̃x�N�g���̑傫��
				float VecX = Enemies[j].pos.x - explosions->pos(i).x;
				float VecY = Enemies[j].pos.y - explosions->pos(i).y;
				float Vec = VecX * VecX + VecY * VecY;

				//�����蔻����e�������Ȃ�
				if (Vec < sqDistanceExplosion)
				{
					Enemy.soundDamage.play();
					Enemies[j].hp--;
					Enemies[j].sprite.setColor(Enemy.collisionColor);
					std::cout << Enemies[j].hp << "\n";
					if (Enemies[j].hp <= 0)
					{
						Enemy.curNum--;
						Enemy.soundDead.play();
						Enemies[j] = Enemies[Enemy.curNum];
					}
					i = 0;
				}

			}
	}
}

void ENEMIES::collisionIzunaBullet()
{
	float delta = game()->timer();
	

	for (int j = Enemy.curNum - 1; j >= 0; j--)
	{

		//Enemies[j].sprite.setColor(Enemy.normalColor);

	
	}
}

void ENEMIES::collisionExplosion()
{
	float delta = game()->timer();
	

	for (int j = Enemy.curNum - 1; j >= 0; j--)
	{

		//Enemies[j].sprite.setColor(Enemy.normalColor);

	}
}



void ENEMIES::draw()
{
	for (int i = 0; i < Enemy.curNum; i++)
	{
		Enemies[i].sprite.setPosition(Enemies[i].pos);
		game()->window()->draw(Enemies[i].sprite);
	}
}
