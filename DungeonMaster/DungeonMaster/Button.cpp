#include "pch.h"
#include "Button.h"
#include "GameManager.h"

Button::Button()
{
	position = Vector2f(0, 0);
	size = Vector2f(100, 100);

	//Setup the rectangle
	background = std::shared_ptr<RectangleShape>(new RectangleShape(size));
	background->setOrigin(size.x / 2, size.y / 2);
	background->setPosition(position);
	background->setFillColor(Color(100, 100, 100, 255));

	//Load the font
	font = std::shared_ptr<Font>(new Font());
	font->loadFromFile("TestFont.tff");

	//Setup the text
	text = std::shared_ptr<Text>(new Text());
	text->setFont(*font);
	text->setString("Untitled");
	text->setCharacterSize(24);
	text->setFillColor(Color::Black);
	text->setPosition(position);
}

Button::~Button()
{
}

void Button::SetBackgroundColor(Color color)
{
	background->setFillColor(color);
}

void Button::SetTextColor(Color color)
{
	text->setFillColor(color);
}

void Button::Display()
{
	GameManager::Instance()->window->draw(*background);
	GameManager::Instance()->window->draw(*text);
}

void Button::Update()
{

}