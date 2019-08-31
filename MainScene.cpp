#include "pch.h"
#include "MainScene.h"


MainScene::MainScene()
{
	doubleBuffer.CreateBuffer(1280, 720);
}


MainScene::~MainScene()
{
	doubleBuffer.DestoryBuffer();
}

void MainScene::Render()
{
	NextScene = false;
	while (!NextScene) {
		doubleBuffer.ClearBuffer();
		MainView();
		doubleBuffer.FlippingBuffer();
	}
}

void MainScene::MainView()
{
	doubleBuffer.WriteBuffer(12, 10,"시작하려면 1,2,3 중 하나를 입력해주세요");
	doubleBuffer.WriteBuffer(12, 12, "1 : LV 1 | 2 : LV 2 | 3 : LV 3");
	doubleBuffer.WriteBuffer(12, 14, "종료하려면 Q 키를 눌러주세요");
	if (_kbhit())
	{
		int i = _getch();
		if (i == 'Q' || i == 'q') {
			exit(0);
		}
		else if (i == 49)
		{
			FWSCENE->First = true;
			FWSCENE->Second = false;
			FWSCENE->three = false;

			NextScene = true;
		}
		else if (i == 50)
		{
			FWSCENE->First = false;
			FWSCENE->Second = true;
			FWSCENE->three = false;

			NextScene = true;
		}
		else if (i == 51)
		{
			FWSCENE->First = false;
			FWSCENE->Second = false;
			FWSCENE->three = true;

			NextScene = true;
		}
	}
}

MainScene * MainScene::GetInstance()
{
	static MainScene i;
	return &i;
}
