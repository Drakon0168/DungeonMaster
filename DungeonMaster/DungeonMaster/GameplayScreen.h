#pragma once

#include "pch.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Screen.h"

#include "Floor.h"

class GameplayScreen : public Screen
{
public:
	GameplayScreen();
	~GameplayScreen();

	//Placeholder for testing
	shared_ptr<Floor> floor;
};

