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
		vector<vector<string>> waves; // string for visual formatting of board
		vector<vector<string>> myWaters;
		//int xCoord, yCoord;

	public:
		board();
		~board();

		void intro();
		void start();
		void setBoard(int);
		bool isShip(int, int);
		void printBoard();

	private:
		bool hit;
		int x, y;
};

#endif