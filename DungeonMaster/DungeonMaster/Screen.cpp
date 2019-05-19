#include "pch.h"
#include "Screen.h"
#include "GameManager.h"

shared_ptr<sf::Font> Screen::buttonFont = nullptr;

Screen::Screen()
{
	background = new sf::RectangleShape(sf::Vector2f(GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight));
	UIView = shared_ptr<sf::View>(new sf::View(sf::FloatRect(0, 0, GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight)));
	DefaultView = shared_ptr<sf::View>(new sf::View(sf::FloatRect(0, 0, GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight)));

	if (buttonFont == nullptr) {
		buttonFont = shared_ptr<sf::Font>(new sf::Font());
		buttonFont->loadFromFile("Fonts\\TestFont.ttf");
	}
}

Screen::~Screen()
{

}

void Screen::Display()
{
	GameManager::Instance()->window->setView(*UIView);
	GameManager::Instance()->window->draw(*background);

	GameManager::Instance()->window->setView(*DefaultView);
	for (int i = 0; i < drawableObjects.size(); i++) {
		drawableObjects[i]->Display();
	}

	GameManager::Instance()->window->setView(*UIView);
	for (int i = 0; i < UIObjects.size(); i++) {
		UIObjects[i]->Display();
	}
}

void Screen::Update()
{
	for (int i = 0; i < updatableObjects.size(); i++) {
		updatableObjects[i]->Update();
	}
}

void Screen::closeGame()
{
	exit(0);
}
