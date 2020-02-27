#include "pch.h"

#define GameInstance GameManager::GetInstance()

using namespace std;

int main()
{
	//Set up SFML Window
	GameInstance->SetWindow(make_shared<sf::RenderWindow>(sf::VideoMode(GameInstance->GetWindowWidth(), GameInstance->GetWindowHeight()), "Dungeon Master"));
	GameInstance->GetWindow()->setFramerateLimit(60);

	//Set up update loop variables
	sf::Clock clock;
	float deltaTime = 0;
	float lastTime = 0;
	srand(0);

	GameInstance->SetupScreens();

	InputManager::Instance()->SetupInputs();

	while (GameInstance->GetWindow()->isOpen()) {
		sf::Event event;
		float currentTime = clock.getElapsedTime().asSeconds();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		while (GameInstance->GetWindow()->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				GameInstance->GetWindow()->close();
			}
		}

		InputManager::Instance()->Update();

		GameInstance->Update(deltaTime);

		/*cout << "Left Click State: ";

		switch (InputManager::Instance()->Inputs[Controls::LeftClick]->state) {
		case InputState::Down:
			cout << "Down" << endl;
			break;
		case InputState::Up:
			cout << "Up" << endl;
			break;
		case InputState::Pressed:
			cout << "Pressed" << endl;
			break;
		case InputState::Released:
			cout << "Released" << endl;
			break;
		}*/

		GameInstance->GetWindow()->clear();

		GameInstance->Draw();

		GameInstance->GetWindow()->display();
	}
}