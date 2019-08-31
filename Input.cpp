#include "pch.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

Input * Input::GetInstance()
{
	static Input i;
	return &i;
}

void Input::InputDown()
{
	if (_kbhit()) {
		int key = _getch();
		switch (key)
		{
		case 75:
			if(FWPLAYER->move != RIGHT)
			FWPLAYER->move = LEFT;
			break;
		case 77:
			if (FWPLAYER->move != LEFT)
			FWPLAYER->move = RIGHT;
			break;
		case 72:
			if (FWPLAYER->move != DOWN)
			FWPLAYER->move = UP;
			break;
		case 80:
			if (FWPLAYER->move != UP)
			FWPLAYER->move = DOWN;
			break;
		default:
			break;
		}
	}
}


