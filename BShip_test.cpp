// BShip_test.cpp
// Dain Harmon
// Addeline Mitchell
// Mar 4, 2016
//
// Battleship Project
// Group 7
//
// Test file for the 'board' class.

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Board.h"
#include <cstdio>
#include <cstdlib>

board play;
int cruLife = 3, hits = 0;

void printB(board); // test printWaters function prototype
void printB2(board); // test printWaves function prototype
void fireMissile(board); // test firing of missiles prototype

// printB
// prints the board containing ships
void printB(board b)
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;

	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";

		for (int ii = 0; ii < 10; ++ii)
		{ cout << b.myWaters[i][ii]; }

		cout << " |" << endl;
	}

	cout << "      ---------------------" << endl;
}

// printB2
// prints the board hiding the ships
void printB2(board b)
{
	cout << "\n       0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "      _____________________" << endl;

	for (int i = 0; i < 10; ++i)
	{
		cout << "  " << i << "  |";

		for (int ii = 0; ii < 10; ++ii)
		{ cout << b.waves[i][ii]; }

		cout << " |" << endl;
	}

	cout << "      ---------------------" << endl;
}

// fireMissile
// condensed verision of fireMissile1 and fireMissile2
void fireMissile(board)
{
	string input;
	bool shoot = false;
	int col, row;

	do
	{
		bool restart = false;

		do // request x-coordinate (column)
		{
			cout << "\n CAPTAIN: fire at will, SIR.\n" << endl;

			printB2(play);

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
					else if (play.waves[row][col] == " O" || play.waves[row][col] == " X")
					{ // if coordinates have already been used
						cout << "\n Oh Captain, my Captain: a missile has already been "
							 << "fired there, no need to send another, SIR. Try again.\n" << endl;

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

	if (play.myWaters[row][col] == " ~")
	{
		play.waves[row][col] = " O";

		printB2(play);

		cout << "\n MISS: no sign of a ship at "
			 << "those coordinates, SIR.\n\n" << endl;
	}
	else if (play.myWaters[row][col] == " c")
	{
		--cruLife;
		++hits;

		play.waves[row][col] = " X";

		if (cruLife == 0)
		{
			printB2(play);

			cout << "\n HIT: the wreckage reveals the enemy's "
				 << "CRUISER has been SUNK, SIR.\n\n" << endl;
		}
		else
		{
			printB2(play);

			cout << "\n HIT: a ship has been sighted at "
				 << "those coordinates sir, SIR.\n\n" << endl;
		}
	}

	if (hits == 3)
	{ cout << "\n ALL ENEMY SHIPS ARE SLEEPING WITH THE FISHES\n" << endl; }
	else
	{ fireMissile(play); }
}


// creation test //
TEST_CASE("Board Initialization", "[board]")
{
	//play.start(); // uncomment to test full game

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			REQUIRE(play.waves[i][ii] == " ~");
			REQUIRE(play.myWaters[i][ii] == " ~");
		}
	}
}


// overlap tests //
TEST_CASE("Ships Overlapping", "[ships]")
{
	play.myWaters[4][7] = " X"; // suggested symbol for 'hit'
	play.myWaters[2][0] = " O"; // suggested symbol for 'miss'
	play.myWaters[3][2] = " #"; // boat?

	REQUIRE(play.isShip(3, 2) == true);
}

TEST_CASE("Ships Not Overlapping", "[ships]")
{
	REQUIRE(play.isShip(0, 0) == false);
}


// test for removal of all ships //
TEST_CASE("Reset Board", "[board]")
{
	play.resetWaters();

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			REQUIRE(play.myWaters[i][ii] == " ~");
		}
	}
}


// ship placement test //
TEST_CASE("Interactive Setup", "[interactive]")
{
	cout << " INTERACTIVE TEST: setup" << endl;

	printB(play);
	play.setBoard(5);
	printB(play);

	play.setBoard(4);
	printB(play);

	play.setBoard(3);
	printB(play);

	play.setBoard(3);
	printB(play);

	play.setBoard(2);
	printB(play);

	int shipCount = 0;

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			if (play.myWaters[i][ii] != " ~")
			{ ++shipCount; }
		}
	}

	REQUIRE(shipCount == 17);
}


// missile tests //
TEST_CASE("Firing Missiles", "[interactive]")
{
	play.resetWaters();

	play.myWaters[4][4] = " c";
	play.myWaters[4][5] = " c";
	play.myWaters[4][6] = " c";

	cout << "\n\n INTERACTIVE TEST: firing missiles\n" << endl;
	cout << "\n A cruiser has been placed somewhere on the board.\n"
		 << "Hits will be verified when ship is sunk, misses must "
		 << "be verified visually. (Hint: row 4)\n" << endl;
	fireMissile(play);
	REQUIRE(hits == 3);
}


// endgame check tests //
TEST_CASE("All Ships Sunk", "[board]")
{
	play.waves[4][4] = " X";
	play.waves[4][5] = " X";
	play.waves[4][6] = " X";
	play.waves[3][4] = " X";
	play.waves[3][5] = " X";
	play.waves[3][6] = " X";
	play.waves[4][1] = " X";
	play.waves[4][2] = " X";
	play.waves[4][3] = " X";
	play.waves[8][4] = " X";
	play.waves[7][4] = " X";
	play.waves[6][4] = " X";
	play.waves[9][3] = " X";
	play.waves[8][3] = " X";
	play.waves[7][3] = " X";
	play.waves[0][0] = " X";
	play.waves[1][0] = " X";

	REQUIRE(play.allSunk() == true);
}

TEST_CASE("Not All Ships Sunk", "[board]")
{
	play.waves[4][4] = " X";
	play.waves[4][5] = " X";
	play.waves[4][6] = " X";
	play.waves[3][4] = " X";
	play.waves[3][5] = " O";
	play.waves[3][6] = " X";
	play.waves[4][1] = " O";
	play.waves[4][2] = " O";
	play.waves[4][3] = " X";
	play.waves[8][4] = " X";
	play.waves[7][4] = " O";
	play.waves[6][4] = " X";
	play.waves[9][3] = " X";
	play.waves[8][3] = " X";
	play.waves[7][3] = " X";
	play.waves[0][0] = " O";
	play.waves[1][0] = " X";

	REQUIRE(play.allSunk() == false);
}