#include <iostream>

#include "raylib.h"
#include "metronome.hpp"
#include "rhythmGame.hpp"

int main()
{
	const int bpm{ 180 };
	const int noteFrequency{ 2 };
	const int noteChance{ 75 };

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1500, 800, "Samuel's Rhythm Game");

	Metronome metronomeLeft{
		GetScreenWidth() / 6,
		GetScreenHeight() / 2,
		25,
		100,
		YELLOW,
		GRAY,
		BROWN,
		bpm
	};

	Metronome metronomeRight{
		GetScreenWidth() - GetScreenWidth() / 6,
		GetScreenHeight() / 2,
		25,
		100,
		ORANGE,
		GRAY,
		BROWN,
		bpm
	};

	Rhythm game{bpm, noteFrequency, noteChance};

	game.setupButtons();

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{

		game.update();

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(SKYBLUE);

		game.render();

		metronomeLeft.show();
		metronomeRight.show();


		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
