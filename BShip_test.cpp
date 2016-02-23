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
		{
			REQUIRE(b.waves[i][ii] == " ~");
			REQUIRE(b.myWaters[i][ii] == " ~");
		}
	}

	REQUIRE(b.isShip(0, 0) == false);
	
	b.myWaters[3][2] = " +";
	REQUIRE(b.isShip(3, 2) == true);

	// to test the print function, I put it here
	// because I didn't know how to use REQUIRE on it
	b.waves[4][7] = " X"; // suggested symbol for 'hit'
	b.waves[2][0] = " O"; // suggested symbol for 'miss' (it looks like a ripple)

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


	cout << "                                      |__\n"
		 << "                                      |\\/\n"
		 << "                                      ---\n"
		 << "                                      / | [\n"
		 << "                              !       | |||\n"
		 << "                            _/|     _ /|-++'\n"
		 << "                        +  +--|    |--|--|_ |-\n"
		 << "                     { /|__|  |/\\_ _|  |--- |||__/'\n"
		 << "                    +---------------___[}-_===_.'____                  /\\\n"
		 << "                ____`-' ||___-{]_| _[}-  |     |_[___\==--              \\/   _\n"
		 << " __..._____--==/___]_|__|_____________________________[___\ == --____,------' .7\n"
		 << "|                                                                    BB - 61 /'\n"
		 << " \\__________________________________________________________________________|'" << endl;

	cout << "__________    ____________________________.____     ___________ _________ ___ ___ ._____________ \n"
		 << "\\______   \\  /  _  \\__    ___ /\\__    ___/|    |    \\_   _____//   _____//   |   \\|   \\______   \\ \n"
		 << " |    |  _/ /  /_\\  \\|    |      |    |   |    |     |    __)_ \\_____  \\/    ~    \\   ||     ___/\n"
		 << " |    |   \\/    |    \\    |      |    |   |    |___  |        \\/        \\    Y    /   ||    |\n"
		 << " |______  /\\____|__  /____|      |____|   |_______ \\/_______  /_______  /\\___|_  /|___||____|\n"
		 << "        \\/          \\/                            \\/        \\/        \\/       \\/" << endl;
}