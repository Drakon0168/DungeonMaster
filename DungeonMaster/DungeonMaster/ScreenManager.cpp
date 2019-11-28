#include "pch.h"
#include "ScreenManager.h"

ScreenManager* ScreenManager::instance = nullptr;

ScreenManager::ScreenManager()
{
	currentScreen = Screens::MainMenu;
	nextScreen = Screens::MainMenu;

	screens.push_back(new Screen());
	screens.push_back(new Screen());
	screens.push_back(new Screen());
}

ScreenManager::~ScreenManager()
{
	for (int i = 0; i < screens.size(); i++) {
		delete screens[i];
	}
}

ScreenManager* ScreenManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new ScreenManager();
	}

	return instance;
}

int ScreenManager::GetCurrentScreen()
{
	return currentScreen;
}

Color ScreenManager::GetClearColor()
{
	return clearColor;
}

void ScreenManager::Update(float deltaTime)
{
	screens[currentScreen]->Update(deltaTime);
}

void ScreenManager::Display()
{
	screens[currentScreen]->Display();
}

void ScreenManager::Init()
{
	for (int i = 0; i < screens.size(); i++) {
		screens[i]->Init();
	}
}

void ScreenManager::SwitchScreens(int next)
{
	nextScreen = next;
	screens[currentScreen]->FadeOut(FADE_TIME);
}

void ScreenManager::FadeIn()
{
	screens[nextScreen]->FadeIn(FADE_TIME);
	currentScreen = nextScreen;
}