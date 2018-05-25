/*
 * File: main.cpp
 * Author: Nicholas Baxter
 * Created on August 23, 2015
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "mySudoku.h"

using namespace std;

int main(int argc, char** argv) {
	int anArray[Size][Size];

	//Makes an empty sudoku puzzle
	mySudoku emptyPuzzle;
	emptyPuzzle.PrintPuzzle();
	
	//Makes the filled sudoku puzzle, then checks the row and column
	mySudoku puzzle(anArray);
	puzzle.ReadPuzzle();
	puzzle.PrintPuzzle();
	
	//puzzle.CheckRow(3, 7);
	//puzzle.CheckCol(6, 8);
	//puzzle.CheckBox(4, 4, 5);
	cout << "iterations: " << puzzle.SolvePuzzle(1) << endl;
	//puzzle.PrintPuzzle();
	puzzle.PrintPuzzle();
	
	return(0);
}
