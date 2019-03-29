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
	
	string config = "483157026";
	string config2 = "123745086";
	string goal = "123456780";

	Board_Tile bt1(config);
	Board_Tile bt2(config2);
	Board_Tile goalconfig(goal);

	bt1.printBoard();
	bt2.printBoard();
	goalconfig.printBoard();

	int md1, md2;
	md1 = bt1.Manhattan_Distance(goalconfig);
	md2 = bt2.Manhattan_Distance(goalconfig);

	cout << "md1 " << md1 << endl << "md2 " << md2 << endl;

	if (bt1 < bt2)
		cout << "bt1 has a lesser manhattan distance than bt2" << endl;
	else
		cout << "bt1 has a greater manhattan distance than bt2" << endl;

	cin.get();
}