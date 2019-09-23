#include <iostream>
#include <cassert>

using namespace std;

// compute the Fibonacci sequence - pass by pointer
void fibonacci(int *x, const int N){

	// check input for valid parameters
	assert (N > 2);
	
	// special cases can be computed directly (would otherwise result in segfault!)
	x[0] = 0;
	x[1] = 1;

	// use the direct iterative method
	for (int n=2; n <= N; n++)
		x[n] = x[n-1] + x[n-2];
	
}


int main(int nargc, char* argv[])
{

	// define the size of sequence to generate (starting at 0)
	const int N = 10;

	// allocate and initialize memory for sequence
	int *x;
	x = new int[N] {0};

	// populate array with the Fibonacci sequence up to N
	fibonacci(x,N);
	
	// display contents of sequence
	for (int n=0; n < N; n++){
		cout << "x[" << n << "] = " << x[n] << endl;
	}

    return 0;
}















	// always clean up memory when you're done with it!
	//delete[] x;
