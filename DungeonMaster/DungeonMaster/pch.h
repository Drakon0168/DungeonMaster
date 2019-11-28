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

//My Classes
#include "IDrawable.h"
#include "IUpdatable.h"
#include "PublicEnums.h"
#include "Input.h"

#include "GameManager.h"
#include "ScreenManager.h"

#endif //PCH_H