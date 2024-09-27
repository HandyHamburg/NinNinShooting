#include "ITEMS.h"
#include"GAME.h"
#include"CONTAINER.h"

ITEMS::ITEMS(GAME* game) : GAME_OBJECT(game)
{
}



void ITEMS::SetItems(const ITEMS::DATA& data)
{
	Item = data;
	Items = new ITEM[Item.totalNum];
}

void ITEMS::init()
{
	Item.curNum = 0;
}

void ITEMS::launch(const sf::Vector2f& pos, const sf::Texture& tex)
{
	if (Item.curNum < Item.totalNum)
	{
		int i = Item.curNum;

		Items[i].sprite.setTexture(tex);
		Items[i].sprite.setScale(Item.scale);
		Items[i].sprite.setOrigin(Item.originPos);

		Items[i].pos = pos;
		Items[i].vec.x = 0;
		Items[i].vec.y = 1; //常に真下に進む
		Items[i].angle = 0;
		Item.curNum++;
	}
}

void ITEMS::update()
{
	float delta = game()->timer();

	for (int i = Item.curNum - 1; i >= 0; i--)
	{
		Items[i].pos += (Items[i].vec * Item.advSpeed) * delta; //常に真下に進む
		Items[i].angle += Item.angleSpeed * delta;
		if (Items[i].pos.y > game()->window()->getSize().y + Item.bcRadius || //下につくか左右についたら消える
			Items[i].pos.x < Item.bcRadius - 100 ||
			Items[i].pos.x > game()->window()->getSize().x + 100 + Item.bcRadius)
		{
			kill(i);
		}
	}
}

void ITEMS::kill(int i)
{
	Item.curNum--;
	Items[i] = Items[Item.curNum];
}

void ITEMS::draw()
{
	for (int i = 0; i < Item.curNum; i++)
	{
		Items[i].sprite.setPosition(Items[i].pos);
		Items[i].sprite.setRotation(Items[i].angle);
		game()->window()->draw(Items[i].sprite);
	}
}


