// board.cpp
// Dain Harmon
// Addeline Mitchell
// Mar 1, 2016
//
// Battleship Project
// Group 7
//
// Source file for the 'board' class.

#include "Board.h"

// ctor
// creates a board object containing 2 different
// boards, 'myWaters' is what a player places their
// ships on during setup and 'waves' is what their
// opponent sees
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

// dctor
// destructs board objects
board::~board()
{}

board play1;
board play2;

// intro
// introduces game to players, shows rules
const void board::intro()
{
	cout << "\n\n\n WELCOME TO\n" << endl;

	cout << " __________    ____________________________.____     ___________ _________ ___ ___ ._____________ \n"
		<< " \\______   \\  /  _  \\__    ___ /\\__    ___/|    |    \\_   _____//   _____//   |   \\|   \\______   \\ \n"
		<< "  |    |  _/ /  /_\\  \\|    |      |    |   |    |     |    __)_ \\_____  \\/    ~    \\   ||     ___/\n"
		<< "  |    |   \\/    |    \\    |      |    |   |    |___  |        \\/        \\    Y    /   ||    |\n"
		<< "  |______  /\\____|__  /____|      |____|   |_______ \\/_______  /_______  /\\___|_  /|___||____|\n"
		<< "         \\/          \\/                            \\/        \\/        \\/       \\/\n" << endl;

	cout << "\t                                      |__\n"
		<< "\t                                      |\\/\n"
		<< "\t                                      ---\n"
		<< "\t                                      / | [\n"
		<< "\t                              !       | |||\n"
		<< "\t                            _/|     _ /|-++'\n"
		<< "\t                        +  +--|    |--|--|_ |-\n"
		<< "\t                     { /|__|  |/\\_ _|  |--- |||__/'\n"
		<< "\t                    +---------------___[}-_===_.'____                  /\\\n"
		<< "\t                ____`-' ||___-{]_| _[}-  |     |_[___\==--              \\/   _\n"
		<< "\t __..._____--==/___]_|__|_____________________________[___\ == --____,------' .7\n"
		<< "\t|                                                                    BB - 64 /'\n"
		<< "\t \\__________________________________________________________________________|'" << endl;

	cout << "\n\n\n\n Press ENTER to continue...";
	getchar();
	
	system("cls");
	
	cout << "\n\n Glad you could make it, Captains.\n" << endl;

	cout << " The two of you have been selected to participate in an Experimental Training Program.\n" << endl;

	cout << endl;

	cout << " Tactical Brief:\n"
		<< "     A Lieutenant will be assigned to each of you, they will keep you updated on the\n"
		<< "     results of your commands and prompt you for coordinates.\n" << endl;

	cout << "     Each Captain is responsible for five ships:\n"
		<< "         1 Carrier       5 shots to sink\n"
		<< "         1 Battleship    4 shots to sink\n"
		<< "         1 Cruiser       3 shots to sink\n"
		<< "         1 Submarine     3 shots to sink\n"
		<< "         1 Destroyer     2 shots to sink\n" << endl;

	cout << "     You will place each ship horizontally or vertically within the boundaries of\n"
		<< "     a 10 x 10 grid. The location each ship is placed in is entirely up to you.\n" << endl;

	cout << " Terms of Engagement:\n"
		<< "     You will take turns shooting into your opponent's field. You will be shooting\n"
		<< "     blind; you won't know where your oppenent's ships are until you hit them.\n"
		<< "     Whoever sinks all five of their opponent's ships first will be the Victor.\n" << endl;

	cout << "\n\n\n Press ENTER to continue...";
	getchar();

	system("cls");
}

// start
// initiates the very start of the game
// standing in for 'main' right now
const void board::start() // this is working fine, just need to include function call at the end to begin the game
{
	string response;
	bool isGood = false;

	intro();

	do
	{
		bool reset = false, correct = false;
		cout << "\n Requesting SETUP for CAPTAIN HONG.\n" << endl;
		cout << " To RESTART at any time during setup: R\n" << endl;

		play1.printWaters1();
		play1.setBoard(5);
		play1.printWaters1();

		play1.setBoard(4);
		play1.printWaters1();

		play1.setBoard(3);
		play1.printWaters1();

		play1.setBoard(3);
		play1.printWaters1();

		play1.setBoard(2);
		play1.printWaters1();

		do // confirms board with PLAYER 1
		{
			cout << "\n Requesting CONFIRMATION of locations, SIR? (Y or N): ";
			getline(cin, response);
			if (response[0] == 'y' || response[0] == 'Y')
			{
				correct = true;
				isGood = true;
				break;
			}
			else if (response[0] == 'n' || response[0] == 'N')
			{
				correct = true;
				reset = true;
				play1.resetWaters();
				system("cls");
			}
			else { cout << "\n\n REPEAT:" << endl; }
		}
		while (!reset);
	}
	while (!isGood);

	system("cls"); // this is so that player 2 can't cheat by scrolling up

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPASS INTERFACE TO OTHER CAPTAIN" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Press ENTER to continue...";
	getchar();

	system("cls"); // will try to find something better that will work on all (most?) systems

	isGood = false; // reset to false

	do
	{
		bool reset2 = false, correct2 = false;
		cout << "\n Requesting SETUP for CAPTAIN CHONG.\n" << endl;
		cout << " To restart at any time during setup: R\n" << endl;

		play2.printWaters2();
		play2.setBoard(5);
		play2.printWaters2();
		
		play2.setBoard(4);
		play2.printWaters2();
		
		play2.setBoard(3);
		play2.printWaters2();
		
		play2.setBoard(3);
		play2.printWaters2();
		
		play2.setBoard(2);
		play2.printWaters2();

		do // confirms board with PLAYER 2
		{
			cout << "\n Requesting CONFIRMATION of locations, SIR? (Y or N): ";
			getline(cin, response);
			if (response[0] == 'y' || response[0] == 'Y')
			{
				correct2 = true;
				isGood = true;
				break;
			}
			else if (response[0] == 'n' || response[0] == 'N')
			{
				correct2 = true;
				reset2 = true;
				play2.resetWaters();
				system("cls");
			}
			else { cout << "\n\n REPEAT:" << endl; }
		}
		while (!reset2);
	}
	while (!isGood);

	// start game //
}


// setBoard
// allows the users to place their ships
const void board::setBoard(const int& shipSize) // unless we find any bugs, this is golden
{
	bool isSet = false;
	do
	{
		int row, col;
		string orient, input;
		bool valid = false, restart = false;

		cout << "\n Requesting location for ";
		switch (shipSize)
		{
			case 5:
				cout << "CARRIER";
				break;

			case 4:
				cout << "BATTLESHIP";
				break;

			case 3:
				if (secondC == false) { cout << "CRUISER"; }
				else { cout << "SUBMARINE"; }
				break;

			case 2:
				cout << "DESTROYER";
				break;

			default: // should NEVER get here
				cout << "\n ABORT MISSION, REPEAT: ABORT MISSION!" << endl;
				break;
		}
		cout << ", SIR? (size " << shipSize << ")" << endl;

		do // request x-coordinate (column)
		{
			cout << "\n X-Coordinate: ";
			getline(cin, input);
			if (input[0] == 'r' || input[0] == 'R') // checks for r
			{
				restart = true;
				break;
			}
			else if (isdigit(input[0])) // attempts conversion if digit found
			{
				col = stoi(input);
				if (col < 0 || col >= 10)
				{
					cout << "\n '" << input << "' is INVALID, SIR. Try Again." << endl;
					restart = true; // start input over
					break;
				}
				break; // get out of this loop and use the value
			}
			else // sets row OOB otherwise
			{
				cout << "\n '" << input << "' is INVALID, SIR. Try Again." << endl;
				restart = true;
				break;
			}
		}
		while (!restart);

		if (!restart) // request y-coordinate (row)
		{
			do
			{
				cout << " Y-Coordinate: ";
				getline(cin, input);
				if (input[0] == 'r' || input[0] == 'R') // checks for r
				{
					restart = true;
					break;
				}
				else if (isdigit(input[0])) // attempts conversion if digit found
				{
					row = stoi(input);
					if (row < 0 || row >= 10)
					{
						cout << "\n '" << input << "' is INVALID, SIR. Try Again." << endl;
						restart = true; // start input over
						break;
					}
					break; // get out of this loop and use the value
				}
				else // sets col OOB otherwise
				{
					cout << "\n '" << input << "' is INVALID, SIR. Try Again." << endl;
					restart = true;
					break;
				}
			}
			while (!restart);
		}
		
		if (!restart) // request orientation
		{
			do
			{
				cout << "\n Should orientation be HORIZONTAL or VERTICAL, SIR? (H or V): ";
				getline(cin, orient);
				if (orient[0] == 'r' || orient[0] == 'R')
				{
					restart = true;
					break;
				}
				else if (orient[0] == 'v' || orient[0] == 'V')
				{
					if (row + shipSize <= 10) // checks vertical bounds
					{ valid = true; }
					else
					{
						cout << "\n That is OUT OF BOUNDS, SIR. Try Again.\n" << endl;
						restart = true;
						break;
					}
				}
				else if (orient[0] == 'h' || orient[0] == 'H')
				{
					if (col + shipSize <= 10) // checks horizontal bounds
					{ valid = true; }
					else
					{
						cout << "\n That is OUT OF BOUNDS, SIR. Try Again.\n" << endl;
						restart = true;
						break;
					}
				}
			}
			while (!valid); // allows orientation if not OOB
		}

		if (!restart)
		{
			if (orient[0] == 'v' || orient[0] == 'V')
			{
				for (int i = 0; i < shipSize; ++i)
				{
					if (isShip(row + i, col)) // checks if ship would overlap vertically with
					{ restart = true; } // one that has already been placed before placing it
				}
			}
			else if (orient[0] == 'h' || orient[0] == 'H')
			{
				for (int ii = 0; ii < shipSize; ++ii)
				{
					if (isShip(row, col + ii)) // checks if ship would overlap horizontally with
					{ restart = true; } // one that has already been placed before placing it
				}
			}
			if (restart == true) // if ship would overlap
			{ cout << "\n You cannot place your ship there, SIR.\n" << endl; }
		}

		if (!restart)
		{
			string boat;
			switch (shipSize) // so that the ships can be identified when sunk
			{
				case 5:
					boat = " a";
					break;

				case 4:
					boat = " b";
					break;

				case 3:
					if (secondC == false)
					{
						boat = " c";
						secondC = true; // for next cruiser
					}
					else
					{
						boat = " s";
						secondC = false; // for next time function is called
					}
					break;

				case 2:
					boat = " d";
					break;

				default: // should NEVER get here
					cout << "\n ABORT MISSION, REPEAT: ABORT MISSION!" << endl;
					break;
			}
			
			if (orient[0] == 'v' || orient[0] == 'V')
			{
				for (int i = 0; i < shipSize; ++i) // places vertical ships
				{ myWaters[row + i][col] = boat; }
				isSet = true;
			}
			else if (orient[0] == 'h' || orient[0] == 'H')
			{
				for (int ii = 0; ii < shipSize; ++ii) // places horizontal ships
				{ myWaters[row][col + ii] = boat; }
				isSet = true;
			}
		}
	}
	while (!isSet);
}


// isShip
// returns a bool indicating whether or not a ship is at
// the specified coordinates
const bool board::isShip(const int& x, const int& y)
{
	if (myWaters[x][y] != " ~")
	{ return true; }
	return false;
}


// printWaves1, printWaters1, printWaves2, printWaters2
// print functions for boards holding ships & boards hiding ships
const void board::printWaves1() // need to figure out all the places to call this
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

const void board::printWaves2() // need to figure out all the places to call this
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";
		for (int ii = 0; ii < 10; ++ii)
		{ cout << play2.waves[i][ii]; }
		cout << " |" << endl;
	}
	cout << "      ---------------------" << endl;
}

const void board::printWaters1() // need to figure out all the places to call this
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

const void board::printWaters2() // need to figure out all the places to call this
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";
		for (int ii = 0; ii < 10; ++ii)
		{ cout << play2.myWaters[i][ii]; }
		cout << " |" << endl;
	}
	cout << "      ---------------------" << endl;
}


// resetWaters
// clear ships from board, replace with 'water'
const void board::resetWaters()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			if (myWaters[i][ii] != " ~")
			{ myWaters[i][ii] = " ~"; }
		}
	}
}


// hit or miss function needed //

// function to identify a sunk ship needed //

// winstate function needed //