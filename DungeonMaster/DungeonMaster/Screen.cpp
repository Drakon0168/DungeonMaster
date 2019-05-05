#include "pch.h"
#include "Screen.h"
#include "GameManager.h"

Screen::Screen()
{
	background = new sf::RectangleShape(sf::Vector2f(GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight));
}

Screen::~Screen()
{
	
}

void Screen::Display()
{
	GameManager::Instance()->window->draw(*background);

	for (int i = 0; i < drawableObjects.size(); i++) {
		drawableObjects[i]->Display();
	}
}

void Screen::Update()
{
	for (int i = 0; i < updatableObjects.size(); i++)
	{
		updatableObjects[i]->Update();
	}
}

void Screen::closeGame()
{
	exit(0);
}
