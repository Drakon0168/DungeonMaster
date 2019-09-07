#include "pch.h"
#include "GameManager.h"
#include "MainMenuScreen.h"
#include "GameplayScreen.h"

GameManager::GameManager()
{
	windowWidth = 800;
	windowHeight = 600;
	currentScreen = ScreenType::MainMenu;
	deltaTime = 0;
	window = nullptr;

	buttonDefaultColor = sf::Color(100, 100, 100, 255);
	buttonHoverColor = sf::Color(200, 200, 200, 255);
	buttonPressedColor = sf::Color(75, 75, 75, 255);
}

GameManager::~GameManager()
{
	for (int i = 0; i < screens->size(); i++)
	{
		delete (*screens)[i];
	}
}

GameManager* GameManager::Instance()
{
	static GameManager instance;

	return &instance;
}

void GameManager::SetupScreens()
{
	currentScreen = ScreenType::MainMenu;

	screens = shared_ptr<vector<Screen*>>(new vector<Screen*>);
	screens->push_back((Screen*) new MainMenuScreen());
	screens->push_back((Screen*) new GameplayScreen());

	Screen::window = window;
}

void GameManager::SwitchScreen(ScreenType screen)
{
	//TODO: Add screen switch animation
	currentScreen = screen;
}

void GameManager::Display()
{
	(*screens)[(int)currentScreen]->Display();
}

void GameManager::Update(float deltaTime)
{
	this->deltaTime = deltaTime;

	windowPosition = window->getPosition();
	mousePosition = sf::Mouse::getPosition(*window);

	(*screens)[(int)currentScreen]->Update();
}