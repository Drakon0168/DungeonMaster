#pragma once

#include "pch.h"
#include "IDrawable.h"

using namespace sf;

enum TileType {
	Floor,
	Wall
};

class Tile : public IDrawable
{
public:
	TileType type;
	Vector2f position;

	Tile();
	~Tile();

	void Display();

private:
	shared_ptr<Sprite> sprite;
	shared_ptr<Texture> texture;
};

