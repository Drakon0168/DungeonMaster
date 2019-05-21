#include "pch.h"
#include "Button.h"
#include "GameManager.h"
#include "InputManager.h"

#define mousePosition GameManager::Instance()->mousePosition
#define inputManager InputManager::Instance()

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

	setupText("Untitled");
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

	setupText("Untitled");
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

	setupText("Untitled");
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

	setupText("Untitled");
}

Button::Button(Vector2f position, Vector2f size, String buttonText)
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

	setupText(buttonText);
}

Button::Button(Vector2f position, Vector2f size, Vector2f anchor, String buttonText)
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

	setupText(buttonText);
}

Button::Button(Vector2f position, Vector2f size, Vector2f anchor, String buttonText, String fontFile)
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

	setupText(buttonText);
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
		if (inputManager->Inputs[Controls::LeftClick]->state == InputState::Down) {
			background->setFillColor(GameManager::Instance()->buttonPressedColor);
		}
		else if (inputManager->Inputs[Controls::LeftClick]->state == InputState::Released) {
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

void Button::setupText(string buttonText)
{
	//Set font
	font = *Screen::buttonFont;
	//Setup the text
	text = std::shared_ptr<Text>(new Text());
	text->setFont(font);
	text->setString(buttonText);
	text->setCharacterSize(GameManager::Instance()->defaultTextSize);
	text->setFillColor(Color::Black);
	text->setPosition(Vector2f(anchor.x * GameManager::Instance()->windowWidth, anchor.y * GameManager::Instance()->windowHeight) + position);
	text->setStyle(sf::Text::Regular);
	text->setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
}
