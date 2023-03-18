#pragma once

#include "Cell.h"

#include <iostream>
#include <vector>

class Board
{
private:

	//private variables
	int height;
	int width;

	std::vector<std::vector <Cell>> gameBoard;

public:

	//constructors and destructors
	Board(int windowWidth = 1600, int windowHeight = 800);
	virtual ~Board();

	//Setters
	void setCell(Cell cell, int x, int y);

	//Getters
	int getHeight();
	int getWidth();
	Cell getCell(int x, int y);

	//Functions
	void swapCell(int x1, int y1, int x2, int y2);
};

