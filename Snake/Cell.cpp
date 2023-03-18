#include "Cell.h"

Cell::Cell(cellType type, int x, int y)
{
	this->setType(type);
	this->setPosition(x, y);
}


//Setters
void Cell::setType(cellType type)
{
	this->type = type;
}

void Cell::setDirection(cellDirection direction)
{
	this->direction = direction;
}

void Cell::setPosition(int x, int y)
{
	this->xPosition = x;
	this->yPosition = y;
}


//Getters
cellType Cell::getType()
{
	return this->type;
}

cellDirection Cell::getDirection()
{
	return this->direction;
}

int Cell::getXPosition()
{
	return this->xPosition;
}

int Cell::getYPosition()
{
	return this->yPosition;
}
