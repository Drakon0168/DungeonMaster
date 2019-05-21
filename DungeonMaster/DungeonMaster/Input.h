#pragma once

#include "pch.h"

using namespace std;

//Enum for storing the current state of a key Pressed and Released are true on the first frame held or released
enum InputState {
	Pressed,
	Released,
	Down,
	Up
};

template<class T>
struct Input {
public:
	InputState state;
	T enumValue;
	bool(*GetState)(T);
	Input(bool(*GetState)(T), T enumValue);

	void Update();
private:
	bool previousState;
};

