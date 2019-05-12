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

	float tileSize = 32.0f;

	//TODO: load the texture in the game manager or some other singleton and share it between all of the tiles
	texture->loadFromFile("Textures\\Square64x64.png");
	sprite->setTexture(*texture);
	sprite->setScale(tileSize / texture->getSize().x, tileSize / texture->getSize().y);
	sprite->setPosition(position * tileSize);// (float)texture->getSize().x);
}

Tile::~Tile()
{
}

void Tile::Display()
{
	GameManager::Instance()->window->draw(*sprite);
}
