#pragma once
#include "TRANSITION.h"
#include<SFML/Graphics.hpp>
class TRANSITION_FADE : public TRANSITION
{
public:
	struct DATA
	{
		sf::Color color;
		float time = 0;
	};
private:
	DATA 
		Transition;
public:
	TRANSITION_FADE(class GAME* game);
	void create() override;
    void inTriggerProc() override;
	bool inProc() override;
	void outTriggerProc() override;
	bool outProc() override;
};

