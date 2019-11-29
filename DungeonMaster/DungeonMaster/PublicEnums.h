#pragma once

enum Screens {
	MainMenu,
	Gameplay,
	Options
};

namespace Controls {
	enum InputCode {
		Up,
		Down,
		Left,
		Right,
		Escape,
		Select
	};
}

enum InputState {
	Up,
	Down,
	Pressed,
	Released
};

enum InputType {
	Mouse,
	Keyboard
};