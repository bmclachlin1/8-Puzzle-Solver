//**************************************************
//Name: Blake McLachlin
//Last Date Revised: March 22, 2019
//Program: Sliding_Solver.h
//Purpose: Header file for Sliding_Solver.cpp
//**************************************************

#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H

#include "BinaryHeap.h"
#include "Board_Tile.h"
#include <string>
using namespace std;

class Sliding_Solver
{
public:
	//constructor
	explicit Sliding_Solver(const string& startConfig);

	//Uses A* search to solve the puzzle. Returns a string of the moves to solve the puzzle. 
	string Solve_Puzzle();

private:
	//MinHeap used to store nextConfigs of Board Tile's
	BinaryHeap<Board_Tile> tileQueue;

	//the start configuration
	string startConfig;
};

#endif