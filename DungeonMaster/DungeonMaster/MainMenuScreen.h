#pragma once
#include "Screen.h"

class MainMenuScreen : Screen
{
public:
	MainMenuScreen();
	~MainMenuScreen();

	//Draws all sprites for the screen
	void Display();
	//Updates all of the objects for the screen
	void Update();
};