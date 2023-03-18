#include "Board.h"

Board::Board(int windowWidth, int windowHeight)
{
	//Each cell will be 25 x 25 pixels
	this->width = windowWidth/25;
	this->height = windowHeight/25;

	Cell cell;
	
	//Creates a board of empty cells
	for (int i = 0; i < height; i++) {
		std::vector<Cell> boardRow;

		//Creates a row of the board
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
				cell = Cell(border, i, j);
			} else {
				cell = Cell(empty, i, j);
			}
			boardRow.push_back(cell);
		}
		//Pushes the row into the array that makes up the board, giving the array an ixj size,
		//with each position being filled by a cell
		this->gameBoard.push_back(boardRow);
	}
}

Board::~Board()
{
}

void Board::setCell(Cell cell, int x, int y)
{
	gameBoard[y][x] = cell;
	cell.setPosition(x, y);
}

int Board::getHeight()
{
	return this->height;
}

int Board::getWidth()
{
	return this->width;
}

Cell Board::getCell(int x, int y)
{
	return gameBoard[y][x];
}

void Board::swapCell(int x1, int y1, int x2, int y2)
{
	Cell holder = gameBoard[y1][x1];
	gameBoard[y1][x1] = gameBoard[y2][x2];
	gameBoard[y2][x2] = holder;
}
