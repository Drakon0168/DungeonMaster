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

	void SetBackgroundColor(Color color);
	void SetTextColor(Color color);

	void Display();
	void Update();
private:
	std::shared_ptr<RectangleShape> background;
	std::shared_ptr<Font> font;
	std::shared_ptr<Text> text;
};

