#include <cassert>
#include "fibonacci.hpp"

// compute Fibonacci sequence - pass by pointer
void fibonacci(long long unsigned int *x, const unsigned int N){

	// check input for valid parameters
	assert (N > 2);
	
	// special cases can be computed directly (would otherwise result in segfault!)
	x[0] = 0;
	x[1] = 1;

	// use the direct iterative method
	for (unsigned int n=2; n < N; n++)
		x[n] = x[n-1] + x[n-2];
	
}

