#include "pch.h"
#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

InputManager* InputManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new InputManager();
	}

	return instance;
}

std::map<int, Input> InputManager::GetInputs()
{
	return inputs;
}

void InputManager::Update()
{
	for (std::pair<int, Input> pair : inputs) {
		pair.second.Update();
	}
}

void InputManager::Init()
{
	inputs.insert(std::pair<int, Input>(Controls::InputCode::Up, Input(InputType::Keyboard, sf::Keyboard::W)));
	/*inputs.insert(std::pair<int, Input>(Controls::InputCode::Down, Input(InputType::Keyboard, sf::Keyboard::S)));
	inputs.insert(std::pair<int, Input>(Controls::InputCode::Left, Input(InputType::Keyboard, sf::Keyboard::A)));
	inputs.insert(std::pair<int, Input>(Controls::InputCode::Up, Input(InputType::Keyboard, sf::Keyboard::W)));
	inputs.insert(std::pair<int, Input>(Controls::InputCode::Escape, Input(InputType::Keyboard, sf::Keyboard::Escape)));
	inputs.insert(std::pair<int, Input>(Controls::InputCode::Select, Input(InputType::Mouse, sf::Mouse::Left)));*/
}

int InputManager::GetInput(int inputCode)
{
	return inputs[inputCode].currentState;
}
