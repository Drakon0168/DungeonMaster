#pragma once

enum Screens {
	MainMenu,
	Gameplay,
	Options
};

enum InputCode {
	W,
	A,
	S,
	D,
	Space,
	Escape,
	LeftMouse,
	RightMouse,
	MiddleMouse
};

enum InputState {
	Down,
	Up,
	Pressed,
	Released
};

enum InputType {
	Mouse,
	Keyboard,
};