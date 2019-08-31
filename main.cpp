#include "pch.h"
#include "GameScene.h"
#include "Input.h"
#include "Snake.h"
#include "MainScene.h"
int main()
{
	back:
	MISCENE->Render();
	FWPLAYER->InitSnake();
	while (true) {
		FWINPUT->InputDown();
		if (!FWPLAYER->Update())
			goto back;
		FWSCENE->Render();
		Sleep(1000/FWPLAYER->SleepPoint);
	}
}