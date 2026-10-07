#include "raylib.h"

#include "rhythmGame.hpp"
#include "button.hpp"
#include "metronome.hpp"

#include <vector>

Rhythm::Rhythm()
{
	setupButtons();
}

Rhythm::Rhythm(int bpm, int frequency) :
	bpm{ bpm }, frequency{ frequency }
{
	setupButtons();
}

void Rhythm::setupButtons()
{
}

void Rhythm::setupButtons(KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, float size)
{
}

void Rhythm::setupButtons(Color firstColor, Color secondColor, Color thirdColor, Color fourthColor, KeyboardKey firstKey, KeyboardKey secondKey, KeyboardKey thirdKey, KeyboardKey fourthKey, float size)
{
}

void Rhythm::render()
{
	notes.shrink_to_fit();
	for (auto& n : notes) {
		n.move();
		n.show();
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

		if (c <= frequency) {
			notes.push_back(Note(Vector2(columns[r], 0),
				Vector2(columns[r], GetScreenHeight() - GetScreenHeight() / 8),
				60,
				BLUE,
				bpm));
		}

		interval = 60 / 100;
	}
}
