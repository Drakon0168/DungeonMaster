#include "pch.h"
#include "Tile.h"
#include "GameManager.h"

using namespace sf;

Tile::Tile()
{
	position = Vector2f(500, 500);
	type = TileType::Wall;
	texture = std::shared_ptr<Texture>(new Texture());
	sprite = std::shared_ptr<Sprite>(new Sprite());

	texture->loadFromFile("Textures\\Square64x64.png");
	sprite->setTexture(*texture);
	sprite->setPosition(position);
}

Tile::~Tile()
{
}

void Tile::Display()
{
	GameManager::Instance()->window->draw(*sprite);
}
