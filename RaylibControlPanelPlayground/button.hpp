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
	bool status;

public:
	Button(int x, int y, float radius, std::string label, Color offColor, Color onColor, bool status);

	void setStatus(bool status);
	bool Status();

	void show();
};