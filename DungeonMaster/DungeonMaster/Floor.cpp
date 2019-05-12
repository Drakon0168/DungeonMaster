#include "pch.h"
#include "Floor.h"

using namespace sf;

Floor::Floor(const int size)
{
	this->size = size;

	//Setup grid
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tiles.push_back(std::shared_ptr<Tile>(new Tile(Vector2f(i,j))));
		}
	}
}

Floor::~Floor()
{
}

void Floor::Display() {
	for (unsigned int i = 0; i < tiles.size(); i++) {
		tiles[i]->Display();
	}
}

void Floor::Update() {
}