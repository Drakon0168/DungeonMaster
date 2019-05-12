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
	//The size of a tile in pixels
	int tileSize;
	//The collection of all of the tiles on the floor
	std::vector<std::shared_ptr<Tile>> tiles;

	Floor(int size);
	~Floor();

	void Display();
	void Update();
};