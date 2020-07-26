#pragma once
#include "board.h"
#include "chess_board_square.h"
#include "list.h"

class application : public board, public list
{
public:

	char r, n;

	void run();
	void test();

};
