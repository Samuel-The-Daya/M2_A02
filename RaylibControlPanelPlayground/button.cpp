#include "raylib.h"
#include "button.hpp"

#include <string>

// Constructor
Button::Button(int x, int y, float radius, std::string label, Color offColor, Color onColor, KeyboardKey keyCode)
	: x{x}, y{y}, radius{radius}, label{label}, offColor{offColor}, onColor{onColor}, keyCode{keyCode}
{
}

// Graphics update loop
void Button::show()
{
	// Display the button
	DrawEllipse(x, y, radius + radius / 16, radius + radius/16, BLACK);
	DrawEllipse(x, y, radius, radius, IsKeyDown(keyCode) ? onColor : offColor);
	// Changes color depending if the keyCode's referenced key is pressed or not

	// Displays the label
	DrawText(label.c_str(), x - radius/4, y - radius/3, radius, WHITE);
}
