#pragma once

#include "pch.h"

class GameManager
{
private:
	static std::shared_ptr<GameManager> instance;
	std::shared_ptr<sf::RenderWindow> window;
	int windowWidth = 800;
	int windowHeight = 600;
public:
#pragma region Constructor
	GameManager();
	~GameManager();
#pragma endregion

#pragma region Accessors
	static std::shared_ptr<GameManager> GetInstance();

	std::shared_ptr<sf::RenderWindow> GetWindow();
	void SetWindow(std::shared_ptr<sf::RenderWindow> value);
	int GetWindowWidth();
	int GetWindowHeight();
#pragma endregion

#pragma region GameManager
	void Update(float deltaTime);
	void Draw();
#pragma endregion

#pragma region Screen Management
	void SetupScreens();
#pragma endregion
};