#pragma once

#include "pch.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Tile.h"

class Floor : public IDrawable, public IUpdatable
{
public:
	//The width of the floor in tiles
	int size;
	//TODO: Figure out how to store tiles in a map based on their position
	//The collection of all of the tiles on the floor
	std::vector<std::shared_ptr<Tile>> tiles;

	Floor(int size);
	~Floor();

	void Display();
	void Update();
};