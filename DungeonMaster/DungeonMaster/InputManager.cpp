#include "pch.h"
#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

InputManager* InputManager::Instance()
{
	static InputManager instance;

	return &instance;
}

void InputManager::SetupInputs()
{
	Inputs.insert(pair<Controls, shared_ptr<Input<int>>>(Controls::LeftClick, shared_ptr<Input<int>>((Input<int>*)new Input<sf::Mouse::Button>(sf::Mouse::isButtonPressed, sf::Mouse::Button::Left))));
}

void InputManager::Update()
{
	for (pair<Controls, shared_ptr<Input<int>>> p : Inputs) {
		p.second->Update();
	}
}

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