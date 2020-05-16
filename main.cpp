//**************************************************
//Name: Blake McLachlin
//Last Date Revised: April 03, 2019
//Program: main.cpp
//Purpose: Test program for sliding puzzle solver
//**************************************************

#include "BinaryHeap.h"
#include "Board_Tile.h"
#include "Sliding_Solver.h"
#include <iomanip>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
	string start, goal, solution, userinput;
	int moves;
	bool flag = false;

	while (!flag)
	{
		cout << "Enter a nine digit start configuration representing a 3x3 tile board: ";
		getline(cin, start);
		if (start.length() != 9)
			continue;

		cout << "Enter a nine digit goal configuration representing a 3x3 tile board: ";
		getline(cin, goal);
		if (goal.length() != 9)
			continue;

		Sliding_Solver solve(start, goal);

		auto startTime = high_resolution_clock::now();
		solution = solve.Solve_Puzzle();
		auto stopTime = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stopTime - startTime);

		if (solution != "No Solution")
			moves = solution.length();
		else
			moves = 0;

		cout << "\n";
		cout << left << setw(20) << "Start Board" << setw(20) << "Goal Board" << setw(20) << "Number of moves" << setw(20) << "Solution";
		cout << "\n\n";
		cout << left << setw(20) << start << setw(20) << goal << setw(20) << moves << setw(20) << solution << "\n\n";
		cout << "Time to solve: " << duration.count() / 1000.0 << " seconds\n\n";
		cout << "Would you like to continue? Enter 0 to exit and any other key to continue: ";
		getline(cin, userinput);
		if (userinput == "0")
			flag = true;
		cout << "\n\n";
	}

	return 0;
}
