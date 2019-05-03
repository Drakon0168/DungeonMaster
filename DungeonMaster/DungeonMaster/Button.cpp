#include "pch.h"
#include "Button.h"
#include "GameManager.h"

#define mousePosition GameManager::Instance()->mousePosition

Button::Button()
{
	position = Vector2f(200, 200);
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
	text->setCharacterSize(GameManager::Instance()->defaultTextSize);
	text->setFillColor(Color::Black);
	text->setPosition(position);
	text->setStyle(sf::Text::Regular);
}

Button::~Button()
{
}

void Button::Display()
{
	GameManager::Instance()->window->draw(*background);
	GameManager::Instance()->window->draw(*text);
}

void Button::Update()
{
	//If hovered over
	if (ContainsPoint(mousePosition)) {
		background->setFillColor(GameManager::Instance()->buttonHoverColor);

		//If clicked
		if (Mouse::isButtonPressed(Mouse::Left)) {
			background->setFillColor(GameManager::Instance()->buttonPressedColor);

			//Call on click on the first frame that the mouse button is released
		}
	}
	else {
		background->setFillColor(GameManager::Instance()->buttonDefaultColor);
	}
}

bool Button::ContainsPoint(sf::Vector2i p)
{
	return (p.x > position.x - (size.x / 2) && p.x < position.x + (size.x / 2) && p.y > position.y - (size.y / 2) && p.y < position.y + (size.y / 2));
}
