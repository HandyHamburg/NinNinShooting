#pragma once
#include "SCENE.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class GAME_CLEAR : public SCENE
{
public:
	struct DATA
	{
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f scale;
		sf::Vector2f pos;
		sf::Vector2f originPos;
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
		float angle;
		float angleSpeed;
	};
private:
	DATA GameClear;
public:
	GAME_CLEAR(GAME* game);
	~GAME_CLEAR();

	//SCENEからオーバーライドする関数
	void init();
	void update();
	void draw();
	void nextScene();
	void create();
};

