#pragma once
#include "pch.h"
#include "Screen.h"

class ScreenManager
{
private:
	const float FADE_TIME = 0.2f;
	
	Color clearColor = Color::White;

	int currentScreen;
	int nextScreen;
	std::vector<Screen*> screens;

	static ScreenManager* instance;
public:
#pragma region Constructors
	ScreenManager();

	~ScreenManager();

	ScreenManager(const ScreenManager& other);

	ScreenManager& operator=(const ScreenManager& other);
#pragma endregion
#pragma region Singleton
	static ScreenManager* GetInstance();
#pragma endregion
#pragma region Accessors
	//Returns the current screen
	int GetCurrentScreen();
	//Returns the default background color of a screen
	Color GetClearColor();
#pragma endregion
#pragma region Update
	//Updates the current screen
	void Update(float deltaTime);
	//Displays the current screen
	void Display();
#pragma endregion
#pragma region Functions
	//Initializes all of the screens
	void Init();
	//Switches to the specified screen
	void SwitchScreens(int next);
	//Fades the next screen in
	void FadeIn();
#pragma endregion
};