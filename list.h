#pragma once
class list
{
public:

	struct node {
		int x;
		int y;
		int xf;
		int yf;
		node* next;
	};

	node* n = nullptr;
	node* t = nullptr;
	node* h = nullptr;

	void init_list();
	void make_list(int x1, int y1, int x2, int y2);
	void print_list();
	void delete_list();
};

