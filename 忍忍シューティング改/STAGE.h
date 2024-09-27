#pragma once
#include "SCENE.h"
#include<SFML/Graphics.hpp>
class STAGE : public SCENE
{
public:
	struct DATA {
		int no;
		int iniNo;
		int ptnNo;
		sf::Text text;
		int textOpacity;
		sf::Font font;
		sf::Color textColor;
		sf::Vector2f textPos;
		int charactorSize;
		
	};

private:
	DATA Stage;
public:
	STAGE(GAME* game);
	~STAGE();

	//SCENEからオーバーライドする関数
	void init();
	void update();
	void draw();
	void nextScene();
	void create();

	//ステージ番号のゲッター
	int no() { return Stage.no; }
	sf::Text text() { return Stage.text; }
};

