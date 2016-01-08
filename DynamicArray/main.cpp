/*
 * File: main.cpp
 * Author: Nicholas Baxter
 * Created on October 30, 2015
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "Array.h"
#include "Array.cpp"

using namespace std;

int main(int argc, char** argv) {
	//creates the array that is passed into the alternate constructor
	int anArray[20];
	for(int i = 0; i < 20; i++) {
		anArray[i] = i;
	}
	//Creates the objects in the program
	Array<int> ArrayOne;
	Array<int> ArrayTwo(20, 27);
	Array<int> ArrayThree(20, -5);
	Array<int> ArrayFour(anArray, 20);
	//Prints out all the objects
	cout << "ArrayOne: " << endl;
	ArrayOne.Print();
	cout << "ArrayTwo: " << endl;
	ArrayTwo.Print();
	cout << "ArrayThree: " << endl;
	ArrayThree.Print();
	cout << "ArrayFour: " << endl;
	ArrayFour.Print();
	//manipulates the arrays
	cout << "ArrayTwo+=ArrayThree" << endl;
	ArrayTwo+=ArrayThree;
	ArrayTwo.Print();
	cout << "ArrayTwo-=ArrayThree" << endl;
	ArrayTwo-=ArrayThree;
	ArrayTwo.Print();
	//test the [] functions
	cout << "ArrayFour[5] = 6: ";
	ArrayFour[5] = 6;
	ArrayFour.Print();
	cout << ArrayFour[5] << endl;
	
}

