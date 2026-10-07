#include "raylib.h"

#include "rhythmGame.hpp"
#include "button.hpp"
#include "note.hpp"

#include <vector>

Rhythm::Rhythm()
{
	setupButtons();
}

Rhythm::Rhythm(int bpm, int frequency, int noteChance) :
	bpm{ bpm }, frequency{ frequency }, noteChance{ noteChance }
{
	setupButtons();
}

void Rhythm::setupButtons()
{
	setupButtons("D", "F", "J", "K", PINK, PINK, PINK, PINK, KEY_D, KEY_F, KEY_J, KEY_K, 60);
}

void Rhythm::setupButtons(std::string firstLabel, std::string secondLabel, std::string thirdLabel, std::string fourthLabel, 
	Color firstColor, Color secondColor, Color thirdColor, Color fourthColor, 
	KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, 
	float size)
{
	buttons.clear();
	std::vector<int> columns{ GetScreenWidth() / 2 - GetScreenWidth() / 5,
							GetScreenWidth() / 2 - GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 5 };

	buttons.push_back(Button(
		columns[0],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		firstLabel,
		DARKGRAY,
		firstColor,
		firstKey));

	buttons.push_back(Button(
		columns[1],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		secondLabel,
		DARKGRAY,
		secondColor,
		secondKey));

	buttons.push_back(Button(
		columns[2],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		thirdLabel,
		DARKGRAY,
		thirdColor,
		thirdKey));

	buttons.push_back(Button(
		columns[3],
		GetScreenHeight() - GetScreenHeight() / 8,
		size,
		fourthLabel,
		DARKGRAY,
		fourthColor,
		fourthKey));
}

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

void Rhythm::update()
{
	std::vector<int> columns{ GetScreenWidth() / 2 - GetScreenWidth() / 5,
							GetScreenWidth() / 2 - GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 15,
							GetScreenWidth() / 2 + GetScreenWidth() / 5 };

	const int r{ GetRandomValue(0,3) };
	const int c{ GetRandomValue(0,100) };

	interval -= GetFrameTime();

	if (interval <= 0) {

		if (c <= noteChance) {
			notes.push_back(Note(Vector2(columns[r], 0),
				Vector2(columns[r], GetScreenHeight() - GetScreenHeight() / 8),
				60,
				BLUE,
				bpm));
		}

		interval = static_cast<float>(60) / static_cast<float>(bpm) / static_cast<float>(frequency);
	}
}
