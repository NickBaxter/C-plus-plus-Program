/*
 * File: intArray.h
 * Author: Nihcolas Baxter
 * Created: October 30, 2015
 */

#ifndef INTARRAY_H
#define INTARRAY_H

class intArray {
public:
	intArray();
	intArray(int arraySize, int value=0);
	virtual ~intArray();
	intArray(int anArray[], int arraySize);
	//intArray(const intArray& orig);//usually called the copy constructor;
	void Print(void);
	void operator=(intArray &rhs);
	void set(int index, int value);
	int get(int index);
	int size();
	bool operator==(intArray &arrayTwo);
	void operator+(intArray &arrayTwo);
	void operator-(intArray &arrayTwo);
	void insert(int index, int value);
	int remove(int index);
private:
	int Size;
	int *Data;
};

#endif
