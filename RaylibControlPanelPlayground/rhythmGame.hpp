#pragma once

#include "raylib.h"

#include <vector>

#include "button.hpp"
#include "note.hpp"

/// <summary>
/// Rhythm Game Class.
/// Sets up four buttons & randomly spawns notes based on bpm, frequency & chance
/// </summary>
class Rhythm {
	// Private Members
	std::vector<Note> notes;
	std::vector<Button> buttons;
	int bpm{ 60 };
	int noteChance{ 50 };
	int frequency{ 5 };
	double interval{ 0 };


public:

	/// <summary>
	/// Rhythm Game Constructor
	/// </summary>
	Rhythm();

	/// <summary>
	/// Rhythm Game Constructor
	/// </summary>
	/// <param name="bpm"></param>
	/// <param name="frequency"></param>
	/// <param name="noteChance"></param>
	Rhythm(int bpm, int frequency, int noteChance);

	/// <summary>
	/// Basic button setup
	/// </summary>
	void setupButtons();

	/// <summary>
	/// Button setup with much more customization
	/// </summary>
	/// <param name="firstLabel"></param>
	/// <param name="secondLabel"></param>
	/// <param name="thirdLabel"></param>
	/// <param name="fourthLabel"></param>
	/// <param name="firstColor"></param>
	/// <param name="secondColor"></param>
	/// <param name="thirdColor"></param>
	/// <param name="fourthColor"></param>
	/// <param name="firstKey"></param>
	/// <param name="secondKey"></param>
	/// <param name="thirdKey"></param>
	/// <param name="fourthKey"></param>
	/// <param name="size"></param>
	void setupButtons(std::string firstLabel, std::string secondLabel, std::string thirdLabel, std::string fourthLabel, 
		Color firstColor, Color secondColor, Color thirdColor, Color fourthColor,
		KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, float size);

	/// <summary>
	/// Rhythm game's render update loop
	/// </summary>
	void render();

	/// <summary>
	/// Rhythm game's update loop
	/// </summary>
	void update();

};