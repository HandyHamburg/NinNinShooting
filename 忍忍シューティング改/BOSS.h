#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
class BOSS :
    public GAME_OBJECT
{
public:
    struct DATA
    {
		sf::Texture texture;
		sf::Sprite sprite;
		static constexpr int nflame = 12; 
		int flameCol;
		int flameRow;
		int curPhase;
		int nPhase;
		float animationTimer;
		float animationSpeed;
		sf::IntRect frame[nflame];
		sf::Vector2f scale;
		sf::Vector2f pos;
		sf::Vector2f originPos;
		float angle;
		//launch(弾発射用)
		float launchVecTheta;
		float ofstLaunchVecTheta; //3wayとか用
		float triggerErapsedTime;
		sf::Vector2f ofstLaunchDist;
		//collision
		float bcRadius;
		float invincibleTime;
		float invincibleRestTime;
		int hp;
		sf::Color collisionColor;
		sf::Color collisionColorPhase3;
		sf::Color normalColor;

		//ムーブパターン1
		int phaseOneThreshHold;
		float triggerIntervalOne;
		float targetPosX;
		float targetPosY;
		sf::Vector2f vecOne;

		//ムーブパターン2
		int phaseTwoThreshHold;
		int phaseTwoEnter;
		float triggerIntervalTwo;
		sf::Vector2f vecTwo;

		//ムーブパターン3
		int phaseThreeEnter;
		float triggerIntervalThree;
		float triggerBurstInterval;
		float triggerBurstErapsedTime;
		int shootCnt;
		sf::Vector2f vecThree;
    };
private:
	DATA Boss;
public:
	BOSS(class GAME* game);
	~BOSS() {};

	void create();
	void init();
	void update();

	void moveOne();
	void launchOne();

	void moveTwo();
	void launchTwo();

	void moveThree();
	void launchThree();

	void phaseShift();
	void collision();
	void draw();

	int hp() { return Boss.hp; }

};

