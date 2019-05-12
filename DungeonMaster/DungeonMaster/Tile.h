#pragma once

#include "pch.h"
#include "IDrawable.h"

enum TileType {
	Wall,
	Open
};

class Tile : public IDrawable
{
public:
	TileType type;
	sf::Vector2f position;

	Tile(sf::Vector2f position);
	~Tile();

	void Display();
	
	void ChangeType(TileType type);

private:
	std::shared_ptr<sf::Sprite> sprite;
	float textureTileSize;
};

