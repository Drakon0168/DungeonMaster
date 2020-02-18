#pragma once

#include "pch.h"

class GameManager
{
private:
	static GameManager* instance;
public:
#pragma region Constructor
	GameManager();
	~GameManager();
#pragma endregion

#pragma region Accessors
	static GameManager* GetInstance();
#pragma endregion
};