#include <iostream>

#include "raylib.h"

#include "button.hpp"
#include "metronome.hpp"

int main()
{
	const float bpm{ 130 };

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1500, 800, "Samuel's Rhythm Game");

	Button buttonD{
		GetScreenWidth() / 2 - GetScreenWidth() / 5,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"D",
		DARKGRAY,
		PINK,
		false
	};

	Button buttonF{
		GetScreenWidth() / 2 - GetScreenWidth() / 15,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"F",
		DARKGRAY,
		PINK,
		false
	};

	Button buttonJ{
		GetScreenWidth() / 2 + GetScreenWidth() / 15,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"J",
		DARKGRAY,
		PINK,
		false
	};

	Button buttonK{
		GetScreenWidth() / 2 + GetScreenWidth() / 5,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"K",
		DARKGRAY,
		PINK,
		false
	};

	Metronome metronomeOne{
		GetScreenWidth() / 6,
		GetScreenHeight() / 2,
		25,
		100,
		YELLOW,
		GRAY,
		BROWN,
		bpm
	};

	Metronome metronomeTwo{
		GetScreenWidth() - GetScreenWidth() / 6,
		GetScreenHeight() / 2,
		25,
		100,
		ORANGE,
		GRAY,
		BROWN,
		bpm
	};

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{

		buttonD.setStatus(IsKeyDown(KEY_D));
		buttonF.setStatus(IsKeyDown(KEY_F));
		buttonJ.setStatus(IsKeyDown(KEY_J));
		buttonK.setStatus(IsKeyDown(KEY_K));

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(SKYBLUE);

		buttonD.show();
		buttonF.show();
		buttonJ.show();
		buttonK.show();

		metronomeOne.show();
		metronomeTwo.show();


		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
