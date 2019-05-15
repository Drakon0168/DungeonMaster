#include "pch.h"
#include "GameManager.h"
#include "GameplayScreen.h"
#include "Button.h"

#define gameManager GameManager::Instance()

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
	if (gameManager->mousePosition.x < cameraMoveThreshold || gameManager->mousePosition.y < cameraMoveThreshold || gameManager->mousePosition.x > gameManager->windowWidth - cameraMoveThreshold || gameManager->mousePosition.y > gameManager->windowHeight - cameraMoveThreshold) {
		//Adjust camera move speed based on the mouse's distance from the edge of the screen
		if (gameManager->mousePosition.x < distanceFromEdge) {
			distanceFromEdge = gameManager->mousePosition.x;
		}
		if (gameManager->mousePosition.y < distanceFromEdge) {
			distanceFromEdge = gameManager->mousePosition.y;
		}
		if (gameManager->windowWidth - gameManager->mousePosition.x < distanceFromEdge) {
			distanceFromEdge = gameManager->windowWidth - gameManager->mousePosition.x;
		}
		if (gameManager->windowHeight - gameManager->mousePosition.y < distanceFromEdge) {
			distanceFromEdge = gameManager->windowHeight - gameManager->mousePosition.y;
		}

		if (distanceFromEdge < 0) {
			distanceFromEdge = 0;
		}

		distanceFromEdge = cameraMoveThreshold - distanceFromEdge;

		cameraDirection = Vector2f(gameManager->mousePosition.x - (gameManager->windowWidth / 2), gameManager->mousePosition.y - (gameManager->windowWidth / 2));
		cameraDirection *= 1 / sqrt(cameraDirection.x * cameraDirection.x + cameraDirection.y * cameraDirection.y);
	}

	//Get the mouse position in the game world and floor to the nearest int
	Vector2f mousePosition = Vector2f(gameManager->mousePosition.x, gameManager->mousePosition.y) + Vector2f(DefaultView->getCenter().x, DefaultView->getCenter().y) - Vector2f(gameManager->windowWidth / 2, gameManager->windowHeight / 2);
	mousePosition /= Dungeon::tileSize;
	mousePosition = Vector2f(floorf(mousePosition.x), floorf(mousePosition.y));

	//TODO: Do something with the currently hovered over tile
	shared_ptr<Tile> currentTile = dungeon->getCurrentFloor()->ContainsPoint(mousePosition);
	if (currentTile != nullptr) {
		currentTile->ChangeType(TileType::Wall);
	}

	DefaultView->move(cameraDirection * cameraMaxSpeed * (distanceFromEdge / cameraMoveThreshold) * GameManager::Instance()->deltaTime);
}