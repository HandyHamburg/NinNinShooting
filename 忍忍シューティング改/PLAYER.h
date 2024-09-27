#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class PLAYER : public GAME_OBJECT
{
//�e��f�[�^
public:
	struct DATA
	{
		sf::Texture texture;
		sf::Sprite sprite;
		static constexpr int nflame = 3; //3�t���[�����������Ăւ�
		sf::IntRect frame[nflame];
		sf::Vector2f scale;
		sf::Vector2f pos;
		sf::Vector2f originPos;
		sf::Vector2f vec;
		float angle;
		float limmitW;
		float limmitH;
		float animationTimer;
		//launch(�e���˗p)
		float launchVecTheta;
		float ofstLaunchVecTheta; //�p���[�A�b�v�̎���3way�e�̎ˊp
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
		//�p���[�A�b�v���
		int powerUpState;
		int powerUpStateIzuna;
		sf::SoundBuffer soundBufferPowerUp;
		sf::Sound soundPowerUp;
		sf::SoundBuffer soundBufferIzuna;
		sf::Sound soundIzuna;
		//�ˌ���
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
		//���S��
		sf::SoundBuffer soundBufferDead;
		sf::Sound soundDead;
	};
private:
	DATA Player;

//�@�\
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

	//�Q�b�^�[
	sf::Vector2f pos() { return Player.pos; }
	float launchVec() { return Player.launchVecTheta;}
	int hp() { return Player.hp; }

};

