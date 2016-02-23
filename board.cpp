#include "Board.h"

// constructor
board::board()
{
	waves.resize(10); // do not remove
	myWaters.resize(10);
	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			waves[i].push_back(" ~");
			myWaters[i].push_back(" ~");
		}
	}
}

// destructor
board::~board()
{}

board play1;
board play2;

// start
// standing in for main
void board::start()
{
	cout << "Set board for PLAYER 1\n" << endl;
	play1.setBoard(5);
	play1.setBoard(4);
	play1.setBoard(3);
	play1.setBoard(3);
	play1.setBoard(2);

	cout << "Set board for PLAYER 2\n" << endl;
	play2.setBoard(5);
	play2.setBoard(4);
	play2.setBoard(3);
	play2.setBoard(3);
	play2.setBoard(2);
}

// setBoard
// for setting ships
void board::setBoard(int shipSize)
{
	int xCoord, yCoord;
	string orient, input;
	bool valid = false, restart = false;

	do
	{
		cout << "To restart at any time during setup: R" << endl;

		cout << "Place ";
		switch (shipSize)
		{
			case 5:
				cout << "Carrier";
				break;

			case 4:
				cout << "Battleship";
				break;

			case 3:
				cout << "Crusier/Submarine";
				break;

			case 2:
				cout << "Destroyer";
				break;

			default: // should NEVER get here
				cout << "What. Have. You. DONE!?" << endl;
				break;
		}
		cout << " (size " << shipSize << ")" << endl;

		do
		{
			cout << "Horizontal: ";
			getline(cin, input);
			if (input[0] == 'r' || input[0] == 'R') // checks for r
			{
				restart = true;
				break;
			}
			else if (isdigit(input[0])) // attempts conversion if digit found
			{
				xCoord = stoi(input);
			}
			else // sets xCoord OOB otherwise
			{
				xCoord = -1;
			}
		}
		while (xCoord >= 0 && xCoord < 10);

		if (!restart)
		{
			do
			{
				cout << "Vertical: ";
				getline(cin, input);
				if (input[0] == 'r' || input[0] == 'R') // checks for r
				{
					restart = true;
					break;
				}
				else if (isdigit(input[0])) // attempts conversion if digit found
				{
					yCoord = stoi(input);
				}
				else // sets yCoord OOB otherwise
				{
					yCoord = -1;
				}
			} while (yCoord >= 0 && yCoord < 10);
		}
		
		if (!restart)
		{
			do
			{
				cout << "Would you like the ship to be HORIZONTAL or VERTICAL? (H or V): ";
				cin >> orient;
				if (orient[0] == 'r' || orient[0] == 'R')
				{
					restart = true;
					break;
				}
				else if (orient[0] == 'h' || orient[0] == 'H')
				{
					if (xCoord + shipSize <= 10)
					{ valid = true; }
				}
				else if (orient[0] == 'v' || orient[0] == 'V')
				{
					if (yCoord + shipSize <= 10)
					{ valid = true; }
				}
			} while (!valid);
		}
	}
	while (!restart);
	
	// NEED TO CHECK IF OVERLAP
	// NEED TO ACTUALLY LAY SOME SHIPS DOWN
	// NEED TO CONFIRM POSITION WITH USER
}

// isShip
// returns a bool indicating whether or not a ship is at
// the specified coordinates
bool board::isShip(int x, int y)
{
	if (myWaters[x][y] != " ~")
	{
		return true;
	}
	return false;
}

void board::printBoard() // need to figure out all the places to call this
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";
		for (int ii = 0; ii < 10; ++ii)
		{ cout << play1.waves[i][ii]; }
		cout << " |" << endl;
	}
	cout << "      ---------------------" << endl;
}