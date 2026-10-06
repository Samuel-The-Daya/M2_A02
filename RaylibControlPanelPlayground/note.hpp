#pragma once

#include "raylib.h"

class Note {
	// Private Members
	Vector2 position;
	Vector2 targetPosition;
	float radius;
	Color color;
	int bpm;

public:

	Note(Vector2 position, Vector2 targetPosition, float radius, Color color, int bpm);

	void move();
	void show();
	
};