#pragma once

#include "IDrawable.h"
#include "IUpdatable.h"

using namespace std;

class Screen : public IDrawable, public IUpdatable
{
public:
	Screen();
	virtual ~Screen();

	//Draws all sprites for the screen
	virtual void Display();
	//Updates all of the objects for the screen
	virtual void Update();
protected:
	sf::RectangleShape* background;
	sf::Color backgroundColor = sf::Color::White;

	shared_ptr<vector<IDrawable*>> drawableObjects;
	shared_ptr<vector<IUpdatable*>> updatableObjects;
};

