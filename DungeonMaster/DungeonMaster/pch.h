#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <vector>

#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//Custom
//	Interfaces
#include "IDrawable.h"
#include "IUpdatable.h"

//	Enums
#include "PublicEnums.h"

//	Structs
#include "Input.h"

//	Singletons
#include "GameManager.h"
#include "ScreenManager.h"
#include "InputManager.h"

//Classes

#endif //PCH_H