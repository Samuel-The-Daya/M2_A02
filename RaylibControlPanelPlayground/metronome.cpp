#include "metronome.hpp"

#include "raylib.h"
#include <cmath>

// Constructor
Metronome::Metronome(int x, int y, float size, float pendulumLength, Color pendulumColor, Color baseColor, Color backColor, int bpm)
	: x{ x }, y{ y }, size{ size }, pendulumLength{ pendulumLength }, pendulumColor{ pendulumColor }, baseColor{ baseColor }, backColor{ backColor }, bpm {
	bpm
}, rotation{ -PI / 2 } // Rotation is automatically set to have the pendulum point upwards
{
}

// Graphics update loop
void Metronome::show()
{
	// Draws the base & back
	DrawRectangle(x - size * 3 * 0.5f, y - pendulumLength * 1.5f + size * 2, size * 3, pendulumLength * 1.5f, backColor);
	DrawEllipse(x, y, size, size, baseColor);

	// Calculate the end of the pendulum
	Vector2 pendulumEnd{x + pendulumLength * cosf(rotation),y + pendulumLength * sinf(rotation)};
	Vector2 basePendulumEnd{ x + pendulumLength *  cosf(-PI / 2), y + pendulumLength * sinf(-PI / 2)};

	// Draws the pendulum
	DrawLineEx(Vector2(x, y), basePendulumEnd, size/4, baseColor);
	DrawLineEx(Vector2(x,y), pendulumEnd, size/4, pendulumColor);

	// Swing the pendulum
	swing();
}

// Metronome swinging function
void Metronome::swing()
{
	// Grabs the deltaTime & calculate speed
	const float deltaTime{ GetFrameTime() };
	const float speed{ PI * deltaTime *  bpm / 120};

	// rotates based on the speed
	rotation += sin(speed);

	// If the pendulum has hit the end of it's arc, then bounce back
	// **TEMPORARY**
	// Future Implementation:
	// Small bug that has the pendulum glitching out, will fix in the future
	if (rotation >= -PI / 2 + PI / 4) {
		bpm *= -1;
	} else if (rotation <= -PI / 2 - PI / 4) {
		bpm *= -1;
	}
}
