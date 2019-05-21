#include "pch.h"
#include "InputManager.h"

//map<Controls, shared_ptr<Input<int>>> InputManager::Inputs;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::SetupInputs()
{
	//Inputs.insert(pair<Controls, shared_ptr<Input<int>>>(Controls::LeftClick, shared_ptr<Input<int>>((Input<int>*)new Input<sf::Mouse::Button>(sf::Mouse::isButtonPressed, sf::Mouse::Button::Left))));
}

void InputManager::Update()
{
	/*for (pair<Controls, shared_ptr<Input<int>>> p : Inputs) {
		p.second->Update();
	}*/
}