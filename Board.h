#ifndef BOARD_H
#define BOARD_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

class board
{
	public:
		vector<vector<string>> waves; // string for visual formatting of board

	public:
		board();
		~board();

		void printBoard(board ocean);
};

#endif
