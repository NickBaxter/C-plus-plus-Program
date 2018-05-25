/* 
 * File:   myQuadratic.h
 * Author: Nicholas Baxter
 * Created on August 31, 2015
 */

#ifndef MYQUADRATIC_H
#define MYQUADRATIC_H

class myQuadratic {
 public:
  myQuadratic(); //Default
  myQuadratic(double a, double b, double c);//alternate
  myQuadratic(const myQuadratic& orig); //copy constructor
  //~myQuadratic();//deconstructor(giving me an error when virtual infront of it)
  void PrintCoefficients();
  void GetCoefficients();
  bool HasImaginary();
  void PrintSolutions();
  void SolveSolutions();
  void SetC(double c);
  double GetC() const;
  void SetB(double b);
  double GetB() const;
  void SetA(double a);
  double GetA() const;
private:
    double a, b, c;
    double Solution1, Solution2;
    // double iSolution1, iSolution2;
};

#endif /* MYQUADRATIC_H */
