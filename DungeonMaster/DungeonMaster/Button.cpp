#include "pch.h"
#include "Button.h"
#include "GameManager.h"

#define mousePosition GameManager::Instance()->mousePosition

Button::Button()
{
	position = Vector2f(0, 0);
	size = Vector2f(100, 100);
	anchor = Vector2f(0.5f, 0.5f);
	OnClick = nullptr;

	//Setup the rectangle
	background = std::shared_ptr<RectangleShape>(new RectangleShape(size));
	background->setOrigin(size.x / 2, size.y / 2);
	background->setPosition(Vector2f(anchor.x * GameManager::Instance()->windowWidth, anchor.y * GameManager::Instance()->windowHeight) + position);
	background->setFillColor(Color(100, 100, 100, 255));

	setupText("Fonts\\TestFont.tff", "Untitled");
}

Button::Button(Vector2f position)
{
	this->position = position;
	size = Vector2f(100, 100);
	anchor = Vector2f(0.5f, 0.5f);
	OnClick = nullptr;

	//Setup the rectangle
	background = std::shared_ptr<RectangleShape>(new RectangleShape(size));
	background->setOrigin(size.x / 2, size.y / 2);
	background->setPosition(Vector2f(anchor.x * GameManager::Instance()->windowWidth, anchor.y * GameManager::Instance()->windowHeight) + position);
	background->setFillColor(Color(100, 100, 100, 255));

	setupText("Fonts\\TestFont.tff", "Untitled");
}

Button::Button(Vector2f position, Vector2f size)
{
	this->position = position;
	this->size = size;
	anchor = Vector2f(0.5f, 0.5f);
	OnClick = nullptr;

	//Setup the rectangle
	background = std::shared_ptr<RectangleShape>(new RectangleShape(size));
	background->setOrigin(size.x / 2, size.y / 2);
	background->setPosition(Vector2f(anchor.x * GameManager::Instance()->windowWidth, anchor.y * GameManager::Instance()->windowHeight) + position);
	background->setFillColor(Color(100, 100, 100, 255));

	setupText("Fonts/TestFont.tff", "Untitled");
}

Button::Button(Vector2f position, Vector2f size, Vector2f anchor)
{
	this->position = position;
	this->size = size;
	this->anchor = anchor;
	OnClick = nullptr;

	//Setup the rectangle
	background = std::shared_ptr<RectangleShape>(new RectangleShape(size));
	background->setOrigin(size.x / 2, size.y / 2);
	background->setPosition(Vector2f(anchor.x * GameManager::Instance()->windowWidth, anchor.y * GameManager::Instance()->windowHeight) + position);
	background->setFillColor(Color(100, 100, 100, 255));

	setupText("Fonts\\TestFont.tff", "Untitled");
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

			//TODO: Call on click on the first frame that the mouse button is released
			if (OnClick != nullptr) {
				OnClick();
			}
		}
	}
	else {
		background->setFillColor(GameManager::Instance()->buttonDefaultColor);
	}
}

bool Button::ContainsPoint(sf::Vector2i p)
{
	return (p.x > ((anchor.x * GameManager::Instance()->windowWidth) + position.x) - (size.x / 2) && p.x < ((anchor.x * GameManager::Instance()->windowWidth) + position.x) + (size.x / 2) && p.y > ((anchor.y * GameManager::Instance()->windowHeight) + position.y) - (size.y / 2) && p.y < ((anchor.y * GameManager::Instance()->windowHeight) + position.y) + (size.y / 2));
}

void Button::setupText(string fontPath, string buttonText)
{
	//The font has been temporarily removed from the folder

	//TODO load the font in the game manager or some other singleton
	//Load the font
	font = std::shared_ptr<Font>(new Font());
	font->loadFromFile(fontPath);

	//Setup the text
	text = std::shared_ptr<Text>(new Text());
	text->setFont(*font);
	text->setString(buttonText);
	text->setCharacterSize(GameManager::Instance()->defaultTextSize);
	text->setFillColor(Color::Black);
	text->setPosition(position);
	text->setStyle(sf::Text::Regular);
}
