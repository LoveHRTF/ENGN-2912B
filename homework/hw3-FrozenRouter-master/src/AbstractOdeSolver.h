// DO NOT MODIFY!

#ifndef ABSTRACTODESOLVER_HPP
#define ABSTRACTODESOLVER_HPP

class AbstractOdeSolver{

protected:
	double stepSize;
	double initialTime;
	double finalTime;
	double initialValue;

public:
	void SetStepSize(double h);
	void SetTimeInterval(double t0, double t1);
	void SetInitialValue(double y0);
	virtual double SolveEquation() = 0;
	virtual double RightHandSide(double y, double t) = 0;
	
};

#endif //ABSTRACTODESOLVER_HPP
