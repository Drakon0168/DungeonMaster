#pragma once

#include "pch.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Floor.h"
#include "Screen.h"

using namespace std;

class Dungeon : public IDrawable, public IUpdatable
{
public:
	vector<shared_ptr<Floor>> floors;
	Screen* screen;
	int currentFloor;
	int floorSize;
	int floorCount;

	static float tileSize;
	static shared_ptr<sf::Texture> tileTexture;

	Dungeon(Screen* screen, int floorCount);
	~Dungeon();

	void Display();
	void Update();
};