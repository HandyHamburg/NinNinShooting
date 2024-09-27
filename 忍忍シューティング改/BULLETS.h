#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
class BULLETS : public GAME_OBJECT
{
public:
	struct DATA 
	{
		sf::Texture texture;
		sf::Vector2f scale;
		sf::Vector2f originPos;
		float advSpeed;
		float angleSpeed;
		float bcRadius; //Boundary Circle Radius �����蔻��̔��a
		int totalNum;
		int curNum;
	};
private:
	//���ʃf�[�^
	DATA Bullet;
	//�P�̃f�[�^�z��
	struct BULLET 
	{
		sf::Sprite sprite;
		sf::Vector2f pos;
		sf::Vector2f vec;
		float angle;
	};
	BULLET* Bullets;
protected:
	void SetBullets(const BULLETS::DATA& data);
public:
	BULLETS(class GAME* game);
	~BULLETS();
	void init();
	void launch(const sf::Vector2f& pos, const sf::Vector2f& vec, const sf::Texture& tex);
	void update();
	void kill(int i);
	void draw();

	//�e�̈ʒu�̃Q�b�^�[
	sf::Vector2f pos(int i) { return Bullets[i].pos; }
	//�e�̓����蔻��̃Q�b�^�[
	float bcRadius() { return Bullet.bcRadius; }
	int curNum() { return Bullet.curNum;  }

};

