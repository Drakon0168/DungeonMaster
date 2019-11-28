#pragma once
#include "pch.h"

struct Input {
public:
	int currentState;
	int lastState;
	int keyCode;
	int inputType;

	Input(int inputType, int keyCode);

	void Update();
};