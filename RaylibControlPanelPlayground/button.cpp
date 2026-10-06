#include "raylib.h"
#include "button.hpp"

#include <string>

Button::Button(int x, int y, float radius, std::string label, Color offColor, Color onColor, bool status)
	: x{x}, y{y}, radius{radius}, label{label}, offColor{offColor}, onColor{onColor}, status{status}
{
}

void Button::setStatus(bool s)
{
	status = s;
}

bool Button::Status()
{
	return status;
}

void Button::show()
{
	DrawEllipse(x, y, radius + radius / 16, radius + radius/16, BLACK);
	DrawEllipse(x, y, radius, radius, status ? onColor : offColor);

	DrawText(label.c_str(), x - radius/4, y - radius/3, radius, WHITE);
}
