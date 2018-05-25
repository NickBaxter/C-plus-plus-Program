/*
 * File: main.cpp
 * Author: Nicholas Baxter
 * Created on October 30, 2015
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "intArray.h"

using namespace std;

int main(int argc, char** argv) {
	//creates the array that is passed into the alternate constructor
	int anArray[20];
	for(int i = 0; i < 20; i++) {
		anArray[i] = i;
	}
	//Creates the objects in the program
	intArray ArrayOne;
	intArray ArrayTwo(20);
	intArray ArrayThree(20, -5);
	intArray ArrayFour(anArray, 20);
	//Prints out all the objects
	cout << "ArrayOne: " << endl;
	ArrayOne.Print();
	cout << "ArrayTwo: " << endl;
	ArrayTwo.Print();
	cout << "ArrayThree: " << endl;
	ArrayThree.Print();
	cout << "ArrayFour: " << endl;
	ArrayFour.Print();
	//copies arrayThree into arrayTwo and prints the them out
	ArrayTwo.copy(ArrayThree);
	cout << "ArrayTwo: " << endl;
	ArrayTwo.Print();
	ArrayThree.set(1, -150);
	cout << "ArrayThree: " << endl;
	ArrayThree.Print();
	//checks to make sure the newly copied arrays are equal
	ArrayTwo.equal(ArrayThree);
	//adds arrayThree to arrayTwo
	ArrayTwo.add(ArrayThree);
	cout << "ArrayTwo: " << endl;
	ArrayTwo.Print();
	//Subtracts arrayThree from arrayTwo
	ArrayTwo.subtract(ArrayThree);
	cout << "ArrayTwo: " << endl;
	ArrayTwo.Print();
	return 0;
}
