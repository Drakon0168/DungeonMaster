#include "pch.h"
#include "Tile.h"
#include "GameManager.h"
#include "Floor.h"

Tile::Tile(sf::Vector2f position)
{
	this->position = position;
	type = TileType::Wall;
	texture = std::shared_ptr<sf::Texture>(new sf::Texture());
	sprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());

	texture->loadFromFile("Textures\\Square64x64.png");
	sprite->setTexture(*texture);
	sprite->setPosition(position * (float)texture->getSize().x);
}

Tile::~Tile()
{
}

void Tile::Display()
{
	GameManager::Instance()->window->draw(*sprite);
}
