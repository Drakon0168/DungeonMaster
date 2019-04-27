#include "pch.h"
#include "Screen.h"
#include "GameManager.h"

Screen::Screen()
{
	background = new sf::RectangleShape(sf::Vector2f(GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight));
}

Screen::~Screen()
{
	for (int i = 0; i < drawableObjects->size(); i++)
	{
		if ((*drawableObjects)[i] != nullptr) {
			delete (*drawableObjects)[i];
			(*drawableObjects)[i] = nullptr;
		}
	}

	for (int i = 0; i < updatableObjects->size(); i++)
	{
		if ((*updatableObjects)[i] != nullptr) {
			delete (*updatableObjects)[i];
			(*updatableObjects)[i] = nullptr;
		}
	}
}

void Screen::Display()
{
	GameManager::Instance()->window->draw(*background);
	std::cout << "Screen is Drawing" << std::endl;

	for (int i = 0; i < drawableObjects->size(); i++) {
		(*drawableObjects)[i]->Display();
	}
}

void Screen::Update()
{
	for (int i = 0; i < updatableObjects->size(); i++)
	{
		(*updatableObjects)[i]->Update();
	}
}
