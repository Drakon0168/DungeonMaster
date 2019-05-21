#include "pch.h"
#include "Tile.h"
#include "GameManager.h"
#include "Floor.h"
#include "Dungeon.h"

Tile::Tile(sf::Vector2f position)
{
	this->position = position;
	type = TileType::Open;
	sprite = std::shared_ptr<sf::Sprite>(new sf::Sprite());

	float tileSize = Dungeon::tileSize;
	textureTileSize = 32.0f;

	//sprite->setTexture(*Dungeon::tileTexture);
	//sprite->setTextureRect(sf::IntRect(textureTileSize * type, 0, textureTileSize, textureTileSize));
	//sprite->setScale(tileSize / sprite->getTextureRect().width, tileSize / sprite->getTextureRect().height);
	//sprite->setPosition(position * tileSize);
}

Tile::~Tile()
{
}

void Tile::Display()
{
	//GameManager::Instance()->window->draw(*sprite);
}

void Tile::ChangeType(TileType type)
{
	/*this->type = type;
	sprite->setTextureRect(sf::IntRect(textureTileSize * type, 0, textureTileSize, textureTileSize));*/
}
