#pragma once
class GAME_OBJECT
{
private:
	class GAME* Game = nullptr;
public:
	GAME_OBJECT(class GAME* game); //�R���X�g���N�^��game�N���X�̃|�C���^�����āAprivate��Game�ɃR�s�[���Ă���
	virtual ~GAME_OBJECT();
	//Accessors �Q�b�^�[
	class GAME* game() { return Game; } //Game�|�C���^�̃Q�b�^�[ 
};

