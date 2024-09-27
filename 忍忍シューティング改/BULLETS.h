#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
class BULLETS : public GAME_OBJECT
{
public:
	struct DATA 
	{
		sf::Texture texture;
		sf::Vector2f scale;
		sf::Vector2f originPos;
		float advSpeed;
		float angleSpeed;
		float bcRadius; //Boundary Circle Radius 当たり判定の半径
		int totalNum;
		int curNum;
	};
private:
	//共通データ
	DATA Bullet;
	//単体データ配列
	struct BULLET 
	{
		sf::Sprite sprite;
		sf::Vector2f pos;
		sf::Vector2f vec;
		float angle;
	};
	BULLET* Bullets;
protected:
	void SetBullets(const BULLETS::DATA& data);
public:
	BULLETS(class GAME* game);
	~BULLETS();
	void init();
	void launch(const sf::Vector2f& pos, const sf::Vector2f& vec, const sf::Texture& tex);
	void update();
	void kill(int i);
	void draw();

	//弾の位置のゲッター
	sf::Vector2f pos(int i) { return Bullets[i].pos; }
	//弾の当たり判定のゲッター
	float bcRadius() { return Bullet.bcRadius; }
	int curNum() { return Bullet.curNum;  }

};

