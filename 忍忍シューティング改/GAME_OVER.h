#pragma once
#include "SCENE.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class GAME_OVER : public SCENE
{
public:
	struct DATA
	{
		sf::Text text;
		sf::Font font;
		sf::Color textColor;
		sf::Vector2f textPos;
		int charactorSize;

		sf::Text text2;
		int text2Opacity;
		sf::Font font2;
		sf::Color text2Color;
		sf::Vector2f text2Pos;
		int charactorSize2;

		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
	};
private:
	DATA GameOver;
public:
	GAME_OVER(GAME* game);
	~GAME_OVER();

	//SCENEからオーバーライドする関数
	void init();
	void update();
	void draw();
	void nextScene();
	void create();
};

