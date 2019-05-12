#pragma once

#include "pch.h"
#include "Screen.h"

#include "Floor.h"

class GameplayScreen : public Screen
{
public:
	GameplayScreen();
	~GameplayScreen();

	void Update();

	//Placeholder for testing
	shared_ptr<Floor> floor;
private:
	//The speed to move the camera in pixes per second
	float cameraSpeed;
	//The distance that the mouse needs to be from the edge of the screen to move the camera in pixels
	float cameraMoveThreshold;
};

