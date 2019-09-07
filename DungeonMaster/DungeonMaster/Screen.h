#pragma once

#include "IDrawable.h"
#include "IUpdatable.h"

using namespace std;

class Screen : public IDrawable, public IUpdatable
{
public:
	vector<shared_ptr<IDrawable>> drawableObjects;
	vector<shared_ptr<IDrawable>> UIObjects;
	vector<shared_ptr<IUpdatable>> updatableObjects;

	static shared_ptr<sf::RenderWindow> window;
	static shared_ptr<sf::Font> buttonFont;

	Screen();
	virtual ~Screen();

	//Draws all sprites for the screen
	virtual void Display();
	//Updates all of the objects for the screen
	virtual void Update();

	static void closeGame();
protected:
	sf::RectangleShape* background;
	sf::Color backgroundColor = sf::Color::White;

	shared_ptr<sf::View> UIView;
	shared_ptr<sf::View> DefaultView;
};

