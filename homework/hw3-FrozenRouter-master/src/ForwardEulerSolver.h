// DO NOT MODIFY!

#ifndef ForwardEulerSolver_hpp
#define ForwardEulerSolver_hpp

#include "AbstractOdeSolver.h"

class ForwardEulerSolver : public AbstractOdeSolver {

public:
	// define new function type
	typedef double(*funcType)(double, double);

	// deconstructor
	virtual ~ForwardEulerSolver() {}

	double SolveEquation();

	// constructor
	ForwardEulerSolver(funcType function) : f(function) {}

	// define RightHandSide function
	virtual double RightHandSide(double y, double t)
	{
		return (*f)(y, t);
	}

	funcType f;

};

#endif /* ForwardEulerSolver_hpp */