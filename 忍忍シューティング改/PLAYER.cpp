#include "PLAYER.h"
#include"GAME.h"
#include"TRANSITION.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"IZUNA_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"POWER_ITEMS.h"
#include"IZUNA_ITEMS.h"
#include<SFML/Audio.hpp>
#include<iostream>

PLAYER::PLAYER(GAME* game) : GAME_OBJECT(game)
{
}

PLAYER::~PLAYER()
{
}

void PLAYER::create()
{
	Player = game()->container()->player();
}

void PLAYER::init()
{
	Player.sprite.setTexture(Player.texture);
	Player.sprite.setScale(Player.scale);
	Player.sprite.setOrigin(Player.originPos);

	//リプレイ時の初期化
	Player.hp = game()->container()->player().hp;
	Player.powerUpState = game()->container()->player().powerUpState;
	Player.powerUpStateIzuna = game()->container()->player().powerUpStateIzuna;
	Player.pos = game()->container()->player().pos;
}

void PLAYER::update()
{
	if (Player.hp != 0 && game()->curSceneId() == GAME::STAGE_ID)
	{
		move();
		shoot();
		collision();
		collisionItemPower();
		collisionItemIzuna();
	}
}

void PLAYER::move()
{
	float delta = game()->timer();

	//WASD移動　中身に斜め移動
	if (Player.pos.y > Player.limmitH && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Player.pos.y += -Player.vec.y * delta;

		//WA移動
		if (Player.pos.x > Player.limmitW && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Player.pos.x += -Player.vec.x * delta;
		}

		//WD移動
		if (Player.pos.x < game()->window()->getSize().x - Player.limmitW &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Player.pos.x += Player.vec.x * delta;
		}
	}
	else if (Player.pos.x > Player.limmitW && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Player.pos.x += -Player.vec.x * delta;

		//AW移動
		if (Player.pos.y > Player.limmitH && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Player.pos.y += -Player.vec.y * delta;
		}

		//AS移動
		if (Player.pos.y < game()->window()->getSize().y - Player.limmitW &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player.pos.y += Player.vec.y * delta;
		}
	}
	else if (Player.pos.y < game()->window()->getSize().y - Player.limmitW &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Player.pos.y += Player.vec.y * delta;

		//SA移動
		if (Player.pos.x > Player.limmitW && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Player.pos.x += -Player.vec.x * delta;
		}
		
		//SD移動
		if (Player.pos.x < game()->window()->getSize().x - Player.limmitW &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Player.pos.x += Player.vec.x * delta;
		}
	}
	else if (Player.pos.x < game()->window()->getSize().x - Player.limmitW &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Player.pos.x += Player.vec.x * delta;

		//DW移動
		if (Player.pos.y > Player.limmitH && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Player.pos.y += -Player.vec.y * delta;
		}
		
		//DS移動
		if (Player.pos.y < game()->window()->getSize().y - Player.limmitW &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player.pos.y += Player.vec.y * delta;
		}
	}
}

void PLAYER::shoot()
{
	float delta = game()->timer();

	Player.triggerErapsedTime += delta;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (Player.triggerErapsedTime >= Player.triggerInterval)
		{
			launch();

			if (Player.powerUpState)
			{
				launchThreeWays();
			}

			if (Player.powerUpStateIzuna)
			{
				if (Player.shootCnt % 6 == 0)
					launchIzuna();
			}


			Player.triggerErapsedTime = 0;
			Player.shootCnt++;
			Player.sound.play();
		}
	}
	/*
	else {
		//連打で連射出来る
		//Player.triggerErapsedTime = Player.triggerInterval;
	}
	*/
}

void PLAYER::launch()
{
	sf::Vector2f pos;
	sf::Vector2f launchVec;

	pos.x = Player.pos.x + cosf(Player.launchVecTheta) * Player.ofstLaunchDist.x;
	pos.y = Player.pos.y + sinf(Player.launchVecTheta) * Player.ofstLaunchDist.y;
	launchVec = { cosf(Player.launchVecTheta), sinf(Player.launchVecTheta) };

	game()->playerBullets()->launch(pos, launchVec,
			game()->container()->playerBullet().texture);
}

void PLAYER::launchThreeWays()
{
	sf::Vector2f pos;
	sf::Vector2f launchVec;
	sf::Vector2f ofstPosRight; //3way用の右
	sf::Vector2f ofstVecRight;
	sf::Vector2f ofstPosLeft; //3way用の左
	sf::Vector2f ofstVecLeft; 

	pos.x = Player.pos.x + cosf(Player.launchVecTheta) * Player.ofstLaunchDist.x;
	pos.y = Player.pos.y + sinf(Player.launchVecTheta) * Player.ofstLaunchDist.y;
	launchVec = { cosf(Player.launchVecTheta), sinf(Player.launchVecTheta) };

	ofstPosRight.x = Player.pos.x + cosf(Player.launchVecTheta + Player.ofstLaunchVecTheta) * Player.ofstLaunchDist.x;
	ofstPosRight.y = Player.pos.y + sinf(Player.launchVecTheta + Player.ofstLaunchVecTheta) * Player.ofstLaunchDist.y;
	ofstVecRight = { cosf(Player.launchVecTheta + Player.ofstLaunchVecTheta),  sinf(Player.launchVecTheta + Player.ofstLaunchVecTheta) };

	ofstPosLeft.x = Player.pos.x + cosf(Player.launchVecTheta - Player.ofstLaunchVecTheta) * Player.ofstLaunchDist.x;
	ofstPosLeft.y = Player.pos.y + sinf(Player.launchVecTheta - Player.ofstLaunchVecTheta) * Player.ofstLaunchDist.y;
	ofstVecLeft = { cosf(Player.launchVecTheta - Player.ofstLaunchVecTheta),  sinf(Player.launchVecTheta - Player.ofstLaunchVecTheta) };

	//右の射撃
	game()->playerBullets()->launch(ofstPosRight, ofstVecRight,
		game()->container()->playerBullet().texture);

	//真ん中の射撃
	/*
	game()->playerBullets()->launch(pos, launchVec,
		game()->container()->playerBullet().texture,
		game()->container()->playerBullet().scale,
		game()->container()->playerBullet().originPos);
	*/

	//左の射撃
	game()->playerBullets()->launch(ofstPosLeft, ofstVecLeft,
		game()->container()->playerBullet().texture);
}

void PLAYER::launchIzuna()
{
	sf::Vector2f pos;
	sf::Vector2f launchVec;

	pos.x = Player.pos.x + cosf(Player.launchVecTheta) * Player.ofstLaunchDist.x;
	pos.y = Player.pos.y + sinf(Player.launchVecTheta) * Player.ofstLaunchDist.y;
	launchVec = { cosf(Player.launchVecTheta), sinf(Player.launchVecTheta) };

	game()->izunaBullets()->launch(pos, launchVec,
		game()->container()->izunaBullet().texture);

	Player.sound.play();
}

//collision
void PLAYER::collision()
{
	float delta = game()->timer();
	ENEMY_BULLETS* bullets = game()->enemyBullets();

	float distance = Player.bcRadius + bullets->bcRadius();
	float sqDistance = distance * distance;

	if (Player.invincibleRestTime > 0)
	{
		Player.invincibleRestTime -= delta;
	}
	else
	{
		for (int i = bullets->curNum() - 1; i >= 0; i--)
		{
			sf::Vector2f vec = Player.pos - bullets->pos(i);

			//自機から敵の弾へのベクトルの大きさ
			float VecX = Player.pos.x - bullets->pos(i).x;
			float VecY = Player.pos.y - bullets->pos(i).y;
			float Vec = VecX * VecX + VecY * VecY;

			//残り無敵時間が0以下かつ当たり判定より弾が内側なら
			if (Player.invincibleRestTime <= 0 &&
				Vec < sqDistance)
			{
				Player.hp--;
				if (Player.hp <= 0)
				{
					Player.soundDead.play();
				}
				Player.invincibleRestTime = Player.invincibleTime;
				bullets->kill(i);
			}
		}
	}
}

//アイテムとのcollision
void PLAYER::collisionItemPower()
{
	float delta = game()->timer();
	POWER_ITEMS* powItems = game()->powerItems();

	float distance = Player.bcRadius + powItems->bcRadius();
	float sqDistance = distance * distance;

		for (int i = powItems->curNum() - 1; i >= 0; i--)
		{
			sf::Vector2f vec = Player.pos - powItems->pos(i);

			//自機から敵の弾へのベクトルの大きさ
			float VecX = Player.pos.x - powItems->pos(i).x;
			float VecY = Player.pos.y - powItems->pos(i).y;
			float Vec = VecX * VecX + VecY * VecY;

			//当たり判定より弾が内側なら
			if (Vec < sqDistance)
			{
				Player.powerUpState++;
				Player.soundPowerUp.play();
				powItems->kill(i);
			}
		}
}

void PLAYER::collisionItemIzuna()
{
	float delta = game()->timer();
	IZUNA_ITEMS* izunaItems = game()->izunaItems();

	float distance = Player.bcRadius + izunaItems->bcRadius();
	float sqDistance = distance * distance;

	for (int i = izunaItems->curNum() - 1; i >= 0; i--)
	{
		sf::Vector2f vec = Player.pos - izunaItems->pos(i);

		//自機から敵の弾へのベクトルの大きさ
		float VecX = Player.pos.x - izunaItems->pos(i).x;
		float VecY = Player.pos.y - izunaItems->pos(i).y;
		float Vec = VecX * VecX + VecY * VecY;

		//当たり判定より弾が内側なら
		if (Vec < sqDistance)
		{
			Player.powerUpStateIzuna++;
			Player.soundIzuna.play();
			//game()->container()->izunaItem().sound.play(); TODO CONATINERに音セット
			izunaItems->kill(i);
		}
	}
}

void PLAYER::draw()
{
	float delta = game()->timer();
	Player.animationTimer += delta*3; //animationの速度が3倍。 Player.animationSpeed * delta にすればいいと思う。元気があれば変える。

	if (Player.animationTimer >= Player.nflame)
	{
		Player.animationTimer = 0;
	}

	Player.sprite.setPosition(Player.pos);
	Player.sprite.setRotation(Player.angle);
	
	Player.sprite.setTextureRect(Player.frame[static_cast<int>(Player.animationTimer)]);

	game()->window()->draw(Player.sprite);
}
