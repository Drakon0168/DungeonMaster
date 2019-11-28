#include "pch.h"
#include "Screen.h"

#define GameInstance GameManager::GetInstance()
#define ScreenInstance ScreenManager::GetInstance()

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
	for (int i = 0; i < other.drawables.size(); i++) {
		drawables.push_back(other.drawables[i]);
	}

	for (int i = 0; i < other.updateables.size(); i++) {
		updateables.push_back(other.updateables[i]);
	}

	background = other.background;
	fade = other.fade;
	fadeAlpha = other.fadeAlpha;
	fadeTime = other.fadeTime;
	fadingIn = other.fadingIn;
	fadingOut = other.fadingOut;
}

const Screen& Screen::operator=(const Screen& other)
{
	return Screen(other);
}

void Screen::Update(float deltaTime)
{
	//Update screen objects
	for (int i = 0; i < updateables.size(); i++) {
		updateables[i]->Update(deltaTime);
	}

	//Fade the screen
	if (fadingIn) {
		fadeAlpha -= 255 * fadeTime * deltaTime;
		
		if (fadeAlpha < 0) {
			fadeAlpha = 0;
			fadingIn = false;
		}

		Color fadeColor = fade.getFillColor();
		fadeColor.a = fadeAlpha;
		fade.setFillColor(fadeColor);
	}

	if (fadingOut) {
		fadeAlpha += 255 * fadeTime * deltaTime;

		if (fadeAlpha > 255) {
			fadeAlpha = 0;
			fadingOut = false;
			ScreenInstance->FadeIn();
		}

		Color fadeColor = fade.getFillColor();
		fadeColor.a = fadeAlpha;
		fade.setFillColor(fadeColor);
	}
}

void Screen::Display()
{
	GameInstance->GetRenderWindow()->draw(background);

	for (int i = 0; i < drawables.size(); i++) {
		drawables[i]->Display();
	}

	GameInstance->GetRenderWindow()->draw(fade);
}

void Screen::Init()
{
	background.setFillColor(ScreenInstance->GetClearColor());
	background.setSize((Vector2f)GameInstance->GetScreenSize());
	background.setPosition(Vector2f(0, 0));

	Color fadeColor = Color::Black;
	fadeColor.a = fadeAlpha;
	fade.setFillColor(fadeColor);
	fade.setSize((Vector2f)GameInstance->GetScreenSize());
	fade.setPosition(Vector2f(0, 0));
}

void Screen::FadeOut(float time)
{
	fadingOut = true;
	fadeTime = time;
}

void Screen::FadeIn(float time)
{
	fadingIn = true;
	fadeTime = time;
}