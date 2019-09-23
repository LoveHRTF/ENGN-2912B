#include <cstdio>			// provides atoi
#include <iostream>
#include <cassert>			// provides assert

#include "fibonacci.hpp"


using namespace std;

int main(int nargc, char* argv[])
{
	// validate user inputs a single parameter
	assert(nargc == 2);

	// read in the size of sequence to generate (starting at 0)
	const unsigned int N = atoi(argv[1]);

	// allocate and initialize memory for sequence
	long long unsigned int *x;
	x = new long long unsigned int[N] {0};

	// populate array with the Fibonacci sequence up to N
	fibonacci(x,N);
	
	// display contents of sequence
	for (unsigned int n=0; n < N; n++){
		cout << "x[" << n << "] = " << x[n] << endl;
	}

	// always clean up memory when you're done with it!
	delete[] x;

    return 0;
}

