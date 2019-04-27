#include "pch.h"
#include "MainMenuScreen.h"
#include "Button.h"

MainMenuScreen::MainMenuScreen()
{
	Screen::Screen();

	Button* playButton = new Button();

	drawableObjects->push_back((IDrawable*)playButton);
	updatableObjects->push_back((IUpdatable*)playButton);
}

MainMenuScreen::~MainMenuScreen()
{
	Screen::~Screen();
}