#include "Board.h"

board::board()
{
	waves.resize(10); // do not remove
	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{ waves[i].push_back(" ~"); }
	}
}

board::~board()
{}

void board::printBoard(board ocean)
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";
		for (int ii = 0; ii < 10; ++ii)
		{ cout << ocean.waves[i][ii]; }
		cout << " |" << endl;
	}
	cout << "      ---------------------" << endl;
}