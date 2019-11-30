#include "pch.h"
#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	//Set up SFML Window
	window = new RenderWindow(VideoMode(DEFAULT_SCREEN_SIZE.x, DEFAULT_SCREEN_SIZE.y), "Dungeon Master");
	window->setFramerateLimit(60);

	//Set up update loop variables
	Clock clock;
	srand(0);
}

GameManager::~GameManager()
{
	delete InputManager::GetInstance();
	delete ScreenManager::GetInstance();
	delete window;
}

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new GameManager();
	}

	return instance;
}

Vector2i GameManager::GetScreenSize()
{
	return (Vector2i)window->getSize();
}

RenderWindow* GameManager::GetRenderWindow()
{
	return window;
}

void GameManager::Update()
{
	//Update timers
	float currentTime = clock.getElapsedTime().asSeconds();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	InputManager::GetInstance()->Update();
	ScreenManager::GetInstance()->Update(deltaTime);

	//Close the game when escape is pressed
	if (InputManager::GetInstance()->GetInput(Controls::Escape) == InputState::Pressed) {
		CloseGame();
	}
}

void GameManager::Display()
{
	ScreenManager::GetInstance()->Display();
}

void GameManager::Init()
{
	InputManager::GetInstance()->Init();
	ScreenManager::GetInstance()->Init();
}

void GameManager::StartLoop()
{
	while (window->isOpen()) {
		Event event;
		
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				CloseGame();
			}
		}

		Update();

		window->clear();

		Display();

		window->display();
	}
}

void GameManager::CloseGame()
{
	window->close();
}