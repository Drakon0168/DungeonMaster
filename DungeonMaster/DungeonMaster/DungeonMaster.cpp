#include "pch.h"

using namespace std;

int main()
{
	//Set up SFML Window
	shared_ptr<sf::RenderWindow> window = make_shared<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode(GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight), "Dungeon Master"));
	window->setFramerateLimit(60);

	//Set up update loop variables
	sf::Clock clock;
	float deltaTime = 0;
	float lastTime = 0;
	srand(0);

	GameManager::Instance()->window = shared_ptr<sf::RenderWindow>(window);
	GameManager::Instance()->SetupScreens();

	InputManager::Instance()->SetupInputs();

	while (window->isOpen()) {
		sf::Event event;
		float currentTime = clock.getElapsedTime().asSeconds();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
		}

		if (GameManager::Instance()->closeWindow) {
			window->close();
		}

		InputManager::Instance()->Update();

		GameManager::Instance()->Update(deltaTime);

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

		window->clear();

		GameManager::Instance()->Display();

		window->display();
	}
}