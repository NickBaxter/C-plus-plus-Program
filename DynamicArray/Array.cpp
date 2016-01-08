/*
* Author: Nicholas Baxter
* Created on December 9, 2015
*/
#include "Array.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

//Default Constructor
template <class T>
Array<T>::Array() :Size(0) {
	Data = NULL;
}
//Alternate Constructor 
template <class T>
Array<T>::Array(int arraySize, T value) : Size(arraySize) {
	Data = new int[Size];
	for (int i = 0; i < Size; i++) {
		Data[i] = value;
	}
}
//Alternate Constructor that takes in an array
template <class T>
Array<T>::Array(T anArray[], int arraySize) : Size(arraySize) {
	Data = new int[Size];
	for (int i = 0; i < Size; i++) {
		Data[i] = anArray[i];
	}
}
//copy constructor
template <class T>
Array<T>::Array(const Array<T> &orig) : Size(orig.size()) {
	Data = new int[Size];
	for (int i = 0; i < Size; i++) {
		Data[i] = orig.get(i);
	}
}
//Deletes Data
template <class T>
Array<T>::~Array() {
	delete[] Data;
}
//Copies the rhs array in the left hand side array
template <class T>
Array<T> & Array<T>::operator=(Array<T> & rhs) {
	if (Size == rhs.Size) {
		for (int i = 0; i < Size; i++) {
			Data[i] = rhs.Data[i];
		}
	}
}
//Adds the rhs array into the lhs side
template <class T>
const Array<T> & Array<T>:: operator+(const Array<T> & rhs) const {
	if (size() == rhs.size()) {
		for (int i = 0; i < size(); i++) {
			Data[i] = Data[i] + rhs.Data[i];
		}
	}
	else {
		exit(0);
	}
}
//Subtracts the content of the first array from the second array
template <class T>
const Array<T> & Array<T>:: operator-(const Array<T> & rhs) const {
	if (size() == rhs.size()) {
		for (int i = 0; i < size(); i++) {
			Data[i] = Data[i] - rhs.get(i);
		}
	}
	else {
		exit(0);
	}
}
template <class T>
//takes the left array and adds it by the right array and sets the left array equal to that
const Array<T> & Array<T>:: operator+=(const Array<T> & rhs) {
	if (size() == rhs.size()) {
		for (int i = 0; i < size(); i++) {
			Data[i] = Data[i] + rhs.get(i);
		}
	}
	return *this;
}
template <class T>
//takes the left array and subtracts it by the right array and sets the left array equal to that 
const Array<T> & Array<T>:: operator-=(const Array<T> & rhs) {
	if (size() == rhs.size()) {
		for (int i = 0; i < size(); i++) {
			Data[i] = Data[i] - rhs.get(i);
		}
	}
	return *this;
}
//Increments the array's Data up by one
//Postfix
template <class T>
Array<T> & Array<T>::operator++() {
	for (int i = 0; i < size(); i++) {
		set(1, get(i) + 1);
	}
	return *this;
}

//Increment the array by one (at the end)
//prefix
template <class T>
Array<T> & Array<T>::operator++(int dummy) {
	for (int i = 0; i < size(); i++) {
		set(1, get(i) + 1);
	}
	return *this;
}

//Checks to see if the two arrays are equal in size and content
template <class T>
bool Array<T>:: operator==(Array<T> & rhs) const {
	if (size() == rhs.size()) {
		for (int i = 0; i < size(); i++) {
			if (Data[i] == rhs.get(i)) {
				if (i == size() - 1) {
					return true;
				}
			}
		}
	}
	return false;
}

//acts as a getters
template <class T>
int Array<T>::operator[](int index) const {
	return Data[index];
}
//acts as a setter
template <class T>
int &Array<T>::operator[](int index) {
	if(index > size()) {
		exit(0);
	}
	return Data[index];
}

//Sets the Array's values a the given index
template <class T>
void Array<T>::set(int index, T value) {
	if (index > size()) { //Exits program if index is out of bounds
		exit(0);
	}
	else {
		Data[index] = value;
	}
}

//Gets the Array's values at the given
template <class T>
int Array<T>::get(int index) const {
	if (index > size()) { //Exits program if index is out of bounds
		exit(0);
	}
	else {
		return Data[index];
	}
}

//Returns the Array's Size
template <class T>
int Array<T>::size() const {
	return Size;
}

//inserts object into array and then shifts all data to the right of the idex to the left
template <class T>
void Array<T>::insert(int index, T value) {
	if (index < size()) {
		int tempSize = size() + 1;
		int temp[tempSize];
		for (int i = 0; i < tempSize; i++) {
			int j = 0;
			if (i == index) {
				temp[i] = value;
				i++;
			}
			temp[i] = Data[j];
			j++;
		}
		delete[] Data;
		Size = tempSize;
		Data = new int[Size];
		for (int i = 0; i < size(); i++) {
			Data[i] = temp[i];
		}
	}
	else {
		exit(0);
	}
}
//Removes object from array and then shift all data to the left of index to the right
template <class T>
int Array<T>::remove(int index) {
	int tempArray[size() - 1];
	int tempSize = size() - 1;
	index = Data[index];
	if (size() > index) {
		for (int i = 0; i < size() - 1; i++) {
			if (i == index) {
				tempArray[i] = Data[i + 1];
				i++;
			}
			tempArray[i] = Data[i + 1];
		}
		delete[] Data;
		Data = new int[tempSize];
		for (int i = 0; i < size(); i++) {
			Data[i] = tempArray[i];
		}
	}
	else {
		exit(0);
	}
	return index;
}
//Prints out an array
template <class T>
void Array<T>::Print() const {
	for(int i = 0; i < size(); i++) {
		cout << Data[i] << " ";
	}
	cout << endl;
}

//allows output an array with cout
template <class T>
ostream & operator <<(ostream & outStream, const Array<T> & rhs) {
	for (int i = 0; i < rhs.size(); i++) {
		outStream << rhs.get(i) << " ";
	}
	cout << endl;
	return outStream;
}
//allows input an array with cin
template <class T>
istream & operator >>(istream & intStream, Array<T> & rhs) {
	for (int i = 0; i < rhs.size(); i++) {
		intStream >> rhs.get(i);
	}
	return intStream;
}
