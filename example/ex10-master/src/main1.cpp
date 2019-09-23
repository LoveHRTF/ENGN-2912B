#include <iostream>
#include <cassert>
#include <math.h>

#define DEBUG

using namespace std;

// test function declaration
float y1(float x);
float y2(float x);

/*
 * trapz() - This function computes an approximate definite integral using the
 * Trapezoidal Rule with uniform grid spacing.
 *
 * Inputs:
 * 	- float (*fn)(float):	pointer to some function f(x)
 * 	- const float a:		integral lower bound
 * 	- const float b:		integral upper bound
 * 	- const int N:			number of computational grids between a and b
 *
 * Output:
 *  - float:				approximate integral result
 *
 * Adopted from: https://www.geeksforgeeks.org/trapezoidal-rule-for-approximate-value-of-definite-integral
 */
float trapz(float (*fn)(float), const float a, const float b, const int N) {

	// validate input
	assert (b > a);
	assert (N > 1);

	// grid spacing
	float h = (b-a)/N;
	#ifdef DEBUG
	cout << "Grid size:  " << h << endl;
	#endif //DEBUG

	// compute value and sum first and last values in series
	float sum = fn(a) + fn(b);
	#ifdef DEBUG
	cout << "f(" << a << ") + f(" << b << ") = " << sum << endl;
	#endif //DEBUG

	// add to cumulative sum using trapezoidal rule
	for (int i=1; i < N; i++) {
		sum += 2*fn(a + i*h);
		#ifdef DEBUG
		cout << "cumsum{f(" << static_cast<float>(i)*h << ")} = " << sum << endl;
		#endif
	}

	return sum * h/2;
}

//
// define a set of test functions
float y1(float x){
	// y(x) = 1/(1+x^2)
	return 1.0/(1.0+x*x);
}

float y2(float x){
	// y(x) = |x|
	return fabs(x);
}


//
// main function
int main(int argc, char* argv[]) {

	// define the default grid size
	int N = 10;

	// initialize integral range and number of uniform grid points
	float a = 0;
	float b = 1;

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
	float y_int_a_b1 = trapz(y1,a,b,N);
	cout << "Value of definite integral (y1) is " << y_int_a_b1 << endl << endl;

	float y_int_a_b2 = trapz(y2,a,b,N);
	cout << "Value of definite integral (y2) is " << y_int_a_b2 << endl;

	return 0;
}
