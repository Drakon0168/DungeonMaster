#pragma once

using namespace sf;

class Screen
{
public:
	Screen();
	virtual ~Screen();

	//Draws all sprites for the screen
	virtual void Display();
	//Updates all of the objects for the screen
	virtual void Update() = 0;
private:
	RectangleShape* background;
	Color backgroundColor = Color::White;
};

