#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<time.h>

class GAME
{
//�E�B���h�E�֘A
private:
	sf::RenderWindow* Window;
	sf::VideoMode VideoMode;
	sf::Event Ev;
	float Timer;
	sf::Clock DeltaClock;

//KeyHold�֘A
	bool KeyHold = false;

//�R���e�i
private: 
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//�V�[��
public:
	enum SCENE_ID
	{
		//0����4��
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES]; //NUM_SCENES=4
	class BACKGROUND* Backgrounds[NUM_SCENES]; //�w�i�p
	SCENE_ID CurSceneId;

//�V�[���J��
private:
	class TRANSITION* Transition;
public:
	void changeScene(SCENE_ID sceneId);
	class STAGE* stage(); // Scene�̃|�C���^�͎����Ă��邪�h���N���X�̃|�C���^�͕Ԃ��Ȃ����ۂ��̂ŁA�֐�����
	SCENE_ID curSceneId() { return CurSceneId; }

//�L�����N�^�[
private:
	class PLAYER* Player;
	class ENEMIES* Enemies;
	class BOSS* Boss;
	class PLAYER_BULLETS* PlayerBullets;
	class ENEMY_BULLETS* EnemyBullets;
	class IZUNA_BULLETS* IzunaBullets;
	class POWER_ITEMS* PowerItems;
	class IZUNA_ITEMS* IzunaItems;
	class EXPLOSIONS* Explosions;
public:
	class PLAYER* player() { return Player; }
	class ENEMIES* enemies() { return Enemies; }
	class BOSS* boss() { return Boss; }
	class PLAYER_BULLETS* playerBullets() { return PlayerBullets; }
	class ENEMY_BULLETS* enemyBullets() { return EnemyBullets; }
	class IZUNA_BULLETS* izunaBullets() { return IzunaBullets; }
	class POWER_ITEMS* powerItems() { return PowerItems; }
	class IZUNA_ITEMS* izunaItems() { return IzunaItems; }
	class EXPLOSIONS* explosions() { return Explosions; }

//�Q�[���V�X�e��
	GAME();
	~GAME();
	void run();

//�Q�b�^�[
	const bool running() { return Window->isOpen(); } //�E�B���h�E���J���Ă��邩�ǂ���	
	const sf::Event event() const { return Ev; }//Ev�̃|�C���^��Ԃ�
	const bool keyHoldGetter() const { return KeyHold; } // KeyHold�̃Q�b�^�[
	const float timer() const { return Timer; }//Timer��Ƃ��f���^�^�C���̃Q�b�^�[
	class TRANSITION* transition() { return Transition; }//Transition�̃Q�b�^�[
	class BACKGROUND* backgrounds(int i) { return Backgrounds[i]; }//�w�i�N���X�̃Q�b�^�[

//�Z�b�^�[
	sf::RenderWindow* window() { return Window; } //�E�B���h�E�̃|�C���^��Ԃ�
	bool keyHoldSetter(bool keyhold); // KeyHold�̃Z�b�^�[

//�C�x���g�|�[�����O
	void pollEvent(); //�E�B���h�E������ꂽ���m�F
};

