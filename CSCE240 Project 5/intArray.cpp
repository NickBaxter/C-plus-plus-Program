*
 * File: intArray.h
 * Author: Nicholas Baxter
 * Created: October 31, 2015
 */

#include "intArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//default constructor
intArray::intArray() :Size(10) {
	Data = NULL;
	Data = new int [Size];
	for(int i = 0; i < Size; i++) {
		Data[i] = 0;
	}
}
//alternate constructor
intArray::intArray(int arraySize, int value) :Size(arraySize) {
	Size = arraySize;
	Data = new int [Size];
	for(int i = 0; i < Size; i++) {
		*(Data+i) = value;
	}
}
//alternate constructor that takes in an array
intArray::intArray(int intArray[], int arraySize) :Size(arraySize) {
	Data = new int[Size];
	for(int i = 0; i < Size; i++) {
		Data[i] = intArray[i];
	}
}
//returns the size of the array
int intArray::size() {
        return Size;
}
//sets the given index to the value if the index is in the bounds of the array
void intArray::set(int index, int value) {
        if(index > size()) {
                exit(0);
        }
        else
                Data[index] = value;
}//gets the int at the give index of the array if it is in the bounds of the array
int intArray::get(int index) {
        if(index > size())
                exit(0);
        else
                return Data[index];
}
//Prints the Array out
void intArray::Print() {
	for(int i = 0; i < size(); i++) {
		cout << Data[i] << " ";
	}
	cout << endl;
}
//Copies the rhs array into the left hand side array
void intArray::operator=(intArray &rhs) {
	if(size() == rhs.size()) {
		for(int i = 0; i < size(); i++) {
			set(i, rhs.get(i));
		}
	}
	else {
		cout << "The two arrays are not the same size.\nTerminating Program Now." << endl;
		exit(0);
	}
}
//the deconstructor.
intArray::~intArray() {
	delete [] Data;
}
//Checks to see if the two arrays are equal in size and content
bool intArray::operator==(intArray &arrayTwo) {
	if(size() == arrayTwo.size()) {
		for(int i = 0; i < size(); i++) {
			if(get(i) != arrayTwo.get(i)) {
				//cout << "The arrays do not have the same content" << end;
				return false;
			}
		}
		//cout << "the arrays are the same size" << endl;
		return true;
	}
	else {
		//cout << "The arrays are not the same size" << endl;
		return false;
	}
}
//Adds the second array into the first array
void intArray::operator+(intArray &arrayTwo) {
	if(size() == arrayTwo.size()) {
		for(int i = 0; i < size(); i++) {
			set(i, (arrayTwo.get(i) + get(i)));
		}
	}
	else {
		cout << "The arrays are not the same size so they can't be added\nTerminating Program Now" << endl;
		exit(0);
	}
	
}
//subtracts the content of the first array from the second array
void intArray::operator-(intArray &arrayTwo) {
	if(size() == arrayTwo.size()) {
		for(int i = 0; i < size(); i++) {
			set(i, (get(i) - arrayTwo.get(i)));
		}
	}
	else {
		cout << "The arrays are not the same size so they can't be added\nTerminating Program Now" << endl;
		exit(0);
	}
	
}

void intArray::insert(int index, int value) {
	if(index < size()) {
		int tempSize = size()+1;
		int temp[tempSize];	
		for(int i = 0; i < tempSize; i++) {
			int j = 0;		
			if(i == index) {
				temp[i] = value;
				i++;
			}
			temp[i] = Data[j];
			j++;		
		}
		
		delete [] Data;
		Size = tempSize;
		Data = new int [Size];

		for(int i = 0; i < size(); i++) {
			Data[i] = temp[i];
		}	
		
	}
	else {
		exit(0);
	}		
}

int intArray::remove(int index) {
	if(index < size()) {
		int value = Data[index];
		int tempSize = size()-1;
		int temp[tempSize];
		int j = 0;

		for(int i = 0; i < (tempSize); i++) {
			if(index == j) {
				j++; 
			}
			temp[i] = Data[j];
			j++;
		}

		delete [] Data;
		Size = tempSize;
		Data = new int [Size];

		for(int i = 0; i < (size()); i++) {
			/*if(i == index) {
				i++;
			}*/
			Data[i] = temp[i];
		}
		return value;
	}
	else {
		exit(0);
	}
}
