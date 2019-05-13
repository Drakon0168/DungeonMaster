#include "pch.h"
#include "Floor.h"

using namespace sf;

Floor::Floor(const int size)
{
	this->size = size;

	//Setup grid
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tiles.insert(std::pair<Vector2f, std::shared_ptr<Tile>>(Vector2f(i,j), std::shared_ptr<Tile>(new Tile(Vector2f(i,j)))));
		}
	}
}

Floor::~Floor()
{
}

void Floor::Display() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tiles[Vector2f(i,j)]->Display();
		}
	}
}

void Floor::Update() {
}