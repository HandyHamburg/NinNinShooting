#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class PLAYER : public GAME_OBJECT
{
//各種データ
public:
	struct DATA
	{
		sf::Texture texture;
		sf::Sprite sprite;
		static constexpr int nflame = 3; //3フレームしかつくってへん
		sf::IntRect frame[nflame];
		sf::Vector2f scale;
		sf::Vector2f pos;
		sf::Vector2f originPos;
		sf::Vector2f vec;
		float angle;
		float limmitW;
		float limmitH;
		float animationTimer;
		//launch(弾発射用)
		float launchVecTheta;
		float ofstLaunchVecTheta; //パワーアップの時の3way弾の射角
		float triggerErapsedTime;
		float triggerInterval;
		sf::Vector2f ofstLaunchDist;
		int shootCnt;
		//collision
		float bcRadius;
		float invincibleTime;
		float invincibleRestTime;
		int hp;
		sf::Color collisionColor;
		sf::Color normalColor;
		//パワーアップ状態
		int powerUpState;
		int powerUpStateIzuna;
		sf::SoundBuffer soundBufferPowerUp;
		sf::Sound soundPowerUp;
		sf::SoundBuffer soundBufferIzuna;
		sf::Sound soundIzuna;
		//射撃音
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
		//死亡音
		sf::SoundBuffer soundBufferDead;
		sf::Sound soundDead;
	};
private:
	DATA Player;

//機能
public:
	PLAYER(class GAME* game);
	~PLAYER();
	void create();
	void init();
	void update();
	void move();
	void shoot();
	void launch();
	void launchThreeWays();
	void launchIzuna();
	void draw();
	void collision();
	void collisionItemPower();
	void collisionItemIzuna();

	//ゲッター
	sf::Vector2f pos() { return Player.pos; }
	float launchVec() { return Player.launchVecTheta;}
	int hp() { return Player.hp; }

};

