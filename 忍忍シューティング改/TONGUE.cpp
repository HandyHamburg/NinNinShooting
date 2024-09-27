#include"TONGUE.h"
#include"CONTAINER.h"
#include"GAME.h"

TONGUE::TONGUE(GAME* game) : GAME_OBJECT(game)
{
}

TONGUE::~TONGUE()
{
	delete[] Tongues;
}

void TONGUE::init()
{
	Tongue.curNum = 0;
	Tongues = new TONGUES[Tongue.totalNum];
}

void TONGUE::launch(const sf::Vector2f& pos, const sf::Vector2f& vec, const sf::Texture& tex)
{
	if (Tongue.curNum < Tongue.totalNum)
	{
		int i = Tongue.curNum;

		Tongues[i].sprite.setTexture(tex);
		Tongues[i].sprite.setOrigin(Tongue.originPos);
		Tongues[i].sprite.setScale(Tongue.scale);
		
		Tongues[i].pos = pos;
		Tongues[i].vec = vec;
		Tongues[i].angle = 0;
		Tongue.curNum++;
	}
}

void TONGUE::update()
{
	float delta = game()->timer();

	for (int i = Tongue.curNum - 1; i >= 0; i--)
	{
		Tongues[i].pos += (Tongues[i].vec * Tongue.advSpeed) * delta;
		if (Tongues[i].pos.y < Tongue.bcRadius ||
			Tongues[i].pos.y > game()->window()->getSize().y + Tongue.bcRadius ||
			Tongues[i].pos.x < Tongue.bcRadius - 100 ||
			Tongues[i].pos.x > game()->window()->getSize().x + 100 + Tongue.bcRadius)
		{
			kill(i);
		}
	}
}

void TONGUE::kill(int i)
{

}

