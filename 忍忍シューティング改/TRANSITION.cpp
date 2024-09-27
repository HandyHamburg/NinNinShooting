#include"GAME.h"
#include "TRANSITION.h"

//初期StateはOUT_END
TRANSITION::TRANSITION(class GAME* game) : GAME_OBJECT(game), State(STATE::OUT_END){}

TRANSITION::~TRANSITION() {}

void TRANSITION::create()
{
}

//透明化処理にStateを変更
void TRANSITION::inTrigger()
{
	if (State == STATE::OUT_END)
	{
		State = STATE::IN_TRIGGER;
	}
}

//不透明化処理にStateを変更
void TRANSITION::outTrigger()
{
	if (State == STATE::IN_END)
	{
		State = STATE::OUT_TRIGGER;
	}
}

void TRANSITION::draw()
{
	//ゲームループ内の処理
	if (State == STATE::IN_END || State == STATE::OUT_END)
	{
		return; //IN_ENDかOUT_ENDになって処理が終わったら何もしない
	}
	switch (State)
	{
		case STATE::IN_TRIGGER: //透明化の処理
		{
			inTriggerProc();
			State = STATE::IN_NOW;//透明化の処理ループ
			break;
		}
		case STATE::IN_NOW:
		{
			if (inProc())
			{
				State = STATE::IN_END;//inProc()で透明化処理が終わったらtrueが帰って来てStateがIN_ENDに
			}
			break;
		}
		case STATE::OUT_TRIGGER:
		{
			outTriggerProc();
			State = STATE::OUT_NOW; //不透明化の処理
			break;
		}
		case STATE::OUT_NOW://不透明化の処理ループ
		{
			if (outProc())
			{
				State = STATE::OUT_END;//outProc()で不透明化処理が終わったらtrueが帰って来てStateがIN_ENDに
			}
			break;
		}
	}
}

void TRANSITION::inTriggerProc()
{
}

bool TRANSITION::inProc()
{
	return false;
}

void TRANSITION::outTriggerProc()
{
}

bool TRANSITION::outProc()
{
	return false;
}




//処理が終わったかどうか判定
bool TRANSITION::inEndFlag()
{
	return (State == STATE::IN_END);

}

bool TRANSITION::outEndFlag()
{
	return (State == STATE::OUT_END);
}


