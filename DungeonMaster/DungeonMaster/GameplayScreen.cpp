#include "pch.h"
#include "GameManager.h"
#include "GameplayScreen.h"
#include "Button.h"

GameplayScreen::GameplayScreen()
{
	Screen::Screen();

	//	Create Exit Button
	shared_ptr<Button> exitButton = shared_ptr<Button>(new Button(Vector2f(30, 30), Vector2f(50, 50), Vector2f(0,0), "Exit"));
	drawableObjects.push_back((shared_ptr<IDrawable>)exitButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)exitButton);
	exitButton->OnClick = closeGame;

	floor = shared_ptr<Floor>(new Floor(10));
	drawableObjects.push_back((shared_ptr<IDrawable>)floor);
	updatableObjects.push_back((shared_ptr<IUpdatable>)floor);
}

GameplayScreen::~GameplayScreen()
{
}
