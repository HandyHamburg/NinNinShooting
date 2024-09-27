#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>

class TONGUE : public GAME_OBJECT
{
public:
	struct DATA
	{
		sf::Texture textureTop; //ê„ÇÃêÊí[
		sf::Texture texture;
		sf::Vector2f scale;
		sf::Vector2f originPos;
		float advSpeed;
		float bcRadius; //Boundary Circle Radius ìñÇΩÇËîªíËÇÃîºåa
		int totalNum;
		int curNum;
	};
private:
	DATA Tongue;

	struct TONGUES
	{
		sf::Sprite sprite;
		sf::Vector2f pos;
		sf::Vector2f vec;
		float angle;
	};
	
	TONGUES* Tongues;
public:
	TONGUE(class GAME* game);
	~TONGUE();
	void init();
	void launch(const sf::Vector2f& pos, const sf::Vector2f& vec, const sf::Texture& tex);
	void update();
	void kill(int i);
	void draw();
};

