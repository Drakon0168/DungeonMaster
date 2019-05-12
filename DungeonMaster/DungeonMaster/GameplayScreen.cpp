#include "pch.h"
#include "GameManager.h"
#include "GameplayScreen.h"
#include "Button.h"

#define mousePosition GameManager::Instance()->mousePosition

GameplayScreen::GameplayScreen()
{
	Screen::Screen();

	//Setup Camera
	cameraSpeed = 100.0f;
	cameraMoveThreshold = 100;

	//	Create Exit Button
	shared_ptr<Button> exitButton = shared_ptr<Button>(new Button(Vector2f(30, 30), Vector2f(50, 50), Vector2f(0,0), "Exit"));
	UIObjects.push_back((shared_ptr<IDrawable>)exitButton);
	updatableObjects.push_back((shared_ptr<IUpdatable>)exitButton);
	exitButton->OnClick = closeGame;

	floor = shared_ptr<Floor>(new Floor(25));
	drawableObjects.push_back((shared_ptr<IDrawable>)floor);
	updatableObjects.push_back((shared_ptr<IUpdatable>)floor);
}

GameplayScreen::~GameplayScreen()
{

}

void GameplayScreen::Update()
{
	Screen::Update();

	//TODO: Middle mouse drag camera movement

	Vector2f cameraMovement = Vector2f(0, 0);

	//TODO: Move more accurately based on the angle between the mouse position and the center of the screen rather than 8 directionally
	if (mousePosition.x < cameraMoveThreshold) {
		cameraMovement.x -= cameraSpeed;
	}
	if (mousePosition.y < cameraMoveThreshold) {
		cameraMovement.y -= cameraSpeed;
	}
	if (mousePosition.x > GameManager::Instance()->windowWidth - cameraMoveThreshold) {
		cameraMovement.x += cameraSpeed;
	}
	if (mousePosition.y > GameManager::Instance()->windowHeight - cameraMoveThreshold) {
		cameraMovement.y += cameraSpeed;
	}

	DefaultView->move(cameraMovement * GameManager::Instance()->deltaTime);
}
