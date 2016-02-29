// Board.h
// Dain Harmon
// Addeline Mitchell
// Mar 1, 2016
//
// Battleship Project
// Group 7
//
// Header file for the 'board' class.

#ifndef BOARD_H
#define BOARD_H


#include <cstdio>

#include <cstdlib>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::getline;

class board
{
	public:
<<<<<<< HEAD
		// string for visual formatting of board
		vector<vector<string>> waves; // hides ships
		vector<vector<string>> myWaters; // with ships
=======
		vector<vector<string>> waves; // string for visual formatting of board
		vector<vector<string>> myWaters;
		//int xCoord, yCoord;
>>>>>>> f9faa63662b0c86a11129e940bdc2f4b1f31bd8a

	public:
		// ctor
		// documentation with implementation
		board();

		// dctor
		// documentation with implementation
		~board();

<<<<<<< HEAD
		// intro
		// documentation with implementation
		const void intro();

		// start
		// documentation with implementation
		const void start();

		// setBoard
		// documentation with implementation
		const void setBoard(const int&);

		// isShip
		// documentation with implementation
		const bool isShip(const int&, const int&);

		// printWaves1, printWaters1, printWaves2, printWaters2
		// documentation with implementation
		const void printWaves1();
		const void printWaters1(); // following the WET (Write Everything Twice)
		const void printWaves2();  // principle (horrible pun intended)
		const void printWaters2();

		// resetWaters
		// documentation with implementation
		const void resetWaters();

	private:
		bool secondC = false; // secondC to keep track of 2nd cruiser in setup
=======
		void intro();
		void start();
		void setBoard(int);
		bool isShip(int, int);
		void printBoard();

	private:
		bool hit;
		int x, y;
>>>>>>> f9faa63662b0c86a11129e940bdc2f4b1f31bd8a
};

#endif