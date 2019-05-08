#pragma once

#include "pch.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Screen.h"

class MainMenuScreen : public Screen
{
public:
	MainMenuScreen();
	~MainMenuScreen();

	static void PlayClicked();
};