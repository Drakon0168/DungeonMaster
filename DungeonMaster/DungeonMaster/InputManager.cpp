#include "pch.h"
#include "InputManager.h"

void InputManager::Init()
{
	inputs.insert(std::pair<int, Input>(InputCode::W, Input(InputType::Keyboard, sf::Keyboard::W)));
}
