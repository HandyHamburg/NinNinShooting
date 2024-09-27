#pragma once
class GAME_OBJECT
{
private:
	class GAME* Game = nullptr;
public:
	GAME_OBJECT(class GAME* game); //コンストラクタでgameクラスのポインタを貰って、privateのGameにコピーしている
	virtual ~GAME_OBJECT();
	//Accessors ゲッター
	class GAME* game() { return Game; } //Gameポインタのゲッター 
};

