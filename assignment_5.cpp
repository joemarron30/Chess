#include <iostream>
#include "application.h"
#include "board.h"
#include "chess_board_square.h"
#include "list.h"

using namespace std;

int main()
{
	//begin by testing all functions
	application test;
	test.test();


	//then play chess!
	test.run();

	return 0;
}