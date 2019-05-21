#include "pch.h"
#include "InputManager.h"
#include "Input.h"

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