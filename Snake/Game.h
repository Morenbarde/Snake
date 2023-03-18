#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "Board.h"

class Game
{
private:
	//private variables
		
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::RectangleShape snakeHeadPiece;
	sf::RectangleShape snakeBodyPiece;
	sf::RectangleShape snakeTailPiece;

	int windowHeight;
	int windowWidth;

	Board gameBoard;

	Cell snakeHead;
	Cell snakeTail;

	Cell target;

	std::vector<Cell*> snake;



	//Private Functions
	void initVariables();
	void initWindow();
	void initBoard();
	void initSnake();


public:
	
	//constructors and destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	int getWindowHeight();
	int getWindowWidth();
	
	//Functions
	void pollEvents();
	void updateTarget();

	bool checkCrash();
	void updateSnake();
	void moveSnake(Cell* cell);

	void renderWindow();
	void renderBoard();

	void update();
	void render();
};

