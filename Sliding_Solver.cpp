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
    while(tileQueue.findMin().getConfig() != goalConfig && counter != 5000)
    {
		counter++;
        Board_Tile temp = tileQueue.findMin();
		temp.getAC();
		temp.Manhattan_Distance(Board_Tile(goalConfig));
		temp.getDC();
        tileQueue.deleteMin();
        vector<Board_Tile> next;
        next = temp.nextConfigs();
        for (unsigned int i = 0; i < next.size(); i++) {
			next[i].getAC();
			next[i].Manhattan_Distance(Board_Tile(goalConfig));
			next[i].getDC();
            tileQueue.insert(next[i]);
        }
    }
    Board_Tile solution = tileQueue.findMin();
	if (solution.getConfig() == goalConfig)
	{
		return solution.getMovesFromStart();
	}
	else
	{
		return "No Solution";
	}
}
