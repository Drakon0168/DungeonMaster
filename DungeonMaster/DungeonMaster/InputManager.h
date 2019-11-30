#pragma once
#include "pch.h"

class InputManager
{
private:
	std::map<int, Input*> inputs;
	Vector2i globalMousePosition; //Position of the mouse in relation to the screen
	Vector2i windowMousePosition; //Position of the mouse in relation to the window

	static InputManager* instance;
public:
#pragma region Constructor
	InputManager();

	~InputManager();

	InputManager(const InputManager& other);

	InputManager& operator=(const InputManager& other);
#pragma endregion
#pragma region Singleton
	static InputManager* GetInstance();
#pragma endregion
#pragma region Accessors
	std::map<int, Input*> GetInputs();
#pragma endregion
#pragma region Update
	//Updates the current state of all inputs
	void Update();
#pragma endregion
#pragma region Functions
	//Sets up the key map
	void Init();
	//Returns the state of the requested input
	int GetInput(int inputCode);
#pragma endregion
};