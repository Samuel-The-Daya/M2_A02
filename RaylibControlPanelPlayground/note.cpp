#include "note.hpp"

Note::Note(Vector2 position, Vector2 targetPosition, float radius, Color color, int bpm)
	: position{position}, targetPosition{targetPosition}, radius{radius}, color{color}, bpm{bpm}
{
}

void Note::move()
{
	const float deltaTime{ GetFrameTime() };
	const float speed{ targetPosition.y - position.y / bpm };

	position.y += speed * deltaTime;
}

void Note::show()
{
	DrawEllipse(position.x, position.y, radius + radius / 16, radius + radius / 16, BLACK);
	DrawEllipse(position.x, position.y, radius, radius, color);
}
