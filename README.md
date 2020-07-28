# Chess
Description:
Basic Chess Board made in C++ as part of college assignment.
Designed to allow players to take turns making legal moves on the board (e.g pawn can move 2 squares on first go).
Also keeps track of moves made so far by making use of a one-way linked list.
As of now (July 2020) some functionality is missing such as checkmate and the Rook and Bishop being able to jump over other pieces.

Structure of Code:
Assignment 5 - Runs testing functions and then if no problems are encountered then the game begins!
Application - Contains run and test functions used in above code, brings together all other parts of the project into one.
Board - Prints out the board, tests if the move made is legal and makes the move is it is legal.
Chess Board Square - Initialises piece and colour objects to be used in the board code.
List - Creates linked list and stores each legal move in it to be printed out upon request from the user.

Feel free to try it out!
