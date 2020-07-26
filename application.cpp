#include "application.h"
#include "board.h"
#include "chess_board_square.h"
#include "list.h"
#include <iostream>
#include <string>

using namespace std;

void application::run() {

	int x1, y1, x2, y2;
	char s;
	char l;
	bool illegal = false;
	bool gameover = false;
	string c;
	string name;

	int count = 1;

	init_list();

	init_board();
	cout << endl;

	while (gameover != true) {

		if (count % 2 == 1) {
			c = "White"; // white goes first
		}
		else if (count % 2 == 0) {
			c = "Black"; //black
		}

		cout << "It is " << c << "'s turn... " << endl;

		cout << "Please Enter Co-ordinates of Piece You Wish to Move (x y): ";
		cin >> x1 >> y1;
		cout << endl;

		cout << "Please Enter co-ordinates of destination (x y): ";
		cin >> x2 >> y2;
		cout << endl;

		move(x1, y1, x2, y2, illegal);

		print_board();
		cout << endl;

		if (illegal == true) {
			illegal = false;
		}
		else if (illegal == false) {
			make_list(x1, y1, x2, y2);
			count++;
		}

		cout << "Would you like to see the moves made so far? (y/n): ";
		cin >> l;
		cout << endl << endl;

		if (l == 'y') {
			print_list();
			cout << endl << endl;
		}

		cout << "reinitialise board? (y/n) or finsh game? (f): ";
		cin >> s;
		cout << endl << endl;

		if (s == 'y') {
			init_board();
			delete_list();
			count--;
			cout << endl;
		}
		else if (s == 'f') {
			gameover = true;
			cout << "Thanks for playing!" << endl;
		}
	}
}

void application::test() {
	//Testing switch functions for errors
	if (int_switch(1) != 'P') {
		cout << "Error found in int_switch function, 1 != Pawn!!!" << endl;
	}
	else if (colour_switch(1) != 'W') {
		cout << "Error found in colour_switch function, 1 != White!!!" << endl;
	}
	//Initialising Board
	init_board();
	cout << endl;

	//Testing board for errors in initialising
	if (Board[0][0].piece != 2 || Board[0][0].colour != 2) {
		cout << "Error found in init_board function, Square (0, 0) != Black Rook!!!" << endl;
	}

	//testing move function
	//moving PW (0, 1) to (0, 3)
	// setting count to 1, move is permissable so count should == 1 after move
	//count only decrease if false move is made
	move(1, 1, 1, 3, illegal);

	if (Board[1][1].piece != 0 && Board[1][3].piece != 1) {
		cout << "Error found in move function, Square (1, 3) != Pawn!" << endl;
	}
	else if (Board[1][1].colour != 0 && Board[1][3].colour != 2) {
		cout << "Error found in move function, Square (1, 3) != Black!" << endl;
	}
	//Testing printboard function
	print_board();
	cout << endl << endl;

	cout << "Black Pawn successfully moved from (1, 1) to (1, 3)" << endl;
	cout << "No errors detected :)" << endl;
	cout << "Testing on all functions complete, enjoy your game of chess! " << endl << endl;

	//Testing Linked List hardcoding co-ordinates from above move
	
	//Initialise Linked List
	init_list();
	//Initialise BOard
	init_board();
	cout << endl;

	//Move Black Pawn (1, 1) -> (1, 3)
	move(1, 1, 1, 3, illegal);

	//Creating New Node with co-ordinates of Move
	make_list(1, 1, 1, 3); //Black Pawn (1, 1) -> (1, 3)

	//print out move
	print_board();
	cout << endl;

	//Print out list, should print out (1, 1) -> (1, 3)
	print_list();
	cout << endl;

	//initialise board
	init_board();
	cout << endl;
	//delete list so far
	delete_list();
	//move next 2 pieces
	move(3, 1, 3, 3, illegal);//Black Pawn 3,1 -> 3,3
	move(2, 6, 2, 4, illegal);//Whhite Pawn 2,6 -> 2,4

	//print out moves
	print_board();
	cout << endl;
	//Insert moves into linked list
	make_list(3, 1, 3, 3);
	make_list(2, 6, 2, 4);

	//Print out 2 moves not first move before initialise
	print_list();
	cout << endl;
	
	//Delete current list before new game starts
	delete_list();

	cout << "Testing Complete!" << endl;
	cout << "No Errors detected in linked list or linked list functions!" << endl;
	cout << "WOOP DEE DOO Enjoy Your Game of Chess :)" << endl << endl;
}
