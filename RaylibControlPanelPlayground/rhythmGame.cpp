#include "raylib.h"

#include "rhythmGame.hpp"
#include "button.hpp"
#include "note.hpp"

#include <vector>

// Constructor & sets up buttons on default
Rhythm::Rhythm()
{
	setupButtons();
}

// Constructor with bpm, frequency & noteChance parameters & sets up buttons on default
Rhythm::Rhythm(int bpm, int frequency, int noteChance) :
	bpm{ bpm }, frequency{ frequency }, noteChance{ noteChance }
{
	setupButtons();
}

// Default setup for buttons
void Rhythm::setupButtons()
{
	setupButtons("D", "F", "J", "K", PINK, PINK, PINK, PINK, KEY_D, KEY_F, KEY_J, KEY_K, 60);
}

// Much more customized button setup
// **EXISTS FOR FUTURE IMPLEMENTATION & CUSTOMIZATION AS CAN BE CHANGED MID GAME**
void Rhythm::setupButtons(std::string firstLabel, std::string secondLabel, std::string thirdLabel, std::string fourthLabel, 
	Color firstColor, Color secondColor, Color thirdColor, Color fourthColor, 
	KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, 
	float size)
{
	// Clears old buttons
	buttons.clear();

	// Sets up the columns
	std::vector<int> columns{ GetScreenWidth() / 2 - GetScreenWidth() / 5,
							GetScreenWidth() / 2 - GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 5 };

	// Create First Button
	buttons.push_back(Button(
		columns[0],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		firstLabel,
		DARKGRAY,
		firstColor,
		firstKey));

	// Create Second Button
	buttons.push_back(Button(
		columns[1],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		secondLabel,
		DARKGRAY,
		secondColor,
		secondKey));

	// Create Third Button
	buttons.push_back(Button(
		columns[2],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		thirdLabel,
		DARKGRAY,
		thirdColor,
		thirdKey));

	// Create Fourth Button
	buttons.push_back(Button(
		columns[3],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		fourthLabel,
		DARKGRAY,
		fourthColor,
		fourthKey));
}

// Iterate collection of notes & buttons
// Then updates & display each of them
void Rhythm::render()
{
	for (auto& n : notes) {
		n.move();
		n.show();
	}

	for (auto& b : buttons) {
		b.show();
	}
}

// Update loop
void Rhythm::update()
{
	// Sets up columns
	std::vector<int> columns{ GetScreenWidth() / 2 - GetScreenWidth() / 5,
							GetScreenWidth() / 2 - GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 5 };

	// Generate two random values
	const int r{ GetRandomValue(0,3) };
	const int c{ GetRandomValue(0,100) };

	// Ticks down interval timer
	interval -= GetFrameTime();

	// When timer is reached 0, attempts to spawn a note
	if (interval <= 0) {

		// If the random value is within the noteChance, spawn a note in a random column
		if (c <= noteChance) {
			notes.push_back(Note(Vector2(columns[r], 0),
				Vector2(columns[r], GetScreenHeight() - GetScreenHeight() / 8),
				60,
				BLUE,
				bpm));
		}

		// Resets timer
		// **MUST BE CASTED TO FLOAT**
		// Keeping the integers as integers will cause the quotient to remain as an integer & not return a decimal value
		interval = static_cast<float>(60) / static_cast<float>(bpm) / static_cast<float>(frequency);
	}
}
