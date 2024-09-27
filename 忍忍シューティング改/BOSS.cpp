#include "BOSS.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER_BULLETS.h"
#include"IZUNA_BULLETS.h"
#include"EXPLOSIONS.h"
#include<iostream>

BOSS::BOSS(GAME* game):GAME_OBJECT(game)
{
}

void BOSS::create()
{
	Boss = game()->container()->boss();
}

void BOSS::init()
{
	Boss.sprite.setTexture(Boss.texture);
	Boss.sprite.setScale(Boss.scale);
	Boss.sprite.setOrigin(Boss.originPos);
	Boss.curPhase = game()->container()->boss().curPhase;
	Boss.hp = game()->container()->boss().hp;
}

void BOSS::update()
{
	collision();
	phaseShift();

	if (Boss.hp > Boss.phaseOneThreshHold)
	{
		moveOne();
		launchOne();
	}
	else if (Boss.phaseOneThreshHold >= Boss.hp && Boss.hp > Boss.phaseTwoThreshHold)
	{
		if (Boss.phaseTwoEnter)
		{
			Boss.curPhase++;
			Boss.phaseTwoEnter = 0;
		}
		moveTwo();
		launchTwo();
	}
	else if (Boss.phaseTwoThreshHold >= Boss.hp)
	{
		if (Boss.phaseThreeEnter)
		{
			Boss.curPhase++;
			Boss.phaseThreeEnter = 0;
		}
		moveThree();
		launchThree();
	}
	
}

void BOSS::moveOne()
{
	float delta = game()->timer();

	if (Boss.pos.y <= Boss.targetPosY)
	{
		Boss.pos.y += Boss.vecOne.y * delta;
	}
	
	if (Boss.pos.y > Boss.targetPosY)
	{
		if (Boss.pos.x <= game()->window()->getSize().x - Boss.targetPosX || Boss.pos.x >= Boss.targetPosX)
		{
			Boss.pos.x += Boss.vecOne.x * delta;
			if (Boss.pos.x > game()->window()->getSize().x - Boss.targetPosX || Boss.pos.x < Boss.targetPosX)
			{
				Boss.vecOne.x = -Boss.vecOne.x;
			}
		}
	}
}

void BOSS::launchOne()
{
	float delta = game()->timer();
	sf::Vector2f pos;
	sf::Vector2f launchVec;

	Boss.triggerErapsedTime += delta;
	if (Boss.triggerErapsedTime >= Boss.triggerIntervalOne)
	{
		pos.x = Boss.pos.x + cosf(Boss.launchVecTheta) * Boss.ofstLaunchDist.x;
		pos.y = Boss.pos.y + sinf(Boss.launchVecTheta) * Boss.ofstLaunchDist.y;
		launchVec = { cosf(Boss.launchVecTheta), sinf(Boss.launchVecTheta) };

		game()->enemyBullets()->launch(pos, launchVec,
			game()->container()->enemyBullet().texture);
		Boss.triggerErapsedTime = 0;
	}
}

void BOSS::moveTwo()
{
	float delta = game()->timer();

	if (Boss.pos.x <= game()->window()->getSize().x - Boss.targetPosX || Boss.pos.x >= Boss.targetPosX)
	{
		Boss.pos.x += Boss.vecTwo.x * delta;
		if (Boss.pos.x > game()->window()->getSize().x - Boss.targetPosX || Boss.pos.x < Boss.targetPosX)
		{
			Boss.vecTwo.x = -Boss.vecTwo.x;
		}
	}
}

void BOSS::launchTwo()
{
	float delta = game()->timer();
	sf::Vector2f pos;
	sf::Vector2f launchVec;
	sf::Vector2f ofstPosRight; //3way�p�̉E
	sf::Vector2f ofstVecRight;
	sf::Vector2f ofstPosLeft; //3way�p�̍�
	sf::Vector2f ofstVecLeft;

	Boss.triggerErapsedTime += delta;
	if (Boss.triggerErapsedTime >= Boss.triggerIntervalTwo)
	{
		pos.x = Boss.pos.x + cosf(Boss.launchVecTheta) * Boss.ofstLaunchDist.x;
		pos.y = Boss.pos.y + sinf(Boss.launchVecTheta) * Boss.ofstLaunchDist.y;
		launchVec = { cosf(Boss.launchVecTheta), sinf(Boss.launchVecTheta) };

		ofstPosRight.x = Boss.pos.x + cosf(Boss.launchVecTheta + Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.x;
		ofstPosRight.y = Boss.pos.y + sinf(Boss.launchVecTheta + Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.y;
		ofstVecRight = { cosf(Boss.launchVecTheta + Boss.ofstLaunchVecTheta),  sinf(Boss.launchVecTheta + Boss.ofstLaunchVecTheta) };

		ofstPosLeft.x = Boss.pos.x + cosf(Boss.launchVecTheta - Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.x;
		ofstPosLeft.y = Boss.pos.y + sinf(Boss.launchVecTheta - Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.y;
		ofstVecLeft = { cosf(Boss.launchVecTheta - Boss.ofstLaunchVecTheta),  sinf(Boss.launchVecTheta - Boss.ofstLaunchVecTheta) };

		game()->enemyBullets()->launch(pos, launchVec,
			game()->container()->enemyBullet().texture);

		game()->enemyBullets()->launch(ofstPosRight, ofstVecRight,
			game()->container()->enemyBullet().texture);

		game()->enemyBullets()->launch(ofstPosLeft, ofstVecLeft,
			game()->container()->enemyBullet().texture);

		Boss.triggerErapsedTime = 0;
	}
}

void BOSS::moveThree()
{
	float delta = game()->timer();

	//���̓���
	if (Boss.pos.x <= game()->window()->getSize().x - Boss.targetPosX || Boss.pos.x >= Boss.targetPosX)
	{
		Boss.pos.x += Boss.vecThree.x * delta;
		if (Boss.pos.x > game()->window()->getSize().x - Boss.targetPosX || Boss.pos.x < Boss.targetPosX)
		{
			Boss.vecThree.x = -Boss.vecThree.x;
		}
	}

	//�炪�v���C���[��ǐՂ���
	float width = game()->window()->getSize().x; //600
	float height = game()->window()->getSize().y; //800
	sf::Vector2f pos = Boss.pos;
	sf::Vector2f playerPos = game()->player()->pos();

	float VecX = playerPos.x - pos.x;
	float VecY = playerPos.y - pos.y;
	float Vec = sqrtf(VecX * VecX + VecY * VecY);
	float normVecX = VecX / Vec;
	float normVecY = VecY / Vec;
	float ofstTheta = acos(Vec / VecY);
	float rotationTheta = acos(normVecY);

	if (Boss.pos.x < playerPos.x)
	{
		Boss.angle =  - rotationTheta * 180 / 3.14159265;
	}
	else if (Boss.pos.x >= playerPos.x)
	{
		Boss.angle = rotationTheta * 180 / 3.14159265;
	}
}

void BOSS::launchThree()
{
	float delta = game()->timer();

		Boss.triggerErapsedTime += delta;
		Boss.triggerBurstErapsedTime += delta;

		if (Boss.triggerErapsedTime >= Boss.triggerIntervalThree)
		{
			sf::Vector2f pos = Boss.pos;
			sf::Vector2f playerPos = game()->player()->pos();
			//���˃x�N�g���v�Z
			float VecX = playerPos.x - pos.x;  //�x�N�g���̈����Z�@A-B B����A�ւ̃x�N�g��
			float VecY = playerPos.y - pos.y;
			float Vec = sqrtf(VecX * VecX + VecY * VecY);
			//���˃x�N�g�����K��
			float normVecX = VecX / Vec;
			float normVecY = VecY / Vec;

			sf::Vector2f ofstPosRight; //3way�p�̉E
			sf::Vector2f ofstVecRight;
			sf::Vector2f ofstPosLeft; //3way�p�̍�
			sf::Vector2f ofstVecLeft;

			sf::Vector2f launchVec(normVecX, normVecY);
			float launchVecTheta = acos(normVecY) + 3.14159265 * 0.5;
			pos.x = pos.x + launchVec.x * Boss.ofstLaunchDist.x;
			pos.y = pos.y + launchVec.y * Boss.ofstLaunchDist.y;

			if (Boss.pos.x < playerPos.x)
			{
				launchVecTheta = 3.14159265 - launchVecTheta;

				ofstPosRight.x = pos.x + cosf(launchVecTheta + Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.x;
				ofstPosRight.y = pos.y + sinf(launchVecTheta + Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.y;
				ofstVecRight = { cosf(launchVecTheta + Boss.ofstLaunchVecTheta),  sinf(launchVecTheta + Boss.ofstLaunchVecTheta) };

				ofstPosLeft.x = pos.x + cosf(launchVecTheta - Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.x;
				ofstPosLeft.y = pos.y + sinf(launchVecTheta - Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.y;
				ofstVecLeft = { cosf(launchVecTheta - Boss.ofstLaunchVecTheta),  sinf(launchVecTheta - Boss.ofstLaunchVecTheta) };
			}
			else if (Boss.pos.x >= playerPos.x)
			{
				ofstPosRight.x = pos.x + sinf(launchVecTheta + Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.x;
				ofstPosRight.y = pos.y + cosf(launchVecTheta + Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.y;
				ofstVecRight = { cosf(launchVecTheta + Boss.ofstLaunchVecTheta),  sinf(launchVecTheta + Boss.ofstLaunchVecTheta) };

				ofstPosLeft.x = pos.x + sinf(launchVecTheta - Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.x;
				ofstPosLeft.y = pos.y + cosf(launchVecTheta - Boss.ofstLaunchVecTheta) * Boss.ofstLaunchDist.y;
				ofstVecLeft = { cosf(launchVecTheta - Boss.ofstLaunchVecTheta),  sinf(launchVecTheta - Boss.ofstLaunchVecTheta) };
			}

			if (Boss.shootCnt <= 2)
			{
				game()->enemyBullets()->launch(pos, launchVec,
					game()->container()->enemyBullet().texture);

				game()->enemyBullets()->launch(pos, ofstVecRight,
					game()->container()->enemyBullet().texture);

				game()->enemyBullets()->launch(pos, ofstVecLeft,
					game()->container()->enemyBullet().texture);

				Boss.shootCnt++;
			}
			else
			{
				if (Boss.triggerBurstErapsedTime >= Boss.triggerBurstInterval)
				{
					Boss.shootCnt = 0;
					Boss.triggerBurstErapsedTime = 0;
				}
			}

			Boss.triggerErapsedTime = 0;
		}
}


void BOSS::phaseShift()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		//KeyHold��False�Ȃ珈��
		if (game()->keyHoldGetter() == false)
		{
			if (Boss.curPhase < Boss.nPhase - 1)
			{
				Boss.curPhase++;
			}
			game()->keyHoldSetter(true);//KeyHold��true�ɂȂ�
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		//KeyHold��False�Ȃ珈��
		if (game()->keyHoldGetter() == false)
		{
			if (Boss.curPhase > 0)
			{
				Boss.curPhase--;
			}
			game()->keyHoldSetter(true);//KeyHold��true�ɂȂ�
		}
	}
	else
	{
		//Z��������ĂȂ����KeyHold��false�ɖ߂�
		game()->keyHoldSetter(false);
	}
}

void BOSS::collision()
{
	float delta = game()->timer();
	BULLETS* bullets = game()->playerBullets();

	float distance = Boss.bcRadius + bullets->bcRadius();
	float sqDistance = distance * distance; //���̓�悷�邩�́A����Vec = VecX * VecX + VecY * VecY;�@�Ł@��g���ĂȂ����炾���B�����B

	
		Boss.sprite.setColor(Boss.normalColor);

		//�ʏ�e�̓����蔻��
		for (int i = bullets->curNum() - 1; i >= 0; i--)
		{
			sf::Vector2f vec = Boss.pos - bullets->pos(i);

			//���@����G�̒e�ւ̃x�N�g���̑傫��
			float VecX = Boss.pos.x - bullets->pos(i).x;
			float VecY = Boss.pos.y - bullets->pos(i).y;
			float Vec = VecX * VecX + VecY * VecY;

			//�����蔻����e�������Ȃ�
			if (Vec < sqDistance)
			{
				//TODO Boss.soundDamage.play(); 
				Boss.hp--;
				Boss.sprite.setColor(Boss.collisionColor);
				std::cout << Boss.hp << "\n";
				if (Boss.hp <= 0)
				{
					//TODO ���S���̏���
				}
				bullets->kill(i);
				i = 0;
			}
		}

		//���e�̓����蔻��
		BULLETS* izunaBullets = game()->izunaBullets();

		float distanceIzuna = Boss.bcRadius + izunaBullets->bcRadius();
		float sqDistanceIzuna = distanceIzuna * distanceIzuna;

		for (int i = izunaBullets->curNum() - 1; i >= 0; i--)
		{
			sf::Vector2f vec = Boss.pos - izunaBullets->pos(i);

			//���@����G�̒e�ւ̃x�N�g���̑傫��
			float VecX = Boss.pos.x - izunaBullets->pos(i).x;
			float VecY = Boss.pos.y - izunaBullets->pos(i).y;
			float Vec = VecX * VecX + VecY * VecY;

			//�����蔻����e�������Ȃ�
			if (Vec < sqDistanceIzuna)
			{
				//TODO Boss.soundDamage.play();
				game()->explosions()->launch(izunaBullets[i].pos(i));
				Boss.sprite.setColor(Boss.collisionColor);
				std::cout << Boss.hp << "\n";
				if (Boss.hp <= 0)
				{
					//TODO ���S���̏���
				}
				izunaBullets->kill(i);
				i = 0;
			}
		}

		//�����̓����蔻��
		EXPLOSIONS* explosions = game()->explosions();

		float distanceExplosion = Boss.bcRadius + explosions->bcRadius();
		float sqDistanceExplosion = distanceExplosion * distanceExplosion; //���̓�悷�邩�́A����Vec = VecX * VecX + VecY * VecY;�@�Ł@��g���ĂȂ����炾���B�����B

		for (int i = explosions->curNum() - 1; i >= 0; i--)
		{
			sf::Vector2f vec = Boss.pos - explosions->pos(i);

			//���@����G�̒e�ւ̃x�N�g���̑傫��
			float VecX = Boss.pos.x - explosions->pos(i).x;
			float VecY = Boss.pos.y - explosions->pos(i).y;
			float Vec = VecX * VecX + VecY * VecY;

			//�����蔻����e�������Ȃ�
			if (Vec < sqDistanceExplosion)
			{
				//TODO Boss.soundDamage.play();
				Boss.hp--;
				Boss.sprite.setColor(Boss.collisionColor);
				std::cout << Boss.hp << "\n";
				if (Boss.hp <= 0)
				{
					
				}
				i = 0;
			}

		}
}

void BOSS::draw()
{
	float delta = game()->timer();
	Boss.animationTimer += Boss.animationSpeed * delta;

	if (Boss.animationTimer >= Boss.flameRow)
	{
		Boss.animationTimer = 0;
	}

	Boss.sprite.setPosition(Boss.pos);
	Boss.sprite.setRotation(Boss.angle);
	Boss.sprite.setTextureRect(Boss.frame[static_cast<int>(Boss.curPhase*Boss.flameRow + Boss.animationTimer)]);
	
	game()->window()->draw(Boss.sprite);
}




