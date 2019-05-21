#include "pch.h"
#include "GameManager.h"
#include "InputManager.h"

using namespace sf;

int main()
{
	//Set up SFML Window
	RenderWindow window(VideoMode(GameManager::Instance()->windowWidth, GameManager::Instance()->windowHeight), "Dungeon Master");
	window.setFramerateLimit(60);

	//Set up update loop variables
	Clock clock;
	float deltaTime = 0;
	float lastTime = 0;
	srand(0);

	GameManager::Instance()->window = &window;
	GameManager::Instance()->SetupScreens();

	InputManager::Instance()->SetupInputs();

	while (window.isOpen()) {
		Event event;
		float currentTime = clock.getElapsedTime().asSeconds();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		InputManager::Instance()->Update();

		GameManager::Instance()->Update(deltaTime);

		window.clear();

		GameManager::Instance()->Display();

		window.display();
	}
}