#include <iostream>

#include "raylib.h"

#include "button.hpp"
#include "metronome.hpp"
#include "note.hpp"

#include "rhythmGame.hpp"

int main()
{
	const int bpm{ 100 };
	const int noteFrequency{ 100 };

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1500, 800, "Samuel's Rhythm Game");

	Note noteSample{
		Vector2(GetScreenWidth() / 2 - GetScreenWidth() / 5,
		0),
		Vector2(GetScreenWidth() / 2 - GetScreenWidth() / 5,
		GetScreenHeight() - GetScreenHeight() / 8),
		60,
		BLUE,
		bpm
	};

	Button buttonD{
		GetScreenWidth() / 2 - GetScreenWidth() / 5,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"D",
		DARKGRAY,
		PINK,
		KEY_D
	};

	Button buttonF{
		GetScreenWidth() / 2 - GetScreenWidth() / 15,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"F",
		DARKGRAY,
		PINK,
		KEY_F
	};

	Button buttonJ{
		GetScreenWidth() / 2 + GetScreenWidth() / 15,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"J",
		DARKGRAY,
		PINK,
		KEY_J
	};

	Button buttonK{
		GetScreenWidth() / 2 + GetScreenWidth() / 5,
		GetScreenHeight() - GetScreenHeight() / 8,
		60,
		"K",
		DARKGRAY,
		PINK,
		KEY_K
	};

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

	Rhythm game{bpm, noteFrequency};

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

		buttonD.show();
		buttonF.show();
		buttonJ.show();
		buttonK.show();

		metronomeLeft.show();
		metronomeRight.show();


		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
