#include "pch.h"
#include "MainMenuScreen.h"
#include "Button.h"

MainMenuScreen::MainMenuScreen()
{
	Screen::Screen();

	//Create Buttons
	//	Create Play Button
	shared_ptr<Button> playButton = shared_ptr<Button>(new Button());
	drawableObjects.push_back((shared_ptr<IDrawable>)playButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)playButton);

	//	Create Exit Button
	shared_ptr<Button> exitButton = shared_ptr<Button>(new Button());
	drawableObjects.push_back((shared_ptr<IDrawable>)exitButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)exitButton);
	exitButton->OnClick = closeGame;
}

MainMenuScreen::~MainMenuScreen()
{
	Screen::~Screen();
}