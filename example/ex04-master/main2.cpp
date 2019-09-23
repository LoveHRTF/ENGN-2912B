#include <cstdlib>      // provides atof()
#include <iostream>     // provides cout, cin, precision, fixed, scientific
#include <string>       // provides 'string()'

//#define HEAP_ALLOC

using namespace std;

int main(int nargc, char* argv[])
{

	const unsigned int N = 6;

	// initialize c-style array of integers / chars
	#ifndef HEAP_ALLOC
		cout << endl << "Using the stack..." << endl;

		unsigned int a[N] {0, 1, 2, 3, 4, 5};

	#else
		cout << endl << "Using the heap..." << endl;

		unsigned int* a;
		a = new unsigned int[N] {0, 1, 2, 3, 4, 5};
	
	#endif //HEAP_ALLOC
	
	// display contents of c-style array
	cout << "a[n] = ";
	for (unsigned int n=0; n < N-1; n++){
		cout << a[n] << ", ";
	}
	cout << a[N-1] << endl;


    return 0;
}










/*
	#ifdef HEAP_ALLOC
	delete[] a;
	#endif
*/
