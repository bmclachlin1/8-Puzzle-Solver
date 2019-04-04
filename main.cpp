//**************************************************
//Name: Blake McLachlin
//Last Date Revised: April 03, 2019
//Program: main.cpp
//Purpose: Test program for sliding puzzle solver
//**************************************************

#include "BinaryHeap.h"
#include "Board_Tile.h"
#include "Sliding_Solver.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cout << "--Testing Sliding Tiles--\n\n";
	string config = "436871052";
	string config2 = "123745086";
	string goal = "123456780";
	string goal2 = "123456780";
	Board_Tile bt1(config);
	Board_Tile bt2(config2);
	Board_Tile goalconfig(goal);
	Board_Tile goalconfig2(goal2);
	Sliding_Solver solver1(config, goal);
	Sliding_Solver solver2(config2, goal2);

	cout << "\nStart Board \n";
	bt1.printBoard();
	cout << "\nGoal Board \n";
	goalconfig.printBoard();
    cout << "\n--Testing Solver--\n\n";
	solver1.Solve_Puzzle();

	cout << "Start Board\n";
	bt2.printBoard();
	cout << "\nGoal Board\n";
	goalconfig2.printBoard();
	cout << "\n--Testing Solver--\n\n";
	solver2.Solve_Puzzle();

	cin.get();
}
