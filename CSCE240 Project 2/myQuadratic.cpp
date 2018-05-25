/* 
 * File:   myQuadratic.h
 * Author: Nicholas Baxter
 * Created on August 31, 2015
 */

#include "myQuadratic.h"
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

myQuadratic::myQuadratic() {
  cout << "I am in the default constructor" << endl;
  SetA(0);
  SetB(0);
  SetC(0);
}

myQuadratic::myQuadratic(double _a, double _b, double _c) {
  cout << "I am in the alternate constructor" << endl;
  SetA(_a);
  SetB(_b);
  SetC(_c);
  cout << _a << ", " << _b << ", " << _c <<endl;
}

void myQuadratic::SetA(double _a) {
  a = _a;
}

double myQuadratic::GetA() const {
  return a;
}

void myQuadratic::SetB(double _b) {
  b = _b;
}

double myQuadratic::GetB() const {
  return b;
}

void myQuadratic::SetC(double _c) {
  c = _c;
}

double myQuadratic::GetC() const {
  return c;
}

void myQuadratic::SolveSolutions() {
  a = GetA();
  b = GetB();
  c = GetC();
  
  double sqrtSolution = (b*b)-(4*a*c);
  //rSolution = (-b/(2*a))+(sqrt(iSolution)/(2*a));
  
  if(sqrtSolution < 0) {
    HasImaginary();true;
    Solution1 = sqrt(-1*sqrtSolution)/(2*a);
    Solution2 = sqrt(-1*sqrtSolution)/(2*a);
  }
  else {
    Solution1 = (-b/(2*a))+(sqrt(sqrtSolution)/(2*a));
    Solution2 = (-b/(2*a))-(sqrt(sqrtSolution)/(2*a));
  }
}

void myQuadratic::PrintSolutions() {
  if(HasImaginary() == true) {
    cout << "Imaginary Solution 1: " << (-b/(2*a)) << " + " << Solution1 << "i" <<  endl;
    cout << "Imaginary Solution 2: " << (-b/(2*a)) << " - " << Solution2 << "i" << endl; 
  }
  else {
    cout << "Solution 1: " << Solution1 << endl;
    cout << "Solution 2: " << Solution2 << endl;
  }
}

bool myQuadratic::HasImaginary() {
   if(((b*b)-(4*a*c)) >=0) {
	return false;
   }
   else {
	return true;
   }
}

void myQuadratic::PrintCoefficients() {
  cout << "A: " << GetA() << endl;
  cout << "B: " << GetB() << endl;
  cout << "C: " << GetC() << endl;
  }




