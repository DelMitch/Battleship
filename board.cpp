// board.cpp
// Dain Harmon
// Addeline Mitchell
// Mar 4, 2016
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

board play1, play2;

// clear
// prints 300 new lines, alternative to [system("cls");]
// used to prevent cheating via scrolling, unfortunately
// the limitations of this method are such that the users
// can simply change the buffer size of the console by
// right-clicking the title bar and changing the setting
// in the properties menu to render this useless
const void board::clear()
{
	for (int i = 0; i < 30; ++i) // angst
	{ cout << "\n\n\n\n\n\n\n\n\n" << endl; }
}

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
		<< "         \\/         \\/                             \\/        \\/        \\/       \\/\n" << endl;

	cout << "\t                                      |__\n"
		<< "\t                                      |\\/\n"
		<< "\t                                      ---\n"
		<< "\t                                      / | [\n"
		<< "\t                              !       | |||\n"
		<< "\t                            _/|     _ /|-++'\n"
		<< "\t                        +  +--|    |--|--|_ |-\n"
		<< "\t                     { /|__|  |/\\_ _|  |--- |||__/'\n"
		<< "\t                    +---------------___[}-_===_.'____                   /\\\n"
		<< "\t                ____`-' ||___-{]_| _[}-  |     |_[___\\==--              \\/   _\n"
		<< "\t __..._____--==/___]_|__|_____________________________[___\\ == --____,------' .7\n"
		<< "\t|                                                                    BB - 64 /'\n"
		<< "\t \\__________________________________________________________________________|'" << endl;

	cout << "\n\n\n\n Press ENTER to continue...";
	getchar();
	
	cout << "\n\n Glad you could make it, Captains.\n" << endl;

	cout << " The two of you have been selected to participate "
		 << "in an Experimental Training Program.\n" << endl << endl;

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

	cout << "\n\n\n\n Press ENTER to continue...";
	getchar();

	clear(); // for convenience
}

// start
// initiates the very start of the game
const void board::start()
{
	string response;
	bool isGood = false;

	intro();

	do
	{
		bool reset = false;

		cout << "\n LIEUTENANT RED requesting SETUP for CAPTAIN HONG.\n" << endl;
		cout << " To RESTART at any time during setup: R\n\n\n\n\n\n\n\n" << endl;

		// PLAYER 1 sets their ships
		play1.printWaters();
		play1.setBoard(5);
		play1.printWaters();

		play1.setBoard(4);
		play1.printWaters();

		play1.setBoard(3);
		play1.printWaters();

		play1.setBoard(3);
		play1.printWaters();

		play1.setBoard(2);
		play1.printWaters();

		do // confirms board with PLAYER 1
		{
			cout << "\n Requesting CONFIRMATION of locations, SIR? (Y or N): ";
			getline(cin, response);
			if (response[0] == 'y' || response[0] == 'Y')
			{
				isGood = true;
				break;
			}
			else if (response[0] == 'n' || response[0] == 'N')
			{
				reset = true;
				play1.resetWaters();
				clear(); // for convenience
			}
			else { cout << "\n\n REPEAT:" << endl; }
		}while (!reset);
	}while (!isGood);

	clear(); // this is so that PLAYER 2 can't cheat by scrolling up

	cout << "\t\t\tPASS INTERFACE TO OTHER CAPTAIN" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Press ENTER to continue...";
	getchar();

	clear(); // for convenience

	isGood = false; // reset to false

	do
	{
		bool reset2 = false;

		cout << "\n LIEUTENANT BLUE requesting SETUP for CAPTAIN CHONG.\n" << endl;
		cout << " To restart at any time during setup: R\n\n\n\n\n\n\n\n" << endl;

		// PLAYER 2 sets their ships
		play2.printWaters();
		play2.setBoard(5);
		play2.printWaters();
		
		play2.setBoard(4);
		play2.printWaters();
		
		play2.setBoard(3);
		play2.printWaters();
		
		play2.setBoard(3);
		play2.printWaters();
		
		play2.setBoard(2);
		play2.printWaters();

		do // confirms board with PLAYER 2
		{
			cout << "\n Requesting CONFIRMATION of locations, SIR? (Y or N): ";
			getline(cin, response);
			if (response[0] == 'y' || response[0] == 'Y')
			{
				isGood = true;
				break;
			}
			else if (response[0] == 'n' || response[0] == 'N')
			{
				reset2 = true;
				play2.resetWaters();
				clear(); // for convenience
			}
			else { cout << "\n\n REPEAT:" << endl; }
		}while (!reset2);
	}while (!isGood);

	clear(); // this is so that PLAYER 1 can't cheat by scrolling up

	cout << " -- WAR SIMLULATION INITIATED --" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";

	fireMissile1(); // START GAME
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
			else // row OOB otherwise
			{
				cout << "\n '" << input << "' is INVALID, SIR. Try Again." << endl;
				restart = true;
				break;
			}
		}while (!restart);

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
				else // col OOB otherwise
				{
					cout << "\n '" << input << "' is INVALID, SIR. Try Again." << endl;
					restart = true;
					break;
				}
			}while (!restart);
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
			}while (!valid); // allows orientation if not OOB
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
						secondC = true; // for next ship of size 3
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
	}while (!isSet);
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


// printWaves, printWaters
// print functions for board holding ships & board hiding ships
const void board::printWaves()
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;

	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";

		for (int ii = 0; ii < 10; ++ii)
		{ cout << waves[i][ii]; }

		cout << " |" << endl;
	}

	cout << "      ---------------------" << endl;
}

const void board::printWaters()
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;

	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";

		for (int ii = 0; ii < 10; ++ii)
		{ cout << myWaters[i][ii]; }

		cout << " |" << endl;
	}

	cout << "      ---------------------" << endl;
}


// resetWaters
// clear all marks from boards, replace with 'water'
const void board::resetWaters()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			if (myWaters[i][ii] != " ~")
			{
				myWaters[i][ii] = " ~";
				waves[i][ii] = " ~";
			}
		}
	}
}


// fireMissile1, fireMissile2
// requests coordinates from play1 and play2 respectively, then
// launches missile when input is valid and verifies hit or miss
const void board::fireMissile1()
{
	string input;
	bool shoot = false;
	int col, row;

	do
	{
		bool restart = false;
		do // request x-coordinate (column)
		{
			cout << "\n L.T. RED: CAPTAIN HONG -- fire when ready, SIR." << endl;

			play2.printWaves();

			cout << "\n X-Coordinate: ";

			getline(cin, input);

			if (isdigit(input[0])) // attempts conversion if digit found
			{
				col = stoi(input);

				if (col < 0 || col >= 10)
				{
					cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

					restart = true; // start input over
					break;
				}
				break; // get out of this loop and use the value
			}
			else // sets row OOB otherwise
			{
				cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

				restart = true;
				break;
			}
		}while (!restart);

		if (!restart) // request y-coordinate (row)
		{
			do
			{
				cout << " Y-Coordinate: ";

				getline(cin, input);

				if (isdigit(input[0])) // attempts conversion if digit found
				{
					row = stoi(input);

					if (row < 0 || row >= 10)
					{
						cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

						restart = true; // start input over
						break;
					}
					else if (play2.waves[row][col] == " O" || play2.waves[row][col] == " X")
					{ // if coordinates have already been used
						cout << "\n Oh Captain, my Captain: a missile has already been fired "
							 <<"there,\n no need to send another, SIR. Try again.\n" << endl;

						restart = true;
						break; // start input over
					}
					shoot = true; // at this point, both coords are valid, so we can use them
					break; // get out of this loop and use the value
				}
				else // sets col OOB otherwise
				{
					cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

					restart = true;
					break;
				}
			}while (!restart);
		}
	}while (!shoot);

	if (play2.myWaters[row][col] == " ~") // miss
	{
		play2.waves[row][col] = " O";
		play2.printWaves();

		cout << "\n MISS: no sign of a ship at "
			 << "those coordinates, SIR.\n\n" << endl;
	}
	else if (play2.myWaters[row][col] == " a") // hit aircraft carrier
	{
		--carLife2;

		play2.waves[row][col] = " X";
		play2.printWaves();

		if (carLife2 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "CARRIER has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play2.myWaters[row][col] == " b") // hit battleship
	{
		--batLife2;

		play2.waves[row][col] = " X";
		play2.printWaves();

		if (batLife2 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "BATTLESHIP has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play2.myWaters[row][col] == " c") // hit cruiser
	{
		--cruLife2;

		play2.waves[row][col] = " X";
		play2.printWaves();

		if (cruLife2 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "CRUISER has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play2.myWaters[row][col] == " s") // hit submarine
	{
		--subLife2;

		play2.waves[row][col] = " X";
		play2.printWaves();

		if (subLife2 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "SUBMARINE has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play2.myWaters[row][col] == " d") // hit destroyer
	{
		--desLife2;

		play2.waves[row][col] = " X";
		play2.printWaves();

		if (desLife2 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "DESTROYER has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}

	if (play2.allSunk()) // check for win state
	{ winState(true); }
	else
	{
		cout << "\n\n\n\n Press ENTER to continue...";
		getchar();

		fireMissile2();
	}
}

const void board::fireMissile2() // for player2 to hit player1's board
{
	string input;
	bool shoot = false;
	int col, row;

	do
	{
		bool restart = false;
		do // request x-coordinate (column)
		{
			cout << "\n L.T. BLUE: CAPTAIN CHONG -- fire when ready, SIR." << endl;

			play1.printWaves();

			cout << "\n X-Coordinate: ";

			getline(cin, input);

			if (isdigit(input[0])) // attempts conversion if digit found
			{
				col = stoi(input);

				if (col < 0 || col >= 10)
				{
					cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

					restart = true; // start input over
					break;
				}
				break; // get out of this loop and use the value
			}
			else // sets row OOB otherwise
			{
				cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

				restart = true;
				break;
			}
		}while (!restart);

		if (!restart) // request y-coordinate (row)
		{
			do
			{
				cout << " Y-Coordinate: ";

				getline(cin, input);

				if (isdigit(input[0])) // attempts conversion if digit found
				{
					row = stoi(input);

					if (row < 0 || row >= 10)
					{
						cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

						restart = true; // start input over
						break;
					}
					else if (play1.waves[row][col] == " O" || play1.waves[row][col] == " X")
					{ // if coordinates have already been used
						cout << "\n Oh Captain, my Captain: a missile has already been fired "
							 << "there,\n no need to send another, SIR. Try again.\n" << endl;

						restart = true;
						break; // start input over
					}
					shoot = true; // at this point, both coords are valid, so we can use them
					break; // get out of this loop and use the value
				}
				else // sets col OOB otherwise
				{
					cout << "\n '" << input << "' is INVALID, SIR. Try Again.\n" << endl;

					restart = true;
					break;
				}
			}while (!restart);
		}
	}while (!shoot);

	if (play1.myWaters[row][col] == " ~") // miss
	{
		play1.waves[row][col] = " O";
		play1.printWaves();

		cout << "\n MISS: no sign of a ship at "
			 << "those coordinates, SIR.\n\n" << endl;
	}
	else if (play1.myWaters[row][col] == " a") // hit aircraft carrier
	{
		--carLife1;

		play1.waves[row][col] = " X";
		play1.printWaves();

		if (carLife1 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "CARRIER has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play1.myWaters[row][col] == " b") // hit battleship
	{
		--batLife1;

		play1.waves[row][col] = " X";
		play1.printWaves();

		if (batLife1 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "BATTLESHIP has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play1.myWaters[row][col] == " c") // hit cruiser
	{
		--cruLife1;

		play1.waves[row][col] = " X";
		play1.printWaves();

		if (cruLife1 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "CRUISER has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play1.myWaters[row][col] == " s") // hit submarine
	{
		--subLife1;

		play1.waves[row][col] = " X";
		play1.printWaves();

		if (subLife1 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "SUBMARINE has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}
	else if (play1.myWaters[row][col] == " d") // hit destroyer
	{
		--desLife1;

		play1.waves[row][col] = " X";
		play1.printWaves();

		if (desLife1 == 0)
		{
			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "DESTROYER has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}

	if (play1.allSunk()) // ccheck for win state
	{ winState(false); }
	else
	{
		cout << "\n\n\n\n Press ENTER to continue...";
		getchar();

		fireMissile1();
	}
}


// allSunk
// checks whether or not there are 17 X's in the board
const bool board::allSunk()
{
	int hits = 0;

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			if (waves[i][ii] == " X")
			{ ++hits; }
		}
	}

	if (hits == 17) { return true; }

	return false;
}


// winState
// declares winner, resets boards and ships if players opt for a rematch
const void board::winState(bool play1Win)
{
	string response;
	
	if (play1Win)
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tMISSION SUCCESS!\n\n"
			 << "\t\t\tCONGRATULATIONS, CAPTAIN HONG!\n\n\n\n\n\n\n\n\n\n\n\n";
		// insert celebratory ascii art
	}
	else
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tMISSION SUCCESS!\n\n"
			 << "\t\t\tCONGRATULATIONS, CAPTAIN CHONG!\n\n\n\n\n\n\n\n\n\n\n\n";
		// insert celebratory ascii art
	}

	cout << "\n Play Again? (Y or N): ";

	getline(cin, response);

	if (response[0] == 'y' || response[0] == 'Y')
	{
		// reset boards
		play1.resetWaters();
		play2.resetWaters();

		// reset player1's ships
		carLife1 = 5;
		batLife1 = 4;
		cruLife1 = 3;
		subLife1 = 3;
		desLife1 = 2;

		// reset player2's ships
		carLife2 = 5;
		batLife2 = 4;
		cruLife2 = 3;
		subLife2 = 3;
		desLife2 = 2;

		clear(); // for convenience

		start(); // new game
	}
	else
	{ exit(1); }
}


/*int main()
{
	play1.start();

	return 0;
}*/