#pragma once

#include "pch.h"
#include "Input.h"

using namespace std;

//A list of all of the controls that are available for the game
enum Controls {
	LeftClick
};

class InputManager
{
public:
	//static map<Controls, shared_ptr<Input<int>>> Inputs;

	InputManager();
	~InputManager();

	static void SetupInputs();
	static void Update();
};

