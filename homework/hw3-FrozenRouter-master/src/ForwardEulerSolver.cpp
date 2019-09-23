#include "AbstractOdeSolver.h"
#include "ForwardEulerSolver.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double ForwardEulerSolver::SolveEquation(){

	// TODO: 1) Implement the SolveEquation method and return the function value at final time point
	//			i.e., y_i[finalTime].
	//		 2) Print the interim values using cout.
	int arraySize = (finalTime - initialTime)/stepSize;

	if (((finalTime - initialTime)/stepSize) - arraySize >= 0){
		arraySize ++;
	}

	double* y = new double[arraySize];
	y[0] = initialValue;

	double* t = new double[arraySize];
	t[0] = initialTime;

	int i;

	for (i = 1; i < arraySize; i++){

		// Compute
		y[i] = y[i-1] + stepSize * RightHandSide(y[i-1], t[i-1]);
		t[i] = t[i-1] + stepSize;
		
		// ostream output to screen
		cout << "y[" << i << "] = " << y[i] << endl;
		cout << "t[" << i << "] = " << t[i] << endl;

	}

	double myResult = y[arraySize - 1];
	cout << "myResult: " << myResult << endl;
	delete[] y;
	delete[] t;
	return myResult;


	//return 0.0;
}