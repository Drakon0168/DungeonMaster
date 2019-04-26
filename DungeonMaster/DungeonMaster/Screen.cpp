#include "pch.h"
#include "Screen.h"
#include "GameManager.h"

Screen::Screen()
{
	background = new RectangleShape(Vector2f(GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight));
}

Screen::~Screen()
{
}

void Screen::Display()
{
	GameManager::Instance()->window->draw(*background);
	std::cout << "Screen is Drawing" << std::endl;
}