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
	int noteChance{ 50 };
	int frequency{ 5 };
	double interval{ 0 };


public:

	Rhythm();

	Rhythm(int bpm, int frequency, int noteChance);

	void setupButtons();

	void setupButtons(KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, float size);

	void setupButtons(std::string firstLabel, std::string secondLabel, std::string thirdLabel, std::string fourthLabel, 
		Color firstColor, Color secondColor, Color thirdColor, Color fourthColor,
		KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, float size);

	void render();

	void update();

};