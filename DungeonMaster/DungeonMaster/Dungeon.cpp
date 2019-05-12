#include "pch.h"
#include "Dungeon.h"


Dungeon::Dungeon(Screen* screen, int floorCount)
{
	this->screen = screen;
	this->floorCount = floorCount;
	currentFloor = 0;
	floorSize = 25;

	for (int i = 0; i < floorCount; i++) {
		floors.push_back(shared_ptr<Floor>(new Floor(floorSize)));
		screen->drawableObjects.push_back(floors[i]);
		screen->updatableObjects.push_back(floors[i]);
	}
}


Dungeon::~Dungeon()
{
}

void Dungeon::Display()
{
	floors[currentFloor]->Display();
}

void Dungeon::Update()
{
	floors[currentFloor]->Update();
}