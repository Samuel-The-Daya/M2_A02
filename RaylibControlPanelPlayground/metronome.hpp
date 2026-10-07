#pragma once

#include "raylib.h"
#include <string>

/// <summary>
/// Metronome Class.
/// Displays a metronome that swings to the bpm.
/// </summary>
class Metronome {
	// Private Members
	int x;
	int y;
	float size;
	float pendulumLength;
	Color pendulumColor;
	Color baseColor;
	Color backColor;
	int bpm;
	float rotation;

public:

	/// <summary>
	/// Metronome Class Constructor
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="size"></param>
	/// <param name="pendulumLength"></param>
	/// <param name="pendulumColor"></param>
	/// <param name="baseColor"></param>
	/// <param name="backColor"></param>
	/// <param name="bpm"></param>
	Metronome(int x, int y, float size, float pendulumLength, Color pendulumColor, Color baseColor, Color backColor, int bpm);
	
	/// <summary>
	/// Metronome's graphics update loop
	/// </summary>
	void show();

private:

	/// <summary>
	/// Private swing method that handles the pendulum swinging
	/// </summary>
	void swing();
};