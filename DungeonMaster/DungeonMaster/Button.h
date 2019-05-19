#pragma once

#include "pch.h"
#include "Screen.h"
#include "IDrawable.h"
#include "IUpdatable.h"

using namespace sf;

class Button : public IDrawable, public IUpdatable
{
public:
	//The position of the button relative to its anchor
	Vector2f position;
	//The width and height of the button
	Vector2f size;
	//The position that the button is anchored to (0.0-1.0 based on window size)
	Vector2f anchor;

	Button();
	Button(Vector2f position);
	Button(Vector2f position, Vector2f size);
	Button(Vector2f position, Vector2f size, Vector2f anchor);
	Button(Vector2f position, Vector2f size, String buttonText);
	Button(Vector2f position, Vector2f size, Vector2f anchor, String buttonText);
	Button(Vector2f position, Vector2f size, Vector2f anchor, String buttonText, String fontFile);
	~Button();

	void Display();
	void Update();

	bool ContainsPoint(sf::Vector2i);

	void(*OnClick)();
private:
	std::shared_ptr<RectangleShape> background;
	std::shared_ptr<Text> text;
	Font font;

	void setupText(string buttonText);
};

