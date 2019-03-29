//**************************************************
//Name: Blake McLachlin
//Last Date Revised: March 22, 2019
//Program: Board_Tile.h
//Purpose: Header file for Board_Tile.cpp
//**************************************************
#ifndef BOARD_TILE_H
#define BOARD_TILE_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cctype>
#include <cmath>
using namespace std;

class Board_Tile
{
public:
	//constructor
	explicit Board_Tile(const string& s = "0123456789");

	//returns a list of board tiles at most 4 objects that are one move away from the current object
	vector<Board_Tile> nextConfigs();

	//returns the number of moves it took from the initial board to reach the current configuration
	int numMoves() const;

	//takes a string representing the goal configuration and returns the manhattan distance of the
	//goal configuration
	int Manhattan_Distance(const Board_Tile& goalConfig);

	//Checks if 0 can move in the direction of c (c = U,D,L,R)
	bool canMoveInDirection(const char& c) const;

	//returns the config
	string getConfig() const;

	//prints the board as a string
	void printString() const;

	//prints the board in 2 dimensions
	void printBoard() const;

	//returns the x coordinate for an entry in config
	int getYCoord(const char& num) const;

	//returns the y coordinate for an entry in config
	int getXCoord(const char& num) const;

	//returns config[i]
	char operator[] (const int& i) const;

	//overloaded inequality operator
	bool operator< (const Board_Tile& rhs) const;

private:
	//Represents a 3x3 tile board in row-major order
	string config;

	//Represents moves or steps that lead to config from a given start configuration
	string movesFromStart;

	//Stores the index of config that has 0 (config[i] == '0').
	int indexAtZero;
	//Number of moves that lead to config from a given start configuration.
	//Always equal to movesFromStart.length()
	int moves;

	//manhattan distance
	int md;

	//number of columns
	const int NUM_ROWS = 3;
	//number of rows
	const int NUM_COLS = 3;
};

#endif
