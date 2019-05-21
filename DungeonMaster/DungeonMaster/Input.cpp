#include "pch.h"
#include "Input.h"

template<class T>
Input<T>::Input(bool(*GetState)(T), T enumValue)
{
	this->GetState = GetState;
	this->enumValue = enumValue;

	state = InputState::Up;
	previousState = false;
}

template<class T>
void Input<T>::Update()
{
	//Set state
	if (GetState != nullptr) {
		if (GetState(enumValue)) {
			if (previousState) {
				state = InputState::Down;
			}
			else {
				state = InputState::Pressed;
			}
		}
		else {
			if (previousState) {
				state = InputState::Released;
			}
			else {
				state = InputState::Up;
			}
		}
	}
	else {
		state = InputState::Up;
	}

	//Update previous state
	if (state == InputState::Pressed || state == InputState::Down) {
		previousState = true;
	}
	else {
		previousState = false;
	}
}