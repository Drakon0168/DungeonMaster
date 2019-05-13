#pragma once

#include "pch.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Vector2fComparer.h"
#include "Tile.h"

class Floor : public IDrawable, public IUpdatable
{
public:
	//The width of the floor in tiles
	int size;
	//The collection of all of the tiles on the floor
	std::map<sf::Vector2f, std::shared_ptr<Tile>, Vector2fComparer> tiles;

	Floor(int size);
	~Floor();

	void Display();
	void Update();
};