// BShip_test.cpp
// Dain Harmon
// Addeline Mitchell
// Mar 1, 2016
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

board b;

void printB(board); // test print function prototype

// printB
// prints the board
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


// creation test //
TEST_CASE("Board Initialization", "[board]")
{
	//b.start();

	// board initialization tests //

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			REQUIRE(b.waves[i][ii] == " ~");
			REQUIRE(b.myWaters[i][ii] == " ~");
		}
	}
}


// overlap tests //
TEST_CASE("Ships Overlapping", "[board]")
{
	b.myWaters[4][7] = " X"; // suggested symbol for 'hit'
	b.myWaters[2][0] = " O"; // suggested symbol for 'miss'
	b.myWaters[3][2] = " #"; // boat?
	
	REQUIRE(b.isShip(3, 2) == true);
}

TEST_CASE("Ships Not Overlapping", "[board]")
{
	REQUIRE(b.isShip(0, 0) == false);
}


// test for removal of all ships //
TEST_CASE("Reset Board", "[board]")
{
	b.resetWaters();

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			REQUIRE(b.myWaters[i][ii] == " ~");
		}
	}
}


// ship placement test //
TEST_CASE("Interactive Setup", "[board]")
{
	printB(b);
	b.setBoard(5);
	printB(b);

	b.setBoard(4);
	printB(b);

	b.setBoard(3);
	printB(b);

	b.setBoard(3);
	printB(b);

	b.setBoard(2);
	printB(b);

	int shipCount = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			if (b.myWaters[i][ii] != " ~")
			{ ++shipCount; }
		}
	}

	REQUIRE(shipCount == 17);
}