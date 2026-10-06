#pragma once

#include "raylib.h"
#include <string>

class Metronome {
	// Private Members
	int x;
	int y;
	float size;
	float pendulumLength;
	Color pendulumColor;
	Color baseColor;
	Color backColor;
	float bpm;
	float rotation;

public:

	Metronome(int x, int y, float size, float pendulumLength, Color pendulumColor, Color baseColor, Color backColor, float bpm);
	void show();

private:

	void swing();
};