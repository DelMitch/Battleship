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

void board::intro()
{
	cout << "Glad you could make it, Captains.\n" << endl;

	cout << "The two of you have been selected to participate in an Experimental Training Program.\n" << endl;

	cout << endl;

	cout << "Tactical Brief:\n"
		<< "\tA Lieutenant will be assigned to each of you, they will keep you updated on the results\n"
		<< "\tof your commands and prompt you for coordinates.\n" << endl;

	cout << "\tEach Captain is responsible for five ships:\n"
		<< "\t\t1 Carrier\t5 shots to sink\n"
		<< "\t\t1 Battleship\t4 shots to sink\n"
		<< "\t\t2 Cruisers\t3 shots to sink\n"
		<< "\t\t1 Destroyer\t2 shots to sink\n" << endl;

	cout << "\tYou will place each ship horizontally or vertically within the boundaries of a 10 x 10 grid.\n"
		<< "\tThe location each ship is placed in is entirely up to you.\n" << endl;

	cout << "Terms of Engagement:\n"
		<< "\tYou will take turns shooting into your opponent's field.\n"
		<< "\tYou will be shooting blind; you won't know where your oppenent's ships are until you hit them.\n"
		<< "\tWhoever sinks all five of their opponent's ships first will be declared the Victor.\n" << endl;

	cout << "\n\n\n\n\nPress ENTER to continue..." << endl;
	getchar();

	cout << "WELCOME TO\n" << endl;

	cout << "\t__________    ____________________________.____     ___________ _________ ___ ___ ._____________ \n"
		<< "\t\\______   \\  /  _  \\__    ___ /\\__    ___/|    |    \\_   _____//   _____//   |   \\|   \\______   \\ \n"
		<< "\t |    |  _/ /  /_\\  \\|    |      |    |   |    |     |    __)_ \\_____  \\/    ~    \\   ||     ___/\n"
		<< "\t |    |   \\/    |    \\    |      |    |   |    |___  |        \\/        \\    Y    /   ||    |\n"
		<< "\t |______  /\\____|__  /____|      |____|   |_______ \\/_______  /_______  /\\___|_  /|___||____|\n"
		<< "\t        \\/          \\/                            \\/        \\/        \\/       \\/\n" << endl;

	cout << "\t\t                                      |__\n"
		<< "\t\t                                      |\\/\n"
		<< "\t\t                                      ---\n"
		<< "\t\t                                      / | [\n"
		<< "\t\t                              !       | |||\n"
		<< "\t\t                            _/|     _ /|-++'\n"
		<< "\t\t                        +  +--|    |--|--|_ |-\n"
		<< "\t\t                     { /|__|  |/\\_ _|  |--- |||__/'\n"
		<< "\t\t                    +---------------___[}-_===_.'____                  /\\\n"
		<< "\t\t                ____`-' ||___-{]_| _[}-  |     |_[___\==--              \\/   _\n"
		<< "\t\t __..._____--==/___]_|__|_____________________________[___\ == --____,------' .7\n"
		<< "\t\t|                                                                    BB - 64 /'\n"
		<< "\t\t \\__________________________________________________________________________|'" << endl;

	cout << "\n\n\n\n\nPress ENTER to continue..." << endl;
	getchar();
	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
}

// start
// standing in for main
void board::start()
{
	intro();

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
			cout << "X-Coordinate: ";
			getline(cin, input);
			if (input[0] == 'r' || input[0] == 'R' || input[0] == '\n') // checks for r
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
		while (xCoord < 0 && xCoord >= 10);

		if (!restart)
		{
			do
			{
				cout << "Y-Coordinate: ";
				getline(cin, input);
				if (input[0] == 'r' || input[0] == 'R' || input[0] == '\n') // checks for r
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
			} while (yCoord < 0 && yCoord >= 10);
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
				else if (orient[0] == 'v' || orient[0] == 'V')
				{
					if (xCoord + shipSize <= 10)
					{ valid = true; }
				}
				else if (orient[0] == 'h' || orient[0] == 'H')
				{
					if (yCoord + shipSize <= 10)
					{ valid = true; }
				}
			} while (!valid);
		}

		if (!restart)
		{
			
			if (orient[0] == 'v' || orient[0] == 'V')
			{
				for (int i = 0; i < shipSize; ++i)
				{
					if (isShip(xCoord + i, yCoord))
					{ restart = true; }
				}
			}
			else if (orient[0] == 'h' || orient[0] == 'H')
			{
				for (int ii = 0; ii < shipSize; ++ii)
				{
					if (isShip(xCoord, yCoord + ii))
					{ restart = true; }
				}
			}
			
			if (restart == true)
			{ cout << "You cannot place your ship there, SIR." << endl; }
		}
		if (!restart)
		{
			if (orient[0] == 'v' || orient[0] == 'V')
			{
				for (int i = 0; i < shipSize; ++i)
				{
					myWaters[xCoord][yCoord + i] = " +";
				}
			}
			else if (orient[0] == 'h' || orient[0] == 'H')
			{
				for (int ii = 0; ii < shipSize; ++ii)
				{
					myWaters[xCoord + 1][yCoord] = " +";
				}
			}
		}
	// NEED TO CONFIRM POSITION WITH USER
	}
	while (!restart);
}

// isShip
// returns a bool indicating whether or not a ship is at
// the specified coordinates
bool board::isShip(int x, int y)
{
	if (myWaters[x][y] != " ~")
	{ return true; }
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
		{ cout << play1.myWaters[i][ii]; }
		cout << " |" << endl;
	}
	cout << "      ---------------------" << endl;
}