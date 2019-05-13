#include "pch.h"
#include "GameManager.h"
#include "GameplayScreen.h"
#include "Button.h"

#define mousePosition GameManager::Instance()->mousePosition
#define windowWidth GameManager::Instance()->windowWidth
#define windowHeight GameManager::Instance()->windowHeight

GameplayScreen::GameplayScreen()
{
	Screen::Screen();

	//Setup Camera
	cameraMaxSpeed = 200.0f;
	cameraMoveThreshold = 150;

	//	Create Exit Button
	shared_ptr<Button> exitButton = shared_ptr<Button>(new Button(Vector2f(30, 30), Vector2f(50, 50), Vector2f(0,0), "Exit"));
	UIObjects.push_back(exitButton);
	updatableObjects.push_back(exitButton);
	exitButton->OnClick = closeGame;

	dungeon = shared_ptr<Dungeon>(new Dungeon(this, 5));
	drawableObjects.push_back((shared_ptr<IDrawable>)dungeon);
	updatableObjects.push_back((shared_ptr<IUpdatable>)dungeon);
}

GameplayScreen::~GameplayScreen()
{

}

void GameplayScreen::Update()
{
	Screen::Update();

	//TODO: Middle mouse drag camera movement

	Vector2f cameraDirection = Vector2f(0, 0);

	//Check if the mouse is on the edge of the window and if it is set the camera direction
	float distanceFromEdge = cameraMoveThreshold;
	if (mousePosition.x < cameraMoveThreshold || mousePosition.y < cameraMoveThreshold || mousePosition.x > windowWidth - cameraMoveThreshold || mousePosition.y > windowHeight - cameraMoveThreshold) {
		//Adjust camera move speed based on the mouse's distance from the edge of the screen
		if (mousePosition.x < distanceFromEdge) {
			distanceFromEdge = mousePosition.x;
		}
		if (mousePosition.y < distanceFromEdge) {
			distanceFromEdge = mousePosition.y;
		}
		if (windowWidth - mousePosition.x < distanceFromEdge) {
			distanceFromEdge = windowWidth - mousePosition.x;
		}
		if (windowHeight - mousePosition.y < distanceFromEdge) {
			distanceFromEdge = windowHeight - mousePosition.y;
		}

		if (distanceFromEdge < 0) {
			distanceFromEdge = 0;
		}

		distanceFromEdge = cameraMoveThreshold - distanceFromEdge;

		cameraDirection = Vector2f(mousePosition.x - (windowWidth / 2), mousePosition.y - (windowWidth / 2));
		cameraDirection *= 1 / sqrt(cameraDirection.x * cameraDirection.x + cameraDirection.y * cameraDirection.y);
	}

	DefaultView->move(cameraDirection * cameraMaxSpeed * (distanceFromEdge / cameraMoveThreshold) * GameManager::Instance()->deltaTime);
}