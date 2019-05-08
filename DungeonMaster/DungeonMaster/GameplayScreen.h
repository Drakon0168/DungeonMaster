#pragma once

#include "pch.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Screen.h"

#include "Tile.h"

class GameplayScreen : public Screen
{
public:
	GameplayScreen();
	~GameplayScreen();

	//Placeholder for testing
	shared_ptr<Tile> tile;
};

