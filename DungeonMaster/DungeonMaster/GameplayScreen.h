#pragma once

#include "pch.h"
#include "Screen.h"

#include "Dungeon.h"

class GameplayScreen : public Screen
{
public:
	GameplayScreen();
	~GameplayScreen();

	void Update();
private:
	//The speed to move the camera in pixes per second
	float cameraSpeed;
	//The distance that the mouse needs to be from the edge of the screen to move the camera in pixels
	float cameraMoveThreshold;

	//The player's dungeon, stores all information about the dungeon
	shared_ptr<Dungeon> dungeon;
};

