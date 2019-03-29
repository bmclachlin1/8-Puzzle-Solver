//**************************************************
//Name: Blake McLachlin
//Last Date Revised: March 22, 2019
//Program: Sliding_Solver.h
//Purpose: Represents 3x3 tile boards.
//**************************************************

#include "Board_Tile.h"
using namespace std;

Board_Tile::Board_Tile(const string &s)
	:config(s)
{
	assert(config.length() == 9);
	for (unsigned int i = 0; i < config.length(); i++)
		if (config[i] == '0')
			indexAtZero = i;
}

vector<Board_Tile> Board_Tile::nextConfigs()
{
	string newConfig = config;
	int iAtZero = indexAtZero;
	vector<Board_Tile> temp;

	if (canMoveInDirection('U')) {
		swap(newConfig[iAtZero], newConfig[iAtZero - 3]);
		temp.push_back(Board_Tile(newConfig));
		newConfig = config;
	}
	if (canMoveInDirection('D')) {
		swap(newConfig[iAtZero], newConfig[iAtZero + 3]);
		temp.push_back(Board_Tile(newConfig));
		newConfig = config;
	}
	if (canMoveInDirection('L')) {
		swap(newConfig[iAtZero], newConfig[iAtZero - 1]);
		temp.push_back(Board_Tile(newConfig));
		newConfig = config;
	}
	if (canMoveInDirection('R')) {
		swap(newConfig[iAtZero], newConfig[iAtZero + 1]);
		temp.push_back(Board_Tile(newConfig));
		newConfig = config;
	}

	return temp;
}

int Board_Tile::numMoves() const
{
	return 0;
}

int Board_Tile::Manhattan_Distance(const Board_Tile& goalconfig)
{
	if (this == &goalconfig)
		exit(0);

	md = 0;
	for (int i = 0; i < config.length(); i++)
		for (int j = 0; j < goalconfig.getConfig().length(); j++)
			if (config[i] == goalconfig[j] && config[i] != '0')
			{
				int xi = getXCoord(config[i]);
				int yi = getYCoord(config[i]);
				int xj = goalconfig.getXCoord(goalconfig[j]);
				int yj = goalconfig.getYCoord(goalconfig[j]);
				md += abs(xi - xj) + abs(yi - yj);
			}
	return md;
}

bool Board_Tile::canMoveInDirection(const char& c) const
{
	char temp = toupper(c);
	switch (temp)
	{
		case 'U':
			if (indexAtZero - 3 >= 0)
				return true;
			break;
		case 'D':
			if (indexAtZero + 3 <= 8)
				return true;
			break;
		case 'L':
			if (indexAtZero % 3 != 0)
				return true;
			break;
		case 'R':
			if (indexAtZero % 3 != 2)
				return true;
			break;
	}
	return false;
}

string Board_Tile::getConfig() const
{
	return config;
}

void Board_Tile::printString() const
{
	cout << config << "\n\n";
}

void Board_Tile::printBoard() const
{
	for (int rows = 0; rows < 3; rows++)
	{
		if(rows > 0)
			cout << "\n";
		for (int cols = 0; cols < 3; cols++)
			cout << config[rows * 3 + cols] << " ";
	}
	cout << "\n\n";
}

int Board_Tile::getXCoord(const char& num) const
{
	int indexAtNum;
	assert(num == '0' || num == '1' || num == '2' || num == '3' || num == '4' ||
		num == '5' || num == '6' || num == '7' || num == '8');
	for (int i = 0; i < config.length(); i++)
		if (config[i] == num)
			indexAtNum = i;
	if (indexAtNum % 3 == 0)
		return 0;
	else if (indexAtNum % 3 == 1)
		return 1;
	else
		return 2;
}

int Board_Tile::getYCoord(const char& num) const
{
	int indexAtNum;
	assert(num == '0' || num == '1' || num == '2' || num == '3' || num == '4' ||
		   num == '5' || num == '6' || num == '7' || num == '8');
	for (int i = 0; i < config.length(); i++)
		if (config[i] == num)
			indexAtNum = i;
	if (indexAtNum / 3 == 0)
		return 0;
	else if (indexAtNum / 3 == 1)
		return 1;
	else
		return 2;

}

char Board_Tile::operator[] (const int& i) const
{
	return config[i];
}

bool Board_Tile::operator< (const Board_Tile& rhs) const
{
    //should be D(C) = A(C) + E(C)
	return this->md < rhs.md;
}
