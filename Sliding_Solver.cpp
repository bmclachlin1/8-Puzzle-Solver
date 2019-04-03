//**************************************************
//Name: Blake McLachlin
//Last Date Revised: March 22, 2019
//Program: Sliding_Solver.h
//Purpose: Implements Sliding_Solver.h
//Solves a 3x3 sliding puzzle problem using A*
//search
//**************************************************

#include "Sliding_Solver.h"
using namespace std;

Sliding_Solver::Sliding_Solver(const string& start, const string& goal)
{
	Board_Tile sc(startConfig);
	startConfig = sc;
	Board_Tile gc(goal);
	goalConfig = gc;
	vector<Board_Tile> next;
	next = sc.nextConfigs();
	for(int i = 0; i < next.size(); i++)
        tileQueue.insert(next[i]);
}

string Sliding_Solver::Solve_Puzzle()
{
    int counter = 0;
    while(tileQueue.findMin() != goalConfig && counter!=10)
    {
        Board_Tile temp = tileQueue.findMin();
        cout << "Deleting min...\n";
        temp.printBoard();
        cout << "A(C): " << temp.getAC();
        cout << "E(C): " << temp.Manhattan_Distance(goalConfig);
        cout << "D(C): = A(C) + E(C): " << temp.getDC() << "\n\n";
        tileQueue.deleteMin();
        vector<Board_Tile> next;
        next = temp.nextConfigs();
        cout << "Next Configs\n\n";
        for (int i = 0; i < next.size(); i++) {
            next[i].printBoard();
            cout << "A(C): " << next[i].getAC();
            cout << "E(C): " << next[i].Manhattan_Distance(goalConfig) << "\n";
            cout << "D(C) = A(C) + E(C): " << next[i].getDC() << "\n";
            tileQueue.insert(next[i]);
        }
    }
    Board_Tile solution = tileQueue.findMin();
    return solution.getMovesFromStart();
    cout << "\n\n";
}
