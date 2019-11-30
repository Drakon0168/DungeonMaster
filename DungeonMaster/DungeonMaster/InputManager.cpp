#include "pch.h"
#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager::InputManager()
{
	globalMousePosition = Vector2i(0, 0);
	windowMousePosition = Vector2i(0, 0);
}

InputManager::~InputManager()
{
	for (std::pair<int, Input*> pair : inputs) {
		delete pair.second;
	}
}

InputManager* InputManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new InputManager();
	}

	return instance;
}

std::map<int, Input*> InputManager::GetInputs()
{
	return inputs;
}

void InputManager::Update()
{
	globalMousePosition = Mouse::getPosition();
	windowMousePosition = globalMousePosition - GameManager::GetInstance()->GetRenderWindow()->getPosition();

	for (std::pair<int, Input*> pair : inputs) {
		pair.second->Update();
	}

	//std::cout << "Global Mouse Position: (" << globalMousePosition.x << ", " << globalMousePosition.y << ")" << std::endl;
	//std::cout << "Window Mouse Position: (" << windowMousePosition.x << ", " << windowMousePosition.y << ")" << std::endl;
}

void InputManager::Init()
{
	inputs.insert(std::pair<int, Input*>(Controls::InputCode::Up, new Input(InputType::Keyboard, sf::Keyboard::W)));
	inputs.insert(std::pair<int, Input*>(Controls::InputCode::Down, new Input(InputType::Keyboard, sf::Keyboard::S)));
	inputs.insert(std::pair<int, Input*>(Controls::InputCode::Left, new Input(InputType::Keyboard, sf::Keyboard::A)));
	inputs.insert(std::pair<int, Input*>(Controls::InputCode::Up, new Input(InputType::Keyboard, sf::Keyboard::W)));
	inputs.insert(std::pair<int, Input*>(Controls::InputCode::Escape, new Input(InputType::Keyboard, sf::Keyboard::Escape)));
	inputs.insert(std::pair<int, Input*>(Controls::InputCode::Select, new Input(InputType::Mouse, sf::Mouse::Left)));
}

int InputManager::GetInput(int inputCode)
{
	return inputs[inputCode]->currentState;
}
