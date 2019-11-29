#include "pch.h"

Input::Input()
{
	currentState = InputState::Up;
	lastState = InputState::Up;
	keyCode = Controls::InputCode::Select;
	inputType = InputType::Mouse;
}

Input::Input(int inputType, int keyCode)
{
	this->inputType = inputType;
	this->keyCode = keyCode;
}

void Input::Update()
{
	lastState = currentState;

	switch (inputType) {
	case InputType::Keyboard:
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keyCode)) {
			if (lastState == InputState::Up) {
				currentState = InputState::Pressed;
			}
			else {
				currentState = InputState::Down;
			}
		}
		else {
			if (lastState == InputState::Down) {
				currentState = InputState::Released;
			}
			else {
				currentState = InputState::Up;
			}
		}
		break;
	case InputType::Mouse:
		if (sf::Mouse::isButtonPressed((sf::Mouse::Button)keyCode)) {
			if (lastState == InputState::Up) {
				currentState = InputState::Pressed;
			}
			else {
				currentState = InputState::Down;
			}
		}
		else {
			if (lastState == InputState::Down) {
				currentState = InputState::Released;
			}
			else {
				currentState = InputState::Up;
			}
		}
		break;
	}

	std::cout << "Control: " << keyCode << ", State: " << currentState << std::endl;
}