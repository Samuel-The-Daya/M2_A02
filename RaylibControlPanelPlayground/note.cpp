#include "note.hpp"

// Constructor
Note::Note(Vector2 position, Vector2 targetPosition, float radius, Color color, int bpm)
	: position{position}, targetPosition{targetPosition}, radius{radius}, color{color}, bpm{bpm}
{
}

// Movement update loop
// **TEMPORARY** 
// Future Implementation:
// Making Note move to any point and not just downward
void Note::move()
{
	const float deltaTime{ GetFrameTime() };
	const float speed{ targetPosition.y - position.y / bpm };

	position.y += speed * deltaTime;
}

// Draw the note
void Note::show()
{
	DrawEllipse(position.x, position.y, radius + radius / 16, radius + radius / 16, BLACK);
	DrawEllipse(position.x, position.y, radius, radius, color);
}
