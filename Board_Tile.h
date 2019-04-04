//**************************************************
//Name: Blake McLachlin
//Last Date Revised: April 03, 2019
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
	//constructor.
	//Param:	- s: the board configuration
	//			- steps: the sequence of steps to reach this board configuration
	//			- init: value of AC
	explicit Board_Tile(const string& s = "0123456789", const string& steps = "", const int& init = 0);

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

	//returns DC
	int getDC();

	//returns AC
	int getAC();

	//returns EC
	int getEC();

	//returns the string movesFromStart
	string getMovesFromStart();

	//Updates the string movesFromStart and update moves
	void updateMoves(const char& c);

	//returns config[i]
	char operator[] (const int& i) const;

	//overloaded equals operator
	bool operator== (const Board_Tile& rhs) const;

	//overloaded not equals operator
	bool operator!= (const Board_Tile& rhs) const;

	//overloaded less-than operator
	bool operator< (const Board_Tile& rhs) const;

	//overloaded greater-than
	bool operator> (const Board_Tile& rhs) const;

	//overloaded less-than or equal operator
	bool operator<= (const Board_Tile& rhs) const;

	//overloaded greater-than or equal operator
	bool operator>= (const Board_Tile& rhs) const;

private:
	//Represents a 3x3 tile board in row-major order
	string config;

	//A list of Board Tile at most 4 objects that are one move away from the current object
	vector<Board_Tile> nextConfig;

	//Represents moves or steps that lead to config from a given start configuration
	string movesFromStart;

	//number of moves taken. Equal to movesFromStart.length()
	int moves;

	//Stores the index of config that has 0 (config[i] == '0').
	int indexAtZero;

	//Heuristic
	int DC;

	//Manhattan Distance used to estimate the number of moves needed to reach the goal from configuration C.
	int EC = 0;

	//Number of moves needed to reach configuration C from the start configuration
	int AC;
};

#endif
