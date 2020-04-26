#include "Game.h"
using namespace sf;
using namespace std;

Game::Game(RenderWindow* window)
{
	this->window = window;
	init();
}

void Game::draw()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			window->draw(cells[i][j].drawable);
		}
	}
	
	currTime = frameClock.getElapsedTime();

	colorSet();
	if (currTime >= stop)
	{
		change();
		frameClock.restart();
	}
}

void Game::init()
{
	srand(time(nullptr));
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			cells[i][j].position[0]=i;
			cells[i][j].position[1]=j;
			if (rand() % 4 == 1) {
				cells[i][j].alive = true;
			}
		}
	}
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			countNeighbors(i,j);
		}
	}
	drawBoard();
}

void Game::colorSet()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			countNeighbors(i,j);
			if (cells[i][j].alive)
			{
				switch (cells[i][j].neighborsCount)
				{
				case 0:
					cells[i][j].drawable.setFillColor(Color(255, 0, 0));
					break;
				case 1:
					cells[i][j].drawable.setFillColor(Color(255, 100, 0));
					break;
				case 2:
					cells[i][j].drawable.setFillColor(Color(255, 230, 0));
					break;
				case 3:
					cells[i][j].drawable.setFillColor(Color(255, 255, 0));
					break;
				case 4:
					cells[i][j].drawable.setFillColor(Color(220, 255, 0));
					break;
				case 5:
					cells[i][j].drawable.setFillColor(Color(159, 255, 0));
					break;
				case 6:
					cells[i][j].drawable.setFillColor(Color(88, 255, 0));
					break;
				case 7:
					cells[i][j].drawable.setFillColor(Color(36, 255, 0));
					break;
				case 8:
					cells[i][j].drawable.setFillColor(Color(0, 255, 0));
					break;
				}
			}
			else
			{
				cells[i][j].drawable.setFillColor(Color(0, 0, 0));
			}
		}
	}
}


void Game::change()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (cells[i][j].neighborsCount < 2 || cells[i][j].neighborsCount>3)
			{
				cells[i][j].alive = false;
			}
			else if (cells[i][j].neighborsCount == 3)
			{
				cells[i][j].alive = true;
			}
		}
	}
}

void Game::drawBoard()
{
	float row = 50;
	float column = 50;

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			cells[i][j].drawable.setOutlineThickness(1);
			cells[i][j].drawable.setOutlineColor(Color(255, 0, 0));
			cells[i][j].drawable.setSize(Vector2f(20, 20));
			cells[i][j].drawable.setPosition(row, column);

			row += 20;
		}
		row = 50;
		column += 20;
	}
}

void Game::countNeighbors(int x, int y)
{
	int count = 0;
	for (int i = x-1; i <= x+1; i++)
	{
		for (int j = y-1; j <= y+1; j++)
		{
			if (i >=0 && j >=0 && i <= 39 && j <= 39)
			{
				if (!(i == x && j == y))
				{
					if (cells[i][j].alive)
					{
						count++;
					}
				}
			}
		}
	}
	cells[x][y].neighborsCount=count;
}
