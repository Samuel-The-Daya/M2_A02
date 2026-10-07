#pragma once

#include "raylib.h"

#include <vector>

#include "button.hpp"
#include "note.hpp"

class Rhythm {
	// Private Members
	std::vector<Note> notes;
	std::vector<Button> buttons;
	int bpm{ 60 };
	int frequency{ 5 };
	float interval{ 0 };


public:

	Rhythm();

	Rhythm(int bpm, int frequency);

	void setupButtons();

	void setupButtons(KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, float size);

	void setupButtons(Color firstColor, Color secondColor, Color thirdColor, Color fourthColor,
		KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, float size);

	void render();

	void update();

};