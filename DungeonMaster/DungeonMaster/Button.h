#pragma once

#include "pch.h"
#include "IDrawable.h"
#include "IUpdatable.h"

using namespace sf;

class Button : public IDrawable, public IUpdatable
{
public:
	Vector2f position;
	Vector2f size;

	Button();
	~Button();

	void Display();
	void Update();

	bool ContainsPoint(sf::Vector2i);

	void(*OnClick)();
private:
	std::shared_ptr<RectangleShape> background;
	std::shared_ptr<Font> font;
	std::shared_ptr<Text> text;
};

