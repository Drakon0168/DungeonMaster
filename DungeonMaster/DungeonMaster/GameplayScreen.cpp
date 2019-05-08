#include "pch.h"
#include "GameManager.h"
#include "GameplayScreen.h"
#include "Button.h"

GameplayScreen::GameplayScreen()
{
	Screen::Screen();

	//	Create Exit Button
	shared_ptr<Button> exitButton = shared_ptr<Button>(new Button(Vector2f(30, 30), Vector2f(50, 50), Vector2f(0,0)));
	drawableObjects.push_back((shared_ptr<IDrawable>)exitButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)exitButton);
	exitButton->OnClick = closeGame;

	//Setup the dungeon
	tile = shared_ptr<Tile>(new Tile());
	drawableObjects.push_back((shared_ptr<IDrawable>)tile);
}

GameplayScreen::~GameplayScreen()
{
}
