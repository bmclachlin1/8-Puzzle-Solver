//**************************************************
//Name: Blake McLachlin
//Last Date Revised: April 03, 2019
//Program: Sliding_Solver.h
//Purpose: Implements Sliding_Solver.h
//Solves a 3x3 sliding puzzle problem using A*
//search
//**************************************************

#include "Sliding_Solver.h"
using namespace std;

Sliding_Solver::Sliding_Solver(const string& start, const string& goal)
	:startConfig(start), goalConfig(goal)
{
	Board_Tile initial(startConfig);
	vector<Board_Tile> next;
	next = initial.nextConfigs();
	for(unsigned int i = 0; i < next.size(); i++)
        tileQueue.insert(next[i]);
}

string Sliding_Solver::Solve_Puzzle()
{
    int counter = 0;
	//counter in case no solution exists and loop does not terminate
    while(tileQueue.findMin().getConfig() != goalConfig && counter!=2500)
    {
		counter++;
        Board_Tile temp = tileQueue.findMin();
		temp.getAC();
		temp.Manhattan_Distance(Board_Tile(goalConfig));
		temp.getDC();
		/*
        cout << "Deleting min...\n";
        temp.printBoard();
		cout << "A(C): " << temp.getAC() << "\n";
        cout << "E(C): " << temp.Manhattan_Distance(Board_Tile(goalConfig)) << "\n";
        cout << "D(C): = A(C) + E(C): " << temp.getDC() << "\n";
		cout << "moves from start: " << temp.getMovesFromStart() << "\n";
		cout << "moves: " << temp.numMoves() << "\n\n";
		*/
        tileQueue.deleteMin();
        vector<Board_Tile> next;
        next = temp.nextConfigs();
        //cout << "Next Configs\n";
        for (unsigned int i = 0; i < next.size(); i++) {
			next[i].getAC();
			next[i].Manhattan_Distance(Board_Tile(goalConfig));
			next[i].getDC();
			/*
            cout << "A(C): " << next[i].getAC() << "\n";
            cout << "E(C): " << next[i].Manhattan_Distance(Board_Tile(goalConfig)) << "\n";
            cout << "D(C) = A(C) + E(C): " << next[i].getDC() << "\n";
			cout << "moves from start: " << next[i].getMovesFromStart() << "\n";
			cout << "moves: " << next[i].numMoves() << "\n\n";
			*/
            tileQueue.insert(next[i]);
        }
    }
    Board_Tile solution = tileQueue.findMin();
	if (solution.getConfig() == goalConfig)
	{
		cout << "Reached goal. Printing Board...\n\n";
		solution.printBoard();
		cout << "A(C): " << solution.getAC() << "\n";
		cout << "E(C): " << solution.getEC() << "\n";
		cout << "D(C) = A(C) + E(C): " << solution.getDC() << "\n";
		cout << "Number of Moves: " << solution.numMoves() << "\n";
		cout << "Moves to get there: " << solution.getMovesFromStart();
		cout << "\n\n";
		return solution.getMovesFromStart();
	}
	else
	{
		cout << "Couldn't reach goal.\n";
		return "";
	}
}
