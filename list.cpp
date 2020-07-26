#include "list.h"
#include <iostream>

using namespace std;

void list::init_list() {

	n = new node;
	n->x = 0;
	n->y = 0;
	n->xf = 0;
	n->yf = 0;
	n->next = nullptr;
	
}

void list::make_list(int x1, int y1, int x2, int y2) {

	if (h == nullptr) {
		h = new node;
		h->x = x1;
		h->y = y1;
		h->xf = x2;
		h->yf = y2;
		h->next = nullptr;
		t = h;
	}
	else //if (t != nullptr)
	{
		node* newNode = new node;
		newNode->x = x1;
		newNode->y = y1;
		newNode->xf = x2;
		newNode->yf = y2;
		newNode->next = nullptr;
		t->next = newNode;
		t = newNode;
	}
}

void list::print_list() {

	int num = 1;
	node* pointer = h;

	while (pointer != nullptr) {
	cout << num << ". (" << pointer->x << ", " << pointer->y << ") ------->  (" << pointer->xf << ", " << pointer->yf << ")" << endl;

	pointer = pointer->next;
	num++;

	}
}

void list::delete_list() {
	//node* point = h;

	while (h != nullptr) {

		node* first = h;
		h = first->next;
		delete first;

		//point->x = 0;
		//point->y = 0;
		//point->xf = 0;
		//point->yf = 0;

		//point = point->next;
	}
	//delete h;
	//delete t;
	//delete n;
}