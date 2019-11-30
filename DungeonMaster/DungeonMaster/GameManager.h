#pragma once
#include "pch.h";

using namespace sf;

class GameManager
{
private:
	const Vector2i DEFAULT_SCREEN_SIZE = Vector2i(1024, 768);

	Clock clock;
	float deltaTime = 0;
	float lastTime = 0;

	RenderWindow* window;

	static GameManager* instance;
public:
#pragma region Constructors
	GameManager();

	~GameManager();

	GameManager(const GameManager& other);

	GameManager& operator=(const GameManager& other);
#pragma endregion
#pragma region Singleton
	static GameManager* GetInstance();
#pragma endregion
#pragma region Accessors
	//Returns the size of the window in pixels
	Vector2i GetScreenSize();
	//Returns a pointer to the current render window
	RenderWindow* GetRenderWindow();
#pragma endregion
#pragma region Update
	//Updates all other manager classes
	void Update();
	//Displays all other displayable classes
	void Display();
#pragma endregion
#pragma region Functions
	//Initializes the other managers
	void Init();
	//Starts the update loop
	void StartLoop();
	//Closes the game and deallocates memory
	void CloseGame();
#pragma endregion
};

