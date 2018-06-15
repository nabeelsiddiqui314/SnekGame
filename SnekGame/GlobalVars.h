#pragma once

struct vec2 {
	int x, y;
};

constexpr int cellWidth = 10;
constexpr vec2 cellNumber = {100, 60};
constexpr int cellGap = 1;
constexpr vec2 screenSize = {cellWidth * cellNumber.x + cellGap * cellNumber.x,
                             cellWidth * cellNumber.y + cellGap * cellNumber.y };