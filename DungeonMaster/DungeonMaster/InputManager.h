#pragma once
#include "pch.h"

class InputManager
{
private:
	std::map<int, Input> inputs;

	InputManager* instance;
public:
#pragma region Constructor
	InputManager();

	~InputManager();

	InputManager(const InputManager& other);

	InputManager& operator=(const InputManager& other);
#pragma endregion
#pragma region Singleton
	InputManager* GetInstance();
#pragma endregion
#pragma region Accessors
	std::map<int, Input> GetInputs();
#pragma endregion
#pragma region Update
	void Update();
#pragma endregion
#pragma region Functions
	void Init();
#pragma endregion
};