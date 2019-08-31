#pragma once
#include "pch.h"	
#include "Scene.h"
#include "DoubleBuffer.h"
#include "Snake.h"
#include "Food.h"
#define FWSCENE GameScene::GetInstance()
class GameScene :
	public Scene
{
public :
	void Render();
	void PrintMap();
public:
	GameScene();
	~GameScene();
	void gotoxy(int x, int y);
	string s;
	DoubleBuffer doubleBuffer;
	bool First = false, Second = false, three = false;
public:
	static GameScene* GetInstance();
};

