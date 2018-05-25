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
	void copy(intArray &rhs);
	void set(int index, int value);
	int get(int index);
	int size();
	bool equal(intArray &arrayTwo);
	void add(intArray &arrayTwo);
	void subtract(intArray &arrayTwo);
private:
	int Size;
	int *Data;
};

#endif
