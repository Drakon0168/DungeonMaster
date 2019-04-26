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
	RenderWindow* window;

	~GameManager();

	static GameManager* Instance();

	//Sets the screens vector 
	void SetupScreens();

	//Calls the Display method of the screen that is currently active
	void Display();
	//Calls the Update method of the screen that is currently active
	void Update();
private:
	GameManager();
	shared_ptr<vector<Screen*>> screens;
	ScreenType currentScreen;
};