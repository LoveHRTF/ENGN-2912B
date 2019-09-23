// DO NOT MODIFY!

#ifndef RungeKuttaSolver_hpp
#define RungeKuttaSolver_hpp

#include <iostream>
#include "AbstractOdeSolver.h"

class RungeKuttaSolver : public AbstractOdeSolver {

public:

	// define new function variable type
	typedef double(*funcType)(double, double);

	// destructor
	virtual ~RungeKuttaSolver() {}

	// SolveEquation symbol
	double SolveEquation();

	// constructor
	RungeKuttaSolver(funcType function) : f(function) {}

	// Define RightHandSide function
	virtual double RightHandSide(double y, double t)
	{
		return (*f)(y, t);
	}

	funcType f;

};

#endif /* RungeKuttaSolver_hpp */