#pragma once

#include "raylib.h"

#include <string>

class Button {
	// Private Members
	int x;
	int y;
	float radius;
	std::string label;
	Color offColor;
	Color onColor;
	KeyboardKey keyCode;

public:
	Button(int x, int y, float radius, std::string label, Color offColor, Color onColor, KeyboardKey keyCode);

	void show();
};