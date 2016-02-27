#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Board.h"
#include <cstdio>
#include <cstdlib>

TEST_CASE("Board Initialization", "[board]")
{
	

	board b;
	
	//b.start();

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{
			REQUIRE(b.waves[i][ii] == " ~");
			REQUIRE(b.myWaters[i][ii] == " ~");
		}
	}

	REQUIRE(b.isShip(0, 0) == false);
	
	b.myWaters[3][2] = " #";
	REQUIRE(b.isShip(3, 2) == true);

	// to test the print function, I put it here
	// because I didn't know how to use REQUIRE on it
	b.myWaters[4][7] = " X"; // suggested symbol for 'hit'
	b.myWaters[2][0] = " O"; // suggested symbol for 'miss'

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