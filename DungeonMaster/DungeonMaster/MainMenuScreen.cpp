#include "pch.h"
#include "MainMenuScreen.h"
#include "Button.h"

MainMenuScreen::MainMenuScreen()
{
	Screen::Screen();

	shared_ptr<Button> playButton = shared_ptr<Button>(new Button());

	drawableObjects.push_back((shared_ptr<IDrawable>)playButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)playButton);

	playButton->OnClick = closeGame;
}

MainMenuScreen::~MainMenuScreen()
{
	Screen::~Screen();
}