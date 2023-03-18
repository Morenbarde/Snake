#pragma once

/*
Types of cell
	Empty: not part of the snake
	Head: the front of the snake, only one per game
	Body: middle parts of the snake
	Tail: end piece of the snake, changes as snake increases in length
*/
enum cellType{empty, head, body, tail, border, target};
enum cellDirection{north, east, south, west};

class Cell
{
private:

	cellType type;
	cellDirection direction;
	int xPosition;
	int yPosition;

public:
	//Constructors and Destructors
	Cell(cellType type = empty, int x = 1600, int y = 800);

	//setters
	void setType(cellType type);
	void setDirection(cellDirection direction);
	void setPosition(int x, int y);

	//getters
	cellType getType();
	cellDirection getDirection();
	int getXPosition();
	int getYPosition();
};

