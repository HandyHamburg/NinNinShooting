#pragma once
#include "GAME_OBJECT.h"

//�e�w�i�̊��N���X
class BACKGROUND : public GAME_OBJECT
{
public:
	BACKGROUND(class GAME* game);
	virtual ~BACKGROUND() {};
	virtual void create();
	virtual void init();
	virtual void draw();
};

