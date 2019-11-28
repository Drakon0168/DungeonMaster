#pragma once
#include "pch.h"

class Screen : IDrawable, IUpdatable
{
private:
	std::vector<IDrawable*> drawables;
	std::vector<IUpdatable*> updateables;

	RectangleShape background;
	RectangleShape fade;
	float fadeAlpha = 0;
	float fadeTime = 0;
	bool fadingOut = false;
	bool fadingIn = false;
public:
#pragma region Constructor
	Screen();
	~Screen();
	Screen(const Screen& other);
	const Screen& operator=(const Screen& other);
#pragma endregion
#pragma region Update
	//Updates all objects on this screen and fades in or out
	void Update(float deltaTime);
	//Displays all objects on this screen
	void Display();
#pragma endregion
#pragma region Functions
	//Initializes backgrounds, buttons, sprites, etc.
	void Init();
	//Starts the fade in or out process
	void FadeOut(float time);
	void FadeIn(float time);
#pragma endregion
};