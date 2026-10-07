#pragma once

#include "raylib.h"

#include <string>

/// <summary>
/// Button Class.
/// Displays a circular button that will change color depending if a certain key is inputted
/// </summary>
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

	/// <summary>
	/// Button Class Constructor
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="radius"></param>
	/// <param name="label"></param>
	/// <param name="offColor"></param>
	/// <param name="onColor"></param>
	/// <param name="keyCode"></param>
	Button(int x, int y, float radius, std::string label, Color offColor, Color onColor, KeyboardKey keyCode);

	/// <summary>
	/// Button's graphics update loop
	/// </summary>
	void show();
};