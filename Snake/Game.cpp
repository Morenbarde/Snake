#include "Game.h"


void Game::initVariables()
{
	this->windowHeight = 800;
	this->windowWidth = 1600;

	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = this->windowHeight;
	this->videoMode.width = this->windowWidth;

	this->window = new sf::RenderWindow(this->videoMode, "Game of Snake", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(20);
}

void Game::initBoard()
{
	this->gameBoard = Board(this->windowWidth, this->windowHeight);
}

void Game::initSnake()
{
	this->snakeHeadPiece.setSize(sf::Vector2f(25.f, 25.f));
	this->snakeHeadPiece.setFillColor(sf::Color(54, 1, 63, 255));
	this->snakeHeadPiece.setPosition(25.f, 25.f);
	this->snakeBodyPiece.setSize(sf::Vector2f(25.f, 25.f));
	this->snakeBodyPiece.setFillColor(sf::Color(sf::Color::Black));
	this->snakeTailPiece.setSize(sf::Vector2f(25.f, 25.f));
	this->snakeTailPiece.setFillColor(sf::Color(sf::Color::Black));


	snakeHead = Cell(head, 2, 2);
	this->gameBoard.setCell(snakeHead, snakeHead.getXPosition(), snakeHead.getYPosition());

	snakeTail = snakeHead;

	snake.push_back(&snakeHead);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initBoard();
	this->initSnake();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

int Game::getWindowHeight()
{
	return this->windowHeight;
}

int Game::getWindowWidth()
{
	return this->windowWidth;
}

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			else if (this->ev.key.code == sf::Keyboard::Right) {
				snakeHead.setDirection(east);
			}
			else if (this->ev.key.code == sf::Keyboard::Up)
				snakeHead.setDirection(north);
			else if (this->ev.key.code == sf::Keyboard::Left)
				snakeHead.setDirection(west);
			else if (this->ev.key.code == sf::Keyboard::Down)
				snakeHead.setDirection(south);
			break;
		}
	}
}

void Game::updateTarget()
{
}

bool Game::checkCrash()
{
	bool crashed = false;

	cellDirection headDirection = snakeHead.getDirection();
	int headX = snakeHead.getXPosition();
	int headY = snakeHead.getYPosition();

	//Checks the dirction the snake is facing, and checks if the next cell is blocked
	switch (headDirection) {
	case north:
		if (snakeHead.getYPosition() <= 0 || (gameBoard.getCell(headX, headY-1).getType() != empty
		&& gameBoard.getCell(headX, headY - 1).getType() != border)) {
			crashed = true;
		}
		break;
	case south:
		if (snakeHead.getYPosition() >= gameBoard.getHeight() - 1 
			|| (gameBoard.getCell(headX, headY+1).getType() != empty
			&& gameBoard.getCell(headX, headY + 1).getType() != border)) {
			crashed = true;
		}
		break;
	case west:
		if (snakeHead.getXPosition() <= 0
			|| (gameBoard.getCell(headX-1, headY).getType() != empty 
			&& gameBoard.getCell(headX - 1, headY).getType() != border)) {
			crashed = true;
		}
		break;
	case east:
		if (snakeHead.getXPosition() >= gameBoard.getWidth() - 1 
			|| (gameBoard.getCell(headX+1, headY).getType() != empty
			&& gameBoard.getCell(headX + 1, headY).getType() != border)){
			crashed = true;
		}
		break;
	default:
		break;
	}

	return crashed;
}

void Game::updateSnake()
{
	for (int i = 0; i < snake.size(); i++) {
		this->moveSnake(snake[i]);
	}
}

void Game::moveSnake(Cell* cell)
{
	int x1 = cell->getXPosition();
	int y1 = cell->getYPosition();
	int x2 = x1;
	int y2 = y1;

	switch (cell->getDirection()) {
	case north:
		y2 -= 1;
		break;
	case south:
		y2 += 1;
		break;
	case east:
		x2 += 1;
		break;
	case west:
		x2 -= 1;
		break;
	}

	gameBoard.swapCell(x1, y1, x2, y2);
	cell->setPosition(x2, y2);
}

void Game::renderWindow()
{
	//Sets the window Color
	this->window->clear(sf::Color(0, 115, 115, 255));

}

void Game::renderBoard()
{
	//Draws the cells onto the board
	Cell cell;
	cellType type;
	sf::RectangleShape bodyPart;
	for (int i = 0; i < this->gameBoard.getHeight(); i++) {
		for (int j = 0; j < this->gameBoard.getWidth(); j++) {
			cell = gameBoard.getCell(j, i);
			switch (cell.getType()) {
			case head:
				bodyPart = this->snakeHeadPiece;
				break;
			case body:
				bodyPart = this->snakeBodyPiece;
				break;
			case tail:
				bodyPart = this->snakeTailPiece;
				break;
			case border:
				bodyPart.setFillColor(sf::Color::Black);
				break;
			default:
				bodyPart.setFillColor(sf::Color::Transparent);
				break;
			}
			bodyPart.setSize(sf::Vector2f(25.f, 25.f));
			bodyPart.setPosition(j * 25.0, i * 25.0);
			this->window->draw(bodyPart);
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->updateTarget();
	this->updateSnake();
	//std::cout << snakeHead.getXPosition() << " " << snake[0].getXPosition() << " " << snakeHead.getDirection() << "??";
	
}

void Game::render()
{
	this->renderWindow();
	this->renderBoard();
	this->window->display();
}
