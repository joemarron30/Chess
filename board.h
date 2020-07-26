#pragma once
#include "chess_board_square.h"
class board
{
public:

	int x1;
	int y1;
	int x2;
	int y2;
	int player;
	bool illegal;

	chess_board_square Board[8][8];

	void init_board();
	void print_board();

	void move(int x1, int y1, int x2, int y2, bool& illegal);

	char int_switch(int piece);
	char colour_switch(int colour);
	/*
	struct node {
		int x;
		int y;
		int xf;
		int yf;
		node* next;
	};

	node* n;
	node* t;
	node* h;

	void init_list();
	void make_list(int x1, int y1, int x2, int y2);
	void print_list();
	*/
private:
	
};


