#pragma once
#include "pch.h"

class Screen : IDrawable, IUpdatable
{
private:
	std::vector<IDrawable*> drawables;
	std::vector<IUpdatable*> updateables;

	RectangleShape background;
public:
#pragma region Constructor
	Screen();
	~Screen();
	Screen(const Screen& other);
	const Screen& operator=(const Screen& other);
#pragma endregion
#pragma region Update
	void Update(float deltaTime);
	void Display();
#pragma endregion
#pragma region Functions
	void Init();
	void FadeOut(float fadeTime);
	void FadeIn(float fadeTime);
#pragma endregion
};