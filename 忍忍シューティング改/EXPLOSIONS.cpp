#include "EXPLOSIONS.h"
#include"GAME.h"
#include"CONTAINER.h"
#include<iostream>

EXPLOSIONS::EXPLOSIONS(GAME* game) : GAME_OBJECT(game)
{
}

void EXPLOSIONS::create()
{
	Explosion = game()->container()->explosion();
	Explosions = new EXPLOSION[Explosion.totalNum];
}

void EXPLOSIONS::launch(const sf::Vector2f& pos)
{
	std::cout << "Im called" << "\n";

	if (Explosion.curNum < Explosion.totalNum)
	{
		int i = Explosion.curNum;

		Explosions[i].pos = pos;
		Explosions[i].sprite.setTexture(Explosion.texture);
		Explosions[i].sprite.setScale(Explosion.scale);
		Explosions[i].sprite.setOrigin(Explosion.originPos);
		Explosions[i].animationTimer = 0;
		Explosions[i].loopCnt = 0;
		Explosion.curNum++;
	}

	Explosion.soundExplosion.play();
}

void EXPLOSIONS::update()
{

}

void EXPLOSIONS::init()
{
	Explosion.curNum = 0;
}

void EXPLOSIONS::draw()
{
	float delta = game()->timer();

	for (int i = Explosion.curNum - 1; i >= 0; i--)
	{
		Explosions[i].animationTimer += Explosion.animationSpeed * delta;
		if (Explosions[i].animationTimer >= Explosion.nflame)
		{
			Explosions[i].animationTimer = 0;
			Explosions[i].loopCnt++;
		}
		Explosions[i].sprite.setPosition(Explosions[i].pos);
		Explosions[i].sprite.setTextureRect(Explosion.frame[static_cast<int>(Explosions[i].animationTimer)]);
		if (Explosions[i].loopCnt == Explosion.loopCntLimit)
		{
			kill(i);
		}

	}

	for (int i = 0; i < Explosion.curNum; i++)
	{
		game()->window()->draw(Explosions[i].sprite);
	}
}

void EXPLOSIONS::kill(int i)
{
	Explosion.curNum--;
	Explosions[i] = Explosions[Explosion.curNum];
}


