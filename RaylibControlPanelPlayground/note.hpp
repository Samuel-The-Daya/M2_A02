#pragma once

#include "raylib.h"

/// <summary>
/// Note Class.
/// Moves from a position DOWNWARDS to a target position.
/// </summary>
class Note {
	// Private Members
	Vector2 position;
	Vector2 targetPosition;
	float radius;
	Color color;
	int bpm;

public:

	/// <summary>
	/// Note Class Constructor
	/// </summary>
	/// <param name="position"></param>
	/// <param name="targetPosition"></param>
	/// <param name="radius"></param>
	/// <param name="color"></param>
	/// <param name="bpm"></param>
	Note(Vector2 position, Vector2 targetPosition, float radius, Color color, int bpm);

	/// <summary>
	/// Note's movement update loop
	/// </summary>
	void move();

	/// <summary>
	/// Note's graphic update loop
	/// </summary>
	void show();
	
};