#pragma once
struct Position
{
	int x;
	int y;

	void operator+= (const Position& other) {
		x += other.x;
		y += other.y;
	}
};

