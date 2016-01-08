/*
 * File: intArray.h
 * Author: Nihcolas Baxter
 * Created: October 30, 2015
 */


#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

template <class T>
class Array {
public:
	Array<T>();
	Array<T>(int arraySize, T value=0);
	Array<T>(T anArray[], int arraySize);
	Array<T>(const Array<T> &orig);
	virtual ~Array();
	
	Array<T> & operator=(Array<T> &rhs);
	const Array<T> & operator+(const Array<T> &rhs) const;
	const Array<T> & operator-(const Array<T> &rhs) const;
	Array<T> & operator++();//Prefix
	Array<T> & operator++(int dummy);//Postfix
	bool operator==(Array<T> &rhs) const;
	const Array<T> & operator+=(const Array<T> &rhs);
	const Array<T> & operator-=(const Array<T> &rhs);
	int operator[](int index) const;//equivalent to get
	int & operator[](int index); //equivalent to set
	
	void Print() const;
	void set(int index, T value);
	int get(int index) const;
	int size() const;
	void insert(int index, T value);
	int remove(int index);
	void add(Array<T> &rhs);
	void subtract(Array<T> &rhs);
	void copy(Array<T> &rhs);
	
	friend ostream & operator<<(ostream &outStream, const Array<T> &rhs){
		return 0;
	};
	friend istream & operator>>(istream &inStream, Array<T> &rhs){ 
		return 0;
	};

private:
	int Size;
	int *Data;
};

#endif /* ARRAY_H */
