// Board.h
// Dain Harmon
// Addeline Mitchell
// Mar 4, 2016
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
		// 'string' used for visual formatting purposes
		vector<vector<string>> waves; // hides ships
		vector<vector<string>> myWaters; // holds ships

	public:
		// ctor
		// documentation with implementation
		board();

		// dctor
		// documentation with implementation
		~board();

		// clear
		// documentation with implementation
		const void clear();

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

		// printWaves, printWaters
		// documentation with implementation
		const void printWaves();
		const void printWaters();

		// resetWaters
		// documentation with implementation
		const void resetWaters();

		// fireMissile1, fireMissile2
		// documentation with implementation
		const void fireMissile1();
		const void fireMissile2();

		// allSunk
		// documentation with implementation
		const bool allSunk();

		// winState
		// documentation with implementation
		const void winState(bool);

	private:
		bool secondC = false; // to keep track of 2nd ship of length 3 in setup

		// player1's ships
		int carLife1 = 5, batLife1 = 4, cruLife1 = 3, subLife1 = 3, desLife1 = 2;

		// player2's ships
		int carLife2 = 5, batLife2 = 4, cruLife2 = 3, subLife2 = 3, desLife2 = 2;
};

#endif