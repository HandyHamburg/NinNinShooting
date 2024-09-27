#pragma once
#include "GAME_OBJECT.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class ITEMS : public GAME_OBJECT
{
public:
	struct DATA
	{
		sf::Texture texture;
		sf::Vector2f scale;
		sf::Vector2f originPos;
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
		float advSpeed;
		float angleSpeed;
		float bcRadius; //Boundary Circle Radius �����蔻��̔��a
		int dropRange; //�o����
		int totalNum;
		int curNum;
	};
private:
	//���ʃf�[�^
	DATA Item;
	//�P�̃f�[�^�z��
	struct ITEM
	{
		sf::Sprite sprite;
		sf::Vector2f pos;
		sf::Vector2f vec;
		float angle;
	};
	ITEM* Items;
protected:
	void SetItems(const ITEMS::DATA& data);
public:
	ITEMS(class GAME* game);
	~ITEMS() {};

	void init();
	void launch(const sf::Vector2f& pos, const sf::Texture& tex);
	void update();
	void kill(int i);
	void draw();

	//�e�̈ʒu�̃Q�b�^�[
	sf::Vector2f pos(int i) { return Items[i].pos; }
	//�e�̓����蔻��̃Q�b�^�[
	float bcRadius() { return Item.bcRadius; }
	int curNum() { return Item.curNum; }
	//Sound�̃Q�b�^�[
	sf::Sound sound() { return Item.sound; }
};

