#include "pch.h"
#include "Floor.h"

using namespace sf;

Floor::Floor(const int size)
{
	this->size = size;

	//Setup grid
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::shared_ptr<Vector2f> currentPosition = std::shared_ptr<Vector2f>(new Vector2f(i, j));
			points.push_back(currentPosition);
			tiles.insert({ *currentPosition, std::shared_ptr<Tile>(new Tile(Vector2f(i, j))) });
		}
	}
}

Floor::~Floor()
{
}

void Floor::Display() {
	for (unsigned int i = 0; i < points.size(); i++) {
		tiles[*points[i]]->Display();
	}
}

void Floor::Update() {
}