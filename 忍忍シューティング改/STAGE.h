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

	//SCENE����I�[�o�[���C�h����֐�
	void init();
	void update();
	void draw();
	void nextScene();
	void create();

	//�X�e�[�W�ԍ��̃Q�b�^�[
	int no() { return Stage.no; }
	sf::Text text() { return Stage.text; }
};

