#pragma once

#include "pch.h"
#include "IDrawable.h"

enum TileType {
	Open,
	Wall
};

class Tile : public IDrawable
{
public:
	TileType type;
	sf::Vector2f position;

	Tile(sf::Vector2f position);
	~Tile();

	void Display();

private:
	std::shared_ptr<sf::Sprite> sprite;
	std::shared_ptr<sf::Texture> texture;
};

