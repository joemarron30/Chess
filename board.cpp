#include "board.h"
#include"chess_board_square.h"
#include <iostream>
#include <string>

using namespace std;

void board::init_board() {

	//SET UP COLOURS
	for (int i = 0; i < 2; i++) {
		for (int n = 0; n < 8; n++) {
			//note 2 = BLACK
			Board[n][i].colour = 2;
		}
	}
	for (int i = 6; i < 8; i++) {
		for (int n = 0; n < 8; n++) {
			//note 1 = WHITE
			Board[n][i].colour = 1;
		}
	}
	for (int i = 2; i < 6; i++) {
		for (int n = 0; n < 8; n++) {
			//note 0 = EMPTY
			Board[n][i].colour = 0;
		}
	}

	//SET UP PIECES
	for (int i = 2; i < 6; i++) {
		for (int n = 0; n < 8; n++) {
			//note 0 = NO PIECE
			Board[n][i].piece = 0;
		}
	}
	for (int i = 0; i < 8; i++) {
		//note 1 = Pawn
		Board[i][1].piece = 1;
		Board[i][6].piece = 1;
	}

	//note rook = 2, knight = 3, bishop = 4, king = 5, queen = 6

	//Initialise black pieces first
	Board[0][0].piece = 2;
	Board[1][0].piece = 3;
	Board[2][0].piece = 4;
	Board[3][0].piece = 5;
	Board[4][0].piece = 6;
	Board[5][0].piece = 4;
	Board[6][0].piece = 3;
	Board[7][0].piece = 2;

	//Initialise white pieces 
	Board[0][7].piece = 2;
	Board[1][7].piece = 3;
	Board[2][7].piece = 4;
	Board[3][7].piece = 6;
	Board[4][7].piece = 5;
	Board[5][7].piece = 4;
	Board[6][7].piece = 3;
	Board[7][7].piece = 2;

	//Print Out Chess Board
	cout << "   ";
	for (int a = 1; a <= 8; a++) {
		cout << "-----";
	}
	cout << "-" << endl;
	for (int y = 7; y > -1; y--) {
		cout << " " << y << " ";
		for (int x = 0; x < 8; x++) {
			cout << "| " << int_switch(Board[x][y].piece) << colour_switch(Board[x][y].colour) << " ";
		}
		cout << "|" << endl;
		cout << "   ";
		for (int c = 1; c <= 8; c++) {
			cout << "-----";
		}
		cout << "-" << endl;
	}
	cout << "    ";
	for (int b = 0; b <= 7; b++) {
		cout << "  " << b << "  ";
	}
	cout << endl;
}

char board::int_switch(int piece) {

	switch (piece) {
	case 0:
		return ' ';
	case 1:
		return 'P';
	case 2:
		return 'R';
	case 3:
		return 'N';
	case 4:
		return 'B';
	case 5:
		return 'K';
	case 6:
		return 'Q';
	default:
		return ' ';
	}
}

char board::colour_switch(int colour) {
	switch (colour) {
	case 0:
		return ' ';
	case 1:
		return 'W';
	case 2:
		return 'B';
	default:
		return ' ';
	}
}

void board::print_board() {

	cout << "   ";
	for (int a = 1; a <= 8; a++) {
		cout << "-----";
	}
	cout << "-" << endl;
	for (int y = 7; y > -1; y--) {
		cout << " " << y << " ";
		for (int x = 0; x < 8; x++) {
			cout << "| " << int_switch(Board[x][y].piece) << colour_switch(Board[x][y].colour) << " ";
		}
		cout << "|" << endl;
		cout << "   ";
		for (int c = 1; c <= 8; c++) {
			cout << "-----";
		}
		cout << "-" << endl;
	}
	cout << "    ";
	for (int b = 0; b <= 7; b++) {
		cout << "  " << b << "  ";
	}
	cout << endl;
}

void board::move(int x1, int y1, int x2, int y2, bool& illegal) {
	if (Board[x1][y1].piece == 0) {
		cout << "No piece selected, please try again" << endl;
		illegal = true;
	}
	else if (x1 > 7 || x2 > 7 || y1 > 7 || y2 > 7 || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) {
		cout << "Incorrect Co-ordinate, please try again" << endl;
		illegal = true;
	}
	else if (Board[x1][y1].piece == 1) { //pawn
		if (Board[x1][y1].colour == 2) {
			if (x1 == x2 && y2 - y1 == 2 && y1 == 1 && Board[x2][y2].piece == 0 && Board[x1][y1 + 1].piece == 0) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if (y2 - y1 == 1 && x1 == x2 && Board[x2][y2].piece == 0) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 1 || x2 == x1 - 1) && y2 == y1 + 1 && Board[x2][y2].piece != 0 && Board[x2][y2].colour != 2) {
				//black pawn capture, diagonally forward left or right one space, given space is occupied by white piece
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else {
				cout << "Incorrect Move, please try again " << endl;
				illegal = true;
			}
		}
		else if (Board[x1][y1].colour == 1 /*&& player == 1*/) {
			if (x1 == x2 && y1 - y2 == 2 && y1 == 6 && Board[x2][y2].piece == 0 && Board[x1][y1 - 1].piece == 0) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if (x1 == x2 && y1 - y2 == 1 && Board[x2][y2].piece == 0) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 - 1 || x2 == x1 + 1) && y2 == y1 - 1 && Board[x2][y2].piece != 0 && Board[x2][y2].colour != 1) {
				//white pawn capture, diagonally forward left or right one space, given space is occupied by black piece
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else {
				cout << "Incorrect Move, please try again " << endl;
				illegal = true;
			}
		}
	}

	else if (Board[x1][y1].piece == 2) { //rook

		if ((x1 == x2 || y1 == y2) && (Board[x2][y2].piece == 0 || Board[x2][y2].colour != Board[x1][y1].colour)) {
			Board[x2][y2].piece = Board[x1][y1].piece;
			Board[x2][y2].colour = Board[x1][y1].colour;
			Board[x1][y1].piece = 0;
			Board[x1][y1].colour = 0;
		}
		else
		{
			cout << "Incorrect Move, please try again" << endl << endl;
			illegal = true;
		}
	}

	else if (Board[x1][y1].piece == 3) { //knight
		if ((x2 == x1 + 1 || x2 == x1 - 1) && y2 == y1 + 2 && (Board[x2][y2].piece == 0 || Board[x2][y2].colour == 1) && Board[x1][y1].colour == 2) {
			Board[x2][y2].piece = Board[x1][y1].piece;
			Board[x2][y2].colour = Board[x1][y1].colour;
			Board[x1][y1].piece = 0;
			Board[x1][y1].colour = 0;
		}
		else if ((x2 == x1 + 1 || x2 == x1 - 1) && y2 == y1 - 2 && (Board[x2][y2].piece == 0 || Board[x2][y2].colour == 2) && Board[x1][y1].colour == 1) {
			Board[x2][y2].piece = Board[x1][y1].piece;
			Board[x2][y2].colour = Board[x1][y1].colour;
			Board[x1][y1].piece = 0;
			Board[x1][y1].colour = 0;
		}
		else {
			cout << "incorrect move, please try again" << endl;
			illegal = true;
		}
	}

	else if (Board[x1][y1].piece == 4) { //bishop
		if ((Board[x1][y1].colour != Board[x2][y2].colour) || Board[x2][y2].piece == 0)
		{
			if ((x2 == x1 + 1 && (y2 == y1 + 1 || y2 == y1 - 1)) || (x2 == x1 - 1 && (y2 == y1 + 1 || y2 == y1 - 1))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 2 && (y2 == y1 + 2 || y2 == y1 - 2)) || (x2 == x1 - 2 && (y2 == y1 + 2 || y2 == y1 - 2))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 3 && (y2 == y1 + 3 || y2 == y1 - 3)) || (x2 == x1 - 3 && (y2 == y1 + 3 || y2 == y1 - 3))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 4 && (y2 == y1 + 4 || y2 == y1 - 4)) || (x2 == x1 - 4 && (y2 == y1 + 4 || y2 == y1 - 4))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 5 && (y2 == y1 + 5 || y2 == y1 - 5)) || (x2 == x1 - 5 && (y2 == y1 + 5 || y2 == y1 - 5))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 6 && (y2 == y1 + 6 || y2 == y1 - 6)) || (x2 == x1 - 6 && (y2 == y1 + 6 || y2 == y1 - 6))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 7 && (y2 == y1 + 7 || y2 == y1 - 7)) || (x2 == x1 - 7 && (y2 == y1 + 7 || y2 == y1 - 7))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
		}
		else {
			cout << "incorrect move, please try again" << endl;
			illegal = true;
		}
	}

	else if (Board[x1][y1].piece == 5) { //king
		if (Board[x1][y1].colour != Board[x2][y2].colour || Board[x1][y1].piece == 0) {
			if (((x2 == x1 + 1 && y2 == y1) || (x2 == x1 - 1 && y2 == y1) || (y2 == y1 + 1 && x2 == x1) || (y2 == y1 - 1 && x2 == x1))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 1 && y2 == y1 + 1) || (x2 == x1 + 1 && y2 == y1 - 1)) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 - 1 && y2 == y1 + 1) || (x2 == x1 - 1 && y2 == y1 - 1)) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else {
				cout << "Incorrect move, please try again" << endl;
				illegal = true;
			}
		}
	}

	else if (Board[x1][y1].piece == 6) { //queen
		if ((Board[x1][y1].colour != Board[x2][y2].colour) || Board[x2][y2].piece == 0)
		{
			if ((x2 == x1 + 1 && (y2 == y1 + 1 || y2 == y1 - 1)) || (x2 == x1 - 1 && (y2 == y1 + 1 || y2 == y1 - 1))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 2 && (y2 == y1 + 2 || y2 == y1 - 2)) || (x2 == x1 - 2 && (y2 == y1 + 2 || y2 == y1 - 2))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 3 && (y2 == y1 + 3 || y2 == y1 - 3)) || (x2 == x1 - 3 && (y2 == y1 + 3 || y2 == y1 - 3))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 4 && (y2 == y1 + 4 || y2 == y1 - 4)) || (x2 == x1 - 4 && (y2 == y1 + 4 || y2 == y1 - 4))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 5 && (y2 == y1 + 5 || y2 == y1 - 5)) || (x2 == x1 - 5 && (y2 == y1 + 5 || y2 == y1 - 5))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 6 && (y2 == y1 + 6 || y2 == y1 - 6)) || (x2 == x1 - 6 && (y2 == y1 + 6 || y2 == y1 - 6))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x2 == x1 + 7 && (y2 == y1 + 7 || y2 == y1 - 7)) || (x2 == x1 - 7 && (y2 == y1 + 7 || y2 == y1 - 7))) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else if ((x1 == x2 || y1 == y2)) {
				Board[x2][y2].piece = Board[x1][y1].piece;
				Board[x2][y2].colour = Board[x1][y1].colour;
				Board[x1][y1].piece = 0;
				Board[x1][y1].colour = 0;
			}
			else {
				cout << "Incorrect Move, please try again " << endl;
				illegal = true;
			}
		}
	}
}