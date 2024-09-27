#pragma once
#include "GAME_OBJECT.h"
#include<iostream>
class TRANSITION : public GAME_OBJECT
{
public:
	enum class STATE {
		IN_TRIGGER, IN_NOW, IN_END,
		OUT_TRIGGER, OUT_NOW, OUT_END
	};
private:
	 STATE State;
public:
	TRANSITION(class GAME* game);
	virtual ~TRANSITION();
	virtual void create();
	void inTrigger();
	void outTrigger();
	void draw();
	//オーバーライド
	virtual void inTriggerProc();
	virtual bool inProc(); 
	virtual void outTriggerProc();
	virtual bool outProc();
	bool inEndFlag();
	bool outEndFlag();

	STATE state() { return State; }
};

