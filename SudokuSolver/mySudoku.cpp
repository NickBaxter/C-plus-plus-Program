 /*
 * File: myQuadratic.h
 * Author: Nicholas Baxter
 * Created: September 23, 2015
 */

#include "mySudoku.h"
#include <stdio.h>
#include <iostream>

using namespace std;

mySudoku::mySudoku() {
 	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j <= 8; j++) {
		Data[i][j] = 0;
		}
	}
}

mySudoku::mySudoku(int anArray[Size][Size]) {
 	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j <= 8; j++) {
			Data[Size][Size] = anArray[Size][Size];
		}
 	}
}

mySudoku::mySudoku(const mySudoku& orig) {

}

mySudoku::~mySudoku() {

}

void mySudoku::PrintPuzzle() {
	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j <= 7; j++) {
			cout << Data[i][j] << " "; 
		}
		cout << Data[i][8] << endl;
	}
	cout << endl;
}

void mySudoku::ReadPuzzle() {
	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j <= 8; j++) {
			cout << "Please enter the value for Row: " << i+1 << ", Column: " << j+1 << endl;
			cin >> Data[i][j];
		}
	}
}

bool mySudoku::CheckRow(int row, int number) {
 cout << "Checking row " << row+1 << " for number " << number << endl;
	for(int i = 0; i <= 8; i++) {
		if(Data[row][i] == number) {
			cout << "Row " << row+1 << " does contain number " << number << endl;
			return true;
		}		
	}
	cout << "Row " << row+1 << " does not contain number " << number << endl;
	return false;
}


bool mySudoku::CheckCol(int col, int number) {
 cout << "Checking column " << col+1 << " for number " << number << endl;
	for(int i = 0; i <= 8; i++) {
		if(Data[i][col] == number) {
			cout << "Column " << col+1 << " does contain number " << number << endl;
			return true;
		}

	}
	cout << "Column " << col+1 << " does not contain number " << number << endl;
	return false;
}

bool mySudoku::CheckBox(int row, int col, int number) {
 int tempRow = (row/3)*3;
 int tempCol = (col/3)*3;

 for(int i = 0; i < 3; i++) {
 	for(int j = 0; j < 3; j++) {
		if(Data[tempRow+i][tempCol+j] == number) {
			cout << "the number " << number << "  exists in the check box" << endl;
			return true;
		}
	}
	return false;
 }
}

//Checks to see if the sudoku puzzle is solved or not
bool mySudoku::CheckSolved() {
 for(int i = 0; i <= 8; i++) {
	for(int j = 0; j <= 8; j++) {
		if(Data[i][j] == 0) {
			return false;
		}
	}
 }
 return true;
}

//Solved the sudoku puzzle
int mySudoku:: SolvePuzzle(int iterations) {
 int iteratCounter = 0;
 while(iterations != 0) {
	//starts treversing the sudoku puzzle.
	for(int i = 0; i < Size; i++) {
		for(int j = 0; j < Size; j++) {
			//checks to see if the number is and if it is it intializes the answer and the answer counter to 0.
			if(Data[i][j] == 0) {
				int answerCounter(0);
				int ans(0);
				//Checks every possible solution and sets the answer and increases the counter as necessary.
				for(int k = 1; k < Size+1; k++) {
					if((CheckRow(i, k) == false)&&(CheckCol(j, k) == false)&&(CheckBox(i, j, k) == false)) {
						answerCounter++;
						ans = k;
					}
				}
				//if the counter is only one it will set the answer.
				if(answerCounter == 1) {
				Data[i][j] = ans;
				}
			}
		}
	}
  //decided how to iterate the function
  if(iterations > 0) {
  	iterations--;
  }
  else if((iterations < 0)&&(CheckSolved() == true)) {
	iteratCounter++;
	return iteratCounter;
  }
  else if((iterations < 0)&&(CheckSolved() == false)) {	
  	iteratCounter++;
	SolvePuzzle(iterations);
  }
  iteratCounter++; 
 }
 return iteratCounter;
}
