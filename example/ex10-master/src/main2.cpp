#include <iostream>
#include <cassert>
#include <math.h>

#include "integrate.hpp"

using namespace std;

// define a set of test functions

#if 1
	// y1(x) = 1/(1+x^2)
	double y1(double x){
		return 1.0/(1.0+x*x);
	}

	// y2(x) = |x|
	double y2(double x){
		return fabs(x);
	}
#else
	// y1(x) = 1/(1+x^2)
	float y1(float x){
		return 1.0/(1.0+x*x);
	}

	// y2(x) = |x|
	float y2(float x){
		return fabs(x);
	}
#endif


//
// main function
int main(int argc, char* argv[]) {

	// define the default grid size
	int N = 10;

	// initialize integral range and number of uniform grid points
#if 0
	double a = 0.0;
	double b = 1.0;
#else
	float a = 0.0;
	float b = 1.0;
#endif

	// override default arguments
	switch (argc){
		case 4:
			N = atoi(argv[3]);
		case 3:
			b = atof(argv[2]);
			a = atof(argv[1]);
		case 1:
			break;
		default:
			cout << "Invalid number of paramaters entered!" << endl;
			return -1;
	}

	// compute the integral and send to std output
	double y_int_a_b1 = trapz(y1,a,b,N);
	double y_int_a_b2 = trapz(y2,a,b,N);

	cout << "Value of definite integral (y1) is " << y_int_a_b1 << endl;
	cout << "Value of definite integral (y2) is " << y_int_a_b2 << endl;

	return 0;
}
