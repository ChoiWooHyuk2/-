#pragma once
#include "pch.h"
#include "Snake.h"
#define FWINPUT Input::GetInstance()
class Input
{
public:
	Input();
	~Input();
public:
	void InputDown();
	static Input* GetInstance();

};

