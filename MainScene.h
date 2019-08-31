#pragma once
#include "Scene.h"
#include "DoubleBuffer.h"
#include "GameScene.h"
#define MISCENE MainScene::GetInstance()
class MainScene :
	public Scene
{
public:
	typedef struct Position {
		int x,y;
	}Pos;
	MainScene();
	~MainScene();
public:
	Pos CursorPosition;
	bool NextScene = false;
	void Render();
	void MainView();
	static MainScene* GetInstance();
	DoubleBuffer doubleBuffer;
};

