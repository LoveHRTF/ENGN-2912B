#include "AbstractOdeSolver.h"
#include "RungeKuttaSolver.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double RungeKuttaSolver::SolveEquation() {

	// TODO: 1) Implement the SolveEquation method and return the function value at final time point
	//			i.e., y_i[finalTime].
	//		 2) Print the interim values using cout.
	double k1; double k2; double k3; double k4;

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
		k1 = stepSize * RightHandSide(y[i-1], t[i-1]);
		k2 = stepSize * RightHandSide((y[i-1] + 0.5 * k1), (t[i-1] + 0.5 * stepSize));
		k3 = stepSize * RightHandSide((y[i-1] + 0.5 * k2), (t[i-1] + 0.5 * stepSize));
		k4 = stepSize * RightHandSide((y[i-1] + k3), (t[i-1] + stepSize));

		y[i] = y[i-1] + (1.0/6.0) * (k1 + (2*k2) + (2*k3) + k4);
		t[i] = t[i-1] + stepSize;

		// ostream output to screen
		cout << (k1 + (2*k2) + (2*k3) + k4) << endl;

		cout << "y[" << i << "] = " << y[i] << endl;
		cout << "t[" << i << "] = " << t[i] << endl;
	}

	double myResult = y[arraySize - 1];
	delete[] y;
	delete[] t;
	return myResult;
	//return 0.0;

}
