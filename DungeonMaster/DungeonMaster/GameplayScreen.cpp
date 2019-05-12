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
	cameraMoveThreshold = 150;

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

	Vector2f cameraDirection = Vector2f(0, 0);

	//TODO: Ease in and out of camera motion
	if (mousePosition.x < cameraMoveThreshold || mousePosition.y < cameraMoveThreshold || mousePosition.x > GameManager::Instance()->windowWidth - cameraMoveThreshold || mousePosition.y > GameManager::Instance()->windowHeight - cameraMoveThreshold) {
		cameraDirection = Vector2f(mousePosition.x - (GameManager::Instance()->windowWidth / 2), mousePosition.y - (GameManager::Instance()->windowWidth / 2));
		cameraDirection *= 1 / sqrt(cameraDirection.x * cameraDirection.x + cameraDirection.y * cameraDirection.y);
	}

	DefaultView->move(cameraDirection * cameraSpeed * GameManager::Instance()->deltaTime);
}
