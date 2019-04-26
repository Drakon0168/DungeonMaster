#include "pch.h"
#include "GameManager.h"
#include "MainMenuScreen.h"

GameManager::GameManager()
{
	windowWidth = 800;
	windowHeight = 600;
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
}

void GameManager::Display()
{
	(*screens)[(int)currentScreen]->Display();
}

void GameManager::Update()
{
	(*screens)[(int)currentScreen]->Update();
}