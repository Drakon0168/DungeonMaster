#include "pch.h"
#include "Dungeon.h"

float Dungeon::tileSize = 32.0f;
shared_ptr<sf::Texture> Dungeon::tileTexture = shared_ptr<sf::Texture>(nullptr);

Dungeon::Dungeon(Screen* screen, int floorCount)
{
	this->screen = screen;
	this->floorCount = floorCount;
	currentFloor = 0;
	floorSize = 25;

	tileTexture = shared_ptr<sf::Texture>(new sf::Texture());
	tileTexture->loadFromFile("Textures\\TileTexture.png");

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

shared_ptr<Floor> Dungeon::getCurrentFloor()
{
	return floors[currentFloor];
}