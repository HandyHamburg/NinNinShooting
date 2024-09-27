#include"GAME.h"
#include "TRANSITION.h"

//����State��OUT_END
TRANSITION::TRANSITION(class GAME* game) : GAME_OBJECT(game), State(STATE::OUT_END){}

TRANSITION::~TRANSITION() {}

void TRANSITION::create()
{
}

//������������State��ύX
void TRANSITION::inTrigger()
{
	if (State == STATE::OUT_END)
	{
		State = STATE::IN_TRIGGER;
	}
}

//�s������������State��ύX
void TRANSITION::outTrigger()
{
	if (State == STATE::IN_END)
	{
		State = STATE::OUT_TRIGGER;
	}
}

void TRANSITION::draw()
{
	//�Q�[�����[�v���̏���
	if (State == STATE::IN_END || State == STATE::OUT_END)
	{
		return; //IN_END��OUT_END�ɂȂ��ď������I������牽�����Ȃ�
	}
	switch (State)
	{
		case STATE::IN_TRIGGER: //�������̏���
		{
			inTriggerProc();
			State = STATE::IN_NOW;//�������̏������[�v
			break;
		}
		case STATE::IN_NOW:
		{
			if (inProc())
			{
				State = STATE::IN_END;//inProc()�œ������������I�������true���A���ė���State��IN_END��
			}
			break;
		}
		case STATE::OUT_TRIGGER:
		{
			outTriggerProc();
			State = STATE::OUT_NOW; //�s�������̏���
			break;
		}
		case STATE::OUT_NOW://�s�������̏������[�v
		{
			if (outProc())
			{
				State = STATE::OUT_END;//outProc()�ŕs�������������I�������true���A���ė���State��IN_END��
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




//�������I��������ǂ�������
bool TRANSITION::inEndFlag()
{
	return (State == STATE::IN_END);

}

bool TRANSITION::outEndFlag()
{
	return (State == STATE::OUT_END);
}


