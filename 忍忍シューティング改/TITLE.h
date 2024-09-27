#pragma once
#include "SCENE.h"
#include<SFML/Graphics.hpp>

class TITLE : public SCENE
{
public:
	struct DATA 
	{
		sf::Text text;
		sf::Font font;
		sf::Color textColor;
		sf::Vector2f pos;
		int charactorSize;
		char str[16];
	};
private:
	DATA Title;
public:
	TITLE(GAME* game);
	~TITLE();

	//SCENEからオーバーライドする関数
	void init();
	void update();
	void draw();
	void nextScene();
	void create(); 
};

