#pragma once
#include "pch.h"

struct Input {
public:
	int currentState = InputState::Up;
	int lastState = InputState::Up;
	int keyCode = Controls::InputCode::Select;
	int inputType = InputType::Mouse;

	Input();

	Input(int inputType, int keyCode);

	void Update();
};