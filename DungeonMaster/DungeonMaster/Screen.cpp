#include "pch.h"
#include "Screen.h"

Screen::Screen()
{
	
}

Screen::~Screen()
{
	for (int i = 0; i < drawables.size(); i++) {
		delete drawables[i];
	}

	for (int i = 0; i < updateables.size(); i++) {
		delete updateables[i];
	}
}

Screen::Screen(const Screen& other)
{
	//TODO: Copy drawable and updateable lists
}

const Screen& Screen::operator=(const Screen& other)
{
	return Screen(other);
}

void Screen::Update(float deltaTime)
{
	for (int i = 0; i < updateables.size(); i++) {
		updateables[i]->Update(deltaTime);
	}
}

void Screen::Display()
{
	GameManager::GetInstance()->GetRenderWindow()->draw(background);

	for (int i = 0; i < drawables.size(); i++) {
		drawables[i]->Display();
	}
}

void Screen::Init()
{
	background.setFillColor(ScreenManager::GetInstance()->GetClearColor());
	background.setSize((Vector2f)GameManager::GetInstance()->GetScreenSize());
	background.setPosition(Vector2f(0, 0));
}

void Screen::FadeOut(float fadeTime)
{
	//TODO: Fade out the screen
}

void Screen::FadeIn(float fadeTime)
{
	//TODO: Fade in the screen
}