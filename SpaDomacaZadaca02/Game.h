#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
struct cell {
	int color[3];
	int neighborsCount;
	bool alive;
	int position[2];
	RectangleShape drawable;
};
class Game
{
public:
	Game(RenderWindow* window);
	void draw();
private:
	void init();
	void colorSet();
	void change();
	void drawBoard();
	void countNeighbors(int i, int j);
	RenderWindow* window;
	Clock frameClock;
	cell cells[40][40];
	Time currTime;
	Time stop = seconds(2.0f);

};

