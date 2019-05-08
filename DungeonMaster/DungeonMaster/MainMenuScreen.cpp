#include "pch.h"
#include "GameManager.h"
#include "MainMenuScreen.h"
#include "Button.h"

MainMenuScreen::MainMenuScreen()
{
	Screen::Screen();

	//Create Buttons
	//	Create Play Button
	shared_ptr<Button> playButton = shared_ptr<Button>(new Button(Vector2f(0, -30), Vector2f(200,50)));
	drawableObjects.push_back((shared_ptr<IDrawable>)playButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)playButton);
	playButton->OnClick = PlayClicked;

	//	Create Exit Button
	shared_ptr<Button> exitButton = shared_ptr<Button>(new Button(Vector2f(0, 30), Vector2f(200, 50)));
	drawableObjects.push_back((shared_ptr<IDrawable>)exitButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)exitButton);
	exitButton->OnClick = closeGame;
}

MainMenuScreen::~MainMenuScreen()
{
	Screen::~Screen();
}

void MainMenuScreen::PlayClicked()
{
	GameManager::Instance()->SwitchScreen(ScreenType::Gameplay);
}
