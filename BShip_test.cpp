#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Board.h"
#include <cstdio>
#include <cstdlib>

TEST_CASE("Board Initialization", "[board]")
{
	board b;
	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii)
		{ REQUIRE(b.waves[i][ii] == " ~"); }
	}

	// to test the print function, I put it here
	// because I didn't know how to use REQUIRE on it
	b.waves[4][7] = " #"; // suggested symbol for 'hit'
	b.waves[2][0] = " @"; // suggested symbol for 'miss' (it looks like a ripple)

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