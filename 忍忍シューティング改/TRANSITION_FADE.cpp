#include "TRANSITION_FADE.h"
#include"GAME.h"

TRANSITION_FADE::TRANSITION_FADE(GAME* game) : TRANSITION(game)
{
}

void TRANSITION_FADE::create()
{
	Transition.color = sf::Color(0, 0, 0,255);
	Transition.time = 1.0f;
}

//ループ前にこれが呼び出される(黒い板をバーンと全画面に貼り付け)
void TRANSITION_FADE::inTriggerProc()
{
	sf::RectangleShape rect;
	rect.setPosition(0, 0);
	rect.setSize(sf::Vector2f(600.f, 800.f));
	rect.setFillColor(Transition.color);
	game()->window()->draw(rect);
}

bool TRANSITION_FADE::inProc()
{
	sf::RectangleShape rect;
	rect.setPosition(0, 0);
	rect.setSize(sf::Vector2f(600.f, 800.f));
	rect.setFillColor(Transition.color);
	rect.setOutlineThickness(0);
	game()->window()->draw(rect);
	//透過処理
	Transition.color.a -= 255 / Transition.time * (game()->timer());
	if (Transition.color.a <= 5.f)
	{
		return true;
	}
	return false; //透過処理中はFalseを返す
}

void TRANSITION_FADE::outTriggerProc()
{
	Transition.color.a = 0.0f;
}

bool TRANSITION_FADE::outProc()
{
	sf::RectangleShape rect;
	rect.setPosition(0, 0);
	rect.setSize(sf::Vector2f(600.f, 800.f));
	rect.setFillColor(Transition.color);
	rect.setOutlineThickness(0);
	game()->window()->draw(rect);
	//不透過処理
	Transition.color.a += 255 / Transition.time * (game()->timer());
	if (Transition.color.a >= 250.0f)
	{
		return true;
	}
	return false; //不透過処理中はFalseを返す
}
