//**************************************************
//Name: Blake McLachlin
//Last Date Revised: March 22, 2019
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
	cout << "Testing Sliding Tiles\n\n";

	string config = "123745086";
	string goal = "123456780";

	Board_Tile goalconfig(goal);
	cout << "Goal Board \n";
	goalconfig.printBoard();

	Board_Tile bt1(config);
	cout << "Initial Board \n";
	cout << "EC: " << bt1.Manhattan_Distance(goalconfig) << "\n";
	cout << "AC: " << bt1.getAC() << "\n";
	cout << "movesFromStart: " << bt1.getMovesFromStart() << "\n";
	cout << "moves: " << bt1.getMoves() << "\n";
	bt1.printBoard();



	vector<Board_Tile> test;
	test = bt1.nextConfigs();
	cout << "Next Configs \n\n";
	for (int i = 0; i < test.size(); i++) {
		cout << "EC: " << test[i].Manhattan_Distance(goalconfig) << "\n";
		cout << "AC: " << test[i].getAC() << "\n";
		cout << "movesFromStart: " << test[i].getMovesFromStart() << "\n";
		cout << "moves: " << test[i].getMoves() << "\n";
		test[i].printBoard();
	}

    cout << "Test \n\n";

	Sliding_Solver solver(config, goal);
	string s1;
	s1 = solver.Solve_Puzzle();
	cout << s1 << "\n";

	cin.get();
}
