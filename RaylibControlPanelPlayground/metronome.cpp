#include "metronome.hpp"

#include "raylib.h"
#include <cmath>
Metronome::Metronome(int x, int y, float size, float pendulumLength, Color pendulumColor, Color baseColor, Color backColor, int bpm)
	: x{ x }, y{ y }, size{ size }, pendulumLength{ pendulumLength }, pendulumColor{ pendulumColor }, baseColor{ baseColor }, backColor{ backColor }, bpm {
	bpm
}, rotation{ -PI / 2 }
{
}

void Metronome::show()
{
	DrawRectangle(x - size * 3 * 0.5f, y - pendulumLength * 1.5f + size * 2, size * 3, pendulumLength * 1.5f, backColor);
	DrawEllipse(x, y, size, size, baseColor);

	Vector2 pendulumEnd{x + pendulumLength * cosf(rotation),y + pendulumLength * sinf(rotation)};
	Vector2 basePendulumEnd{ x + pendulumLength *  cosf(-PI / 2), y + pendulumLength * sinf(-PI / 2)};

	DrawLineEx(Vector2(x, y), basePendulumEnd, size/4, baseColor);
	DrawLineEx(Vector2(x,y), pendulumEnd, size/4, pendulumColor);

	swing();
}

void Metronome::swing()
{
	const float deltaTime{ GetFrameTime() };
	const float speed{ PI * deltaTime *  bpm / 120};

	rotation += sin(speed);

	if (rotation >= -PI / 2 + PI / 4) {
		bpm *= -1;
	} else if (rotation <= -PI / 2 - PI / 4) {
		bpm *= -1;
	}
}
