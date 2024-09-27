#include "CONTAINER.h"
#include<iostream>
void CONTAINER::load()
{
	createData();
	loadGraphic();
	loadSound();
}


void CONTAINER::createData()
{
	//タイトルデータ
	Data.title.font.loadFromFile("Fonts\\Minecrafter.Reg.ttf");
	Data.title.textColor = (sf::Color::Red);	
	Data.title.charactorSize = 120;
	Data.title.pos.x = 120;
	Data.title.pos.y = 200;
	strcpy_s(Data.title.str, "TITLE");
	//タイトル背景
	Data.backgroundTitle.scale = { 1.0, 1.0 };
	Data.backgroundTitle.pos = { 0,0 };

	//ステージ
	Data.stage.iniNo = 1;
	Data.stage.no = Data.stage.iniNo;
	Data.stage.ptnNo = 3;
	//ステージ背景
	Data.backgroundStage.scale = { 1.0, 1.0 };
	Data.backgroundStage.pos = { 0,0 };
	//死亡時、ステージ表示用文字
	Data.stage.font.loadFromFile("Fonts\\tamanegi_kaisho_free.ttf");
	Data.stage.text.setFont(Data.stage.font);
	Data.stage.textColor = (sf::Color(255,0,0,0));
	Data.stage.text.setOrigin(100, 100);
	Data.stage.textOpacity = 0;
	Data.stage.charactorSize = 200;
	Data.stage.textPos.x = 300;
	Data.stage.textPos.y = 200;
	Data.stage.text.setString(L"死");

	//ゲームオーバー
	Data.gameOver.font.loadFromFile("Fonts\\tamanegi_kaisho_free.ttf");
	Data.gameOver.text.setFont(Data.gameOver.font);
	Data.gameOver.textColor = (sf::Color::Red);
	Data.gameOver.text.setOrigin(100, 100);
	Data.gameOver.charactorSize = 200;
	Data.gameOver.textPos.x = 300;
	Data.gameOver.textPos.y = 200;
	Data.gameOver.text.setString(L"死");
	//死の下の文字
	Data.gameOver.font.loadFromFile("Fonts\\tamanegi_kaisho_free.ttf");
	Data.gameOver.text2.setFont(Data.gameOver.font);
	Data.gameOver.text2Opacity = 0;
	Data.gameOver.text2Color = (sf::Color(255,0,0,0));
	Data.gameOver.charactorSize2 = 30;
	Data.gameOver.text2Pos.x = 210;
	Data.gameOver.text2Pos.y = 350;
	Data.gameOver.text2.setString("D  E  A  T  H");
	//オーバー背景
	Data.backgroundOver.scale = { 1.0, 1.0 };
	Data.backgroundOver.pos = { 0,0 };

	//ゲームクリア
	Data.gameClear.scale.x = 1.0;
	Data.gameClear.scale.y = 1.0;
	Data.gameClear.pos.x = 300;
	Data.gameClear.pos.y = 380;
	Data.gameClear.originPos.x = 160; //320*320のサイズだから
	Data.gameClear.originPos.y = 160;
	Data.gameClear.angle = 0;
	Data.gameClear.angleSpeed = 50;
	//クリア背景
	Data.backgroundClear.scale = { 1.0, 1.0 };
	Data.backgroundClear.pos = { 0,0 };

	//プレイヤーデータ
	for (int i = 0; i < Data.player.nflame; i++)
	{
		Data.player.frame[i] = {i * 96,0,96,96};
	}
	Data.player.scale.x = 1.0;
	Data.player.scale.y = 1.0;
	Data.player.pos.x = 300;
	Data.player.pos.y = 600;
	Data.player.originPos.x = 50; //100*100のサイズだから
	Data.player.originPos.y = 50;
	Data.player.vec.x = 300;
	Data.player.vec.y = 300;
	Data.player.angle = 0;
	Data.player.limmitW = 10;
	Data.player.limmitH = 10;
	Data.player.animationTimer = 0; //animationタイマー
	Data.player.powerUpState = 0;
	Data.player.powerUpStateIzuna = 0;
	Data.player.shootCnt = 0;
	//launch
	Data.player.launchVecTheta = 3.14159265 * 1.5; 
	Data.player.ofstLaunchVecTheta = 0.2;
	Data.player.triggerErapsedTime = 0; //発射してからの経過時間　初期値0
	Data.player.triggerInterval = 0.25f; //次回発射までの時間
	Data.player.ofstLaunchDist.x = 40; //発射位置
	Data.player.ofstLaunchDist.y = 40;
	//当たり判定
	Data.player.bcRadius = 1;
	Data.player.invincibleTime = 0.05f;
	Data.player.invincibleRestTime = 0;
	Data.player.hp = 500;
	Data.player.collisionColor = sf::Color(255, 0, 0);
	Data.player.normalColor = sf::Color(255, 255, 255);

	//プレイヤーの弾
	Data.playerBullet.scale.x = 0.5;
	Data.playerBullet.scale.y = 0.5;
	Data.playerBullet.originPos.x = 34.0; //64*64のサイズだから。でもちょっとずらしてる
	Data.playerBullet.originPos.y = 32.0;
	Data.playerBullet.totalNum = 50;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 600;
	Data.playerBullet.angleSpeed = 150.0f;
	Data.playerBullet.bcRadius = 20;
	//プレイヤーの弾(イズナ)
	Data.izunaBullet.scale.x = 1.0;
	Data.izunaBullet.scale.y = 1.0;
	Data.izunaBullet.originPos.x = 32.0; //64*64のサイズだから
	Data.izunaBullet.originPos.y = 32.0;
	Data.izunaBullet.totalNum = 50;
	Data.izunaBullet.curNum = 0;
	Data.izunaBullet.advSpeed = 300;
	Data.izunaBullet.angleSpeed = -150.0f;
	Data.izunaBullet.bcRadius = 20;

	//敵データ
	Data.enemy.scale.x = 1.0;
	Data.enemy.scale.y = 1.0;
	Data.enemy.originPos.x = 64; //128*128のサイズだから
	Data.enemy.originPos.y = 64;
	Data.enemy.totalNum = 10; //敵の数
	Data.enemy.curNum = Data.enemy.totalNum; //敵の現在の数初期化
	Data.enemy.ofstLaunchDist.x = 20; //弾の発射位置
	Data.enemy.ofstLaunchDist.y = 20;
	Data.enemy.initHp = 5; //初期体力

	//敵ムーブパターン1
	Data.enemy.centerPosOne.x = 300;
	Data.enemy.centerPosOne.y = -300;
	Data.enemy.centerMoveSpeedOne.x = 200;
	Data.enemy.centerMoveSpeedOne.y = 80;
	Data.enemy.refThetaOne = 0; //初期スポーン位置(radian)
	Data.enemy.thetaSpeedOne = 0.6f;
	Data.enemy.targetPosXOne = 100;
	Data.enemy.targetPosYOne = 200;
	Data.enemy.xRadiusOne = 150;
	Data.enemy.yRadiusOne = 50;

	//敵ムーブパターン2
	Data.enemy.refThetaTwo = 3.14159265 * 1.5; //π=3.14[radian]で、π* 3/2の位置を初期スポーン位置にしたい
	Data.enemy.centerPosTwo.x = 300;
	Data.enemy.centerPosTwo.y = -600;
	Data.enemy.centerMoveSpeedTwo.x = 0;
	Data.enemy.centerMoveSpeedTwo.y = 100;
	Data.enemy.thetaSpeedTwo = 1.0f;
	Data.enemy.targetPosXTwo = 0;
	Data.enemy.targetPosYTwo = 200;
	Data.enemy.xRadiusTwo = 200;
	Data.enemy.yRadiusTwo = 300;

	//敵ムーブパターン3
	Data.enemy.refThetaThree = 3.14159265 * 1.75; //π=3.14[radian]で、π* 7/4の位置を初期スポーン位置にしたい
	Data.enemy.centerPosThree.x = 300;
	Data.enemy.centerPosThree.y = -200;
	Data.enemy.centerMoveSpeedThree.x = 300;
	Data.enemy.centerMoveSpeedThree.y = 100;
	Data.enemy.thetaSpeedThree = 2.0f;
	Data.enemy.targetPosXThree = 50;
	Data.enemy.targetPosYThree = 200;
	Data.enemy.xRadiusThree = 400;
	Data.enemy.yRadiusThree = 400;
	
	//敵の当たり判定
	Data.enemy.bcRadius = 28;
	Data.enemy.collisionColor = sf::Color(255, 0, 0);
	Data.enemy.normalColor = sf::Color(255, 255, 255);

	//敵の弾
	Data.enemyBullet.scale.x = 1.0;
	Data.enemyBullet.scale.y = 1.0;
	Data.enemyBullet.originPos.x = 16.0; //32*48のサイズだから
	Data.enemyBullet.originPos.y = 24.0;
	Data.enemyBullet.curNum = 0;
	Data.enemyBullet.advSpeed = 600;
	Data.enemyBullet.angleSpeed = 0;
	Data.enemyBullet.bcRadius = 20;
	Data.enemyBullet.totalNum = 100; //忘れない！！
	Data.enemy.triggerInterval = 3.72;

	//ボス
	Data.boss.scale.x = 5.0;
	Data.boss.scale.y = 5.0;
	Data.boss.pos.x = 300; //初期位置
	Data.boss.pos.y = -300; 
	Data.boss.originPos.x = 32; //64*64のサイズだから
	Data.boss.originPos.y = 32;
	Data.boss.flameCol = 3;
	Data.boss.flameRow = 4;
	for (int i = 0; i < Data.boss.flameCol; i++)
	{
		for (int j = 0; j < Data.boss.flameRow; j++)
		{
			Data.boss.frame[i*Data.boss.flameRow + j] = {j*64, i*64, 64, 64};
		}
	}
	Data.boss.curPhase = 0; //
	Data.boss.nPhase = Data.boss.flameCol;
	Data.boss.animationSpeed = 10.f;
	Data.boss.animationTimer = 0;
	Data.boss.angle = 0;
	Data.boss.hp = 500;
	Data.boss.launchVecTheta = 3.14159265 * 0.5; //最初は真下に撃つ
	Data.boss.ofstLaunchVecTheta = 0.2;
	Data.boss.triggerErapsedTime = 0.f;	
	Data.boss.ofstLaunchDist = { 100.f, 100.f };
	Data.boss.bcRadius = 120;
	Data.boss.collisionColor = sf::Color(255, 0, 0);
	Data.boss.collisionColorPhase3 = sf::Color(255, 0, 0);
	Data.boss.normalColor = sf::Color(255, 255, 255);

	//ボスの動き1
	Data.boss.phaseOneThreshHold = 400;
	Data.boss.triggerIntervalOne = 1.0f;
	Data.boss.vecOne.x = 100.f;
	Data.boss.vecOne.y = 100.f;
	Data.boss.targetPosX = 50.f;
	Data.boss.targetPosY = 100.f;
	//ボスの動き2
	Data.boss.phaseTwoThreshHold = 350;
	Data.boss.phaseTwoEnter = 1;
	Data.boss.triggerIntervalTwo = 0.5f;
	Data.boss.vecTwo.x = 300;
	Data.boss.vecTwo.y = 0;
	//ボスの動き3
	Data.boss.phaseThreeEnter = 1;
	Data.boss.triggerIntervalThree = 0.1f;
	Data.boss.triggerBurstInterval = 1.8f;
	Data.boss.triggerBurstErapsedTime = 0.f;
	Data.boss.shootCnt = 0;
	Data.boss.vecThree.x = 300.f;
	Data.boss.vecThree.y = 0;

	//舌
	Data.tongue.scale = { 1.0f, 1.0f };
	Data.tongue.originPos = { 32.f, 32.f };
	Data.tongue.totalNum = 100;
	Data.tongue.curNum = 0;
	Data.tongue.advSpeed = 100;
	Data.tongue.bcRadius = 20.f;

	//爆発
	for (int i = 0; i < Data.explosion.nflame; i++)
	{
		Data.explosion.frame[i] = { i * 64,0,64,64 }; //(0,0),(64,0),(128,0),(192,0)の位置に64*64の四角形が4つ
	}
	Data.explosion.originPos = { 32, 32 }; //縦64 横64*4
	Data.explosion.scale = { 4.0f, 4.0f };
	Data.explosion.animationSpeed = 50.0f; // animationTimer += animationSpeed* delta でやる
	Data.explosion.totalNum = 100;
	Data.explosion.curNum = 0;
	Data.explosion.loopCntLimit = 5;
	Data.explosion.bcRadius = 32*3.0f; // scale4倍だから

	//アイテム
	//地獄忍魔刀アイテム
	Data.powerItem.scale.x = 0.8;
	Data.powerItem.scale.y = 0.8;
	Data.powerItem.originPos.x = 32.0; //64*64だから
	Data.powerItem.originPos.y = 32.0;
	Data.powerItem.advSpeed = 200;
	Data.powerItem.angleSpeed = 100;
	Data.powerItem.bcRadius = 40; //Boundary Circle Radius 当たり判定の半径
	Data.powerItem.dropRange = 1; //出現率
	Data.powerItem.totalNum = 100;
	Data.powerItem.curNum = 0;

	//イズナアイテム
	Data.izunaItem.scale.x = 0.8;
	Data.izunaItem.scale.y = 0.8;
	Data.izunaItem.originPos.x = 32.0; //64*64だから
	Data.izunaItem.originPos.y = 32.0;
	Data.izunaItem.advSpeed = 200;
	Data.izunaItem.angleSpeed = 100;
	Data.izunaItem.bcRadius = 40; //Boundary Circle Radius 当たり判定の半径
	Data.izunaItem.dropRange = 2; //出現率
	Data.izunaItem.totalNum = 100;
	Data.izunaItem.curNum = 0;
}

void CONTAINER::loadGraphic()
{
	Data.player.texture.loadFromFile("imgs\\Michiru.png");
	Data.enemy.texture.loadFromFile("imgs\\Sensei_1.png");
	Data.explosion.texture.loadFromFile("imgs\\Explosion_1.png");
	Data.playerBullet.texture.loadFromFile("imgs\\Shuriken.png");
	Data.izunaBullet.texture.loadFromFile("imgs\\bomb_1.png");
	Data.enemyBullet.texture.loadFromFile("imgs\\Sensei_bullet.png");
	Data.gameClear.texture.loadFromFile("imgs\\kokona100.png");
	Data.powerItem.texture.loadFromFile("imgs\\ZigokuNinmaTou.png");
	Data.izunaItem.texture.loadFromFile("imgs\\izuna.png");
	Data.backgroundStage.texture.loadFromFile("imgs\\sky.png");
	Data.boss.texture.loadFromFile("imgs\\Sensei_2.png");
	Data.tongue.textureTop.loadFromFile("imgs\\Sensei_tongue_top.png");
	Data.tongue.texture.loadFromFile("imgs\\Sensei_tongue_middle.png");
}

void CONTAINER::loadSound()
{
	Data.player.soundBuffer.loadFromFile("Sounds\\pBulletSound.wav");
	Data.player.sound.setBuffer(Data.player.soundBuffer);
	Data.player.soundBufferPowerUp.loadFromFile("Sounds\\michiruBuff.wav");
	Data.player.soundPowerUp.setBuffer(Data.player.soundBufferPowerUp);
	Data.player.soundBufferIzuna.loadFromFile("Sounds\\michirubuffizuna.wav");
	Data.player.soundIzuna.setBuffer(Data.player.soundBufferIzuna);
	Data.player.soundBufferDead.loadFromFile("Sounds\\michiruDead.wav");
	Data.player.soundDead.setBuffer(Data.player.soundBufferDead);
	Data.enemy.soundBufferDamage.loadFromFile("Sounds\\damaged3.wav");
	Data.enemy.soundDamage.setBuffer(Data.enemy.soundBufferDamage);
	Data.enemy.soundBufferDead.loadFromFile("Sounds\\enemyDead.wav");
	Data.enemy.soundDead.setBuffer(Data.enemy.soundBufferDead);
	Data.explosion.soundBufferExplosion.loadFromFile("Sounds\\explosion.wav");
	Data.explosion.soundExplosion.setBuffer(Data.explosion.soundBufferExplosion);
	Data.gameClear.soundBuffer.loadFromFile("Sounds\\cocona.wav");
	Data.gameClear.sound.setBuffer(Data.gameClear.soundBuffer);
	Data.gameOver.soundBuffer.loadFromFile("Sounds\\coconaZenryoku.wav");
	Data.gameOver.sound.setBuffer(Data.gameOver.soundBuffer);
	Data.gameOver.sound.setVolume(500);
}
