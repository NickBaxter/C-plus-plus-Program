/*
 * File: main.cpp
 * Author: Nicholas Baxter
 * Created on August 31, 2015
 */

#include <stdio.h>
#include <iostream>
#include "myQuadratic.h"

using namespace std;
char  PrintMenuAndGetInput();

int main(int argc, char** argv) {
  char userInput;
  userInput = PrintMenuAndGetInput();

  //while loop to prompt users to quit or solve another equation
  while(userInput != 'q') {
     //where users input values of the quadratic
     if(userInput == 's') {
	double aValue = 0;
	double bValue = 0;
	double cValue = 0;
	cout << "Enter the value for A: ";
	cin >> aValue;
	cout << "\nEnter the value for B: ";
	cin >> bValue;
	cout << "\nEnter the value for C: ";
	cin >> cValue;
	myQuadratic QTest1(aValue, bValue, cValue);
	QTest1.SolveSolutions();
	QTest1.PrintSolutions();
     }
     else {
	cout << "Valid inputs are: s, q. Please try agian" << endl;
     }
     userInput = PrintMenuAndGetInput();
  }	  

  cout << "Thank you for using the program." << endl;
  return 0;

}

char PrintMenuAndGetInput(){
    char userInput;
    cout << "s) enter s to solve a quadratic equation." << endl;
    cout << "q) enter q to end the program." << endl;
    cin >> userInput;
    return userInput;
}
