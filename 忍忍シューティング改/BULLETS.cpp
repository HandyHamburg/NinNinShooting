#include "BULLETS.h"
#include"GAME.h"
#include"CONTAINER.h"
#include<iostream>

BULLETS::BULLETS(GAME* game) : GAME_OBJECT(game)
{
}

BULLETS::~BULLETS()
{
	delete[] Bullets;
}

void BULLETS::SetBullets(const BULLETS::DATA& data)
{
	Bullet = data;
	Bullets = new BULLET[Bullet.totalNum];
}

void BULLETS::init()
{
	Bullet.curNum = 0;
}

//íeÇÃî≠éÀèÄîı(ê∂ê¨)
void BULLETS::launch(const sf::Vector2f& pos, const sf::Vector2f& vec, const sf::Texture& tex)
{
	if (Bullet.curNum < Bullet.totalNum)
	{
		int i = Bullet.curNum;

		Bullets[i].sprite.setTexture(tex);
		Bullets[i].sprite.setOrigin(Bullet.originPos);
		Bullets[i].sprite.setScale(Bullet.scale);

		Bullets[i].pos = pos;
		Bullets[i].vec = vec;
		Bullets[i].angle = 0;
		Bullet.curNum++;
	}
}

//íeÇÃìÆÇ´
void BULLETS::update()
{
	float delta = game()->timer();

	for (int i = Bullet.curNum - 1; i >= 0; i--)
	{
		Bullets[i].pos += (Bullets[i].vec * Bullet.advSpeed)*delta ;
		Bullets[i].angle += Bullet.angleSpeed * delta;
		if (Bullets[i].pos.y < Bullet.bcRadius ||
			Bullets[i].pos.y > game()->window()->getSize().y + Bullet.bcRadius ||
			Bullets[i].pos.x < Bullet.bcRadius - 100 ||
			Bullets[i].pos.x > game()->window()->getSize().x + 100 + Bullet.bcRadius)
		{
			kill(i);
		}
	}
}

void BULLETS::kill(int i)
{
	Bullet.curNum--;
	Bullets[i] = Bullets[Bullet.curNum];
}

void BULLETS::draw()
{
	for (int i = 0; i < Bullet.curNum; i++)
	{
		Bullets[i].sprite.setPosition(Bullets[i].pos);
		Bullets[i].sprite.setRotation(Bullets[i].angle);
		game()->window()->draw(Bullets[i].sprite);
	}
}
