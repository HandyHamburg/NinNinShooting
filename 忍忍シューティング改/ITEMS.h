#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class ITEMS : public GAME_OBJECT
{
public:
	struct DATA
	{
		sf::Texture texture;
		sf::Vector2f scale;
		sf::Vector2f originPos;
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
		float advSpeed;
		float angleSpeed;
		float bcRadius; //Boundary Circle Radius 当たり判定の半径
		int dropRange; //出現率
		int totalNum;
		int curNum;
	};
private:
	//共通データ
	DATA Item;
	//単体データ配列
	struct ITEM
	{
		sf::Sprite sprite;
		sf::Vector2f pos;
		sf::Vector2f vec;
		float angle;
	};
	ITEM* Items;
protected:
	void SetItems(const ITEMS::DATA& data);
public:
	ITEMS(class GAME* game);
	~ITEMS() {};

	void init();
	void launch(const sf::Vector2f& pos, const sf::Texture& tex);
	void update();
	void kill(int i);
	void draw();

	//弾の位置のゲッター
	sf::Vector2f pos(int i) { return Items[i].pos; }
	//弾の当たり判定のゲッター
	float bcRadius() { return Item.bcRadius; }
	int curNum() { return Item.curNum; }
	//Soundのゲッター
	sf::Sound sound() { return Item.sound; }
};

