#pragma once
#include "Screen.h"

using namespace std;

enum ScreenType {
	MainMenu,
	Gameplay,
};

class GameManager
{
public:
	int windowWidth;
	int windowHeight;
	float deltaTime;
	sf::RenderWindow* window;

	~GameManager();

	static GameManager* Instance();

	//Sets the screens vector 
	void SetupScreens();
	//Switches to the specified screen
	void SwitchScreen(ScreenType screen);

	//Calls the Display method of the screen that is currently active
	void Display();
	//Calls the Update method of the screen that is currently active
	void Update(float deltaTime);

	//Global Variables
	sf::Color buttonDefaultColor;
	sf::Color buttonHoverColor;
	sf::Color buttonPressedColor;
	int defaultTextSize = 24;

	//The position of the window on the screen
	sf::Vector2i windowPosition;
	//The mouse position on the window
	sf::Vector2i mousePosition;
private:
	GameManager();
	shared_ptr<vector<Screen*>> screens;
	ScreenType currentScreen;
};