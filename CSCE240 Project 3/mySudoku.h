/*
 * File: mySudoku.h
 * Author: Nicholas Baxter
 * Created: August 23, 2015
 */

#ifndef MYSUDOKU_H
#define MYSUDOKU_H

const int Size(9);

class mySudoku {
public:
	mySudoku();
	mySudoku(int anArray[][Size]);
	mySudoku(const mySudoku& orig);

	void ReadPuzzle();
	void PrintPuzzle();
	bool CheckBox(int row, int col, int number);
	bool CheckRow(int row, int number);
	bool CheckCol(int col, int number);
	int SolvePuzzle(int iterations);
	int mySolvePuzzle();
	bool CheckSolved();
	virtual ~mySudoku();
	
private:
	int Data[Size][Size];
};

#endif /* MYSUDOKU_H */
