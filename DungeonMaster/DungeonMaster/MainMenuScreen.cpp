#include "pch.h"
#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
}

MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::Display()
{
	Screen::Display();

	std::cout << "Drawing the main menu Screen" << std::endl;
}

void MainMenuScreen::Update()
{
	std::cout << "Updating the Main Menu Screen" << std::endl;
}