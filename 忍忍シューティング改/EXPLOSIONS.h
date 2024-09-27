#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class EXPLOSIONS :
	public GAME_OBJECT
{
public:
	struct DATA
	{
		sf::Texture texture;
		static constexpr int nflame = 4; //����4�t���[��
		sf::IntRect frame[nflame];
		sf::Vector2f scale;
		sf::Vector2f originPos;
		sf::SoundBuffer soundBufferExplosion;
		sf::Sound soundExplosion;
		float bcRadius;
		float animationSpeed;
		int totalNum;
		int curNum;
		int loopCntLimit;
	};
private:
	//���ʃf�[�^
	DATA Explosion;
	//�P�̃f�[�^
	struct EXPLOSION
	{
		sf::Sprite sprite;
		sf::Vector2f pos;
		float animationTimer;
		int loopCnt;
	};

	EXPLOSION* Explosions;
public:
	EXPLOSIONS(class GAME* game);
	~EXPLOSIONS() {};

	void create();
	void launch(const sf::Vector2f& pos);
	void update();
	void init();
	void draw();
	void kill(int i);

	sf::Vector2f pos(int i) { return Explosions[i].pos; }
	float bcRadius() { return Explosion.bcRadius; }
	int curNum() { return Explosion.curNum; }
};