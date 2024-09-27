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
		//ムーブパターン制御
		bool movePtnOne;
		bool movePtnTwo;
		//ムーブパターン1
		float refThetaOne;
		sf::Vector2f centerPosOne;
		sf::Vector2f centerMoveSpeedOne;
		float thetaSpeedOne; //角速度
		float targetPosXOne;
		float targetPosYOne;
		float xRadiusOne; //楕円の長い半径
		float yRadiusOne; //楕円の短い半径
		//ムーブパターン2
		float refThetaTwo;
		sf::Vector2f centerPosTwo;
		sf::Vector2f centerMoveSpeedTwo;
		float thetaSpeedTwo; //角速度
		float targetPosXTwo;
		float targetPosYTwo;
		float xRadiusTwo; //楕円の長い半径
		float yRadiusTwo; //楕円の短い半径
		//ムーブパターン3
		float refThetaThree;
		sf::Vector2f centerPosThree;
		sf::Vector2f centerMoveSpeedThree;
		float thetaSpeedThree; //角速度
		float targetPosXThree;
		float targetPosYThree;
		float xRadiusThree; //楕円の長い半径
		float yRadiusThree; //楕円の短い半径
		//敵の数
		int totalNum;
		int curNum;
		//当たり判定
		float bcRadius;
		int initHp;
		sf::Color collisionColor;
		sf::Color normalColor;
		float triggerInterval;//射撃間隔

		//ダメージ音
		sf::SoundBuffer soundBufferDamage;
		sf::Sound soundDamage;
		sf::SoundBuffer soundBufferDead;
		sf::Sound soundDead;

	};
private:
	//共通データ
	DATA Enemy;

	//単体データ配列
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

	//動き
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

