#include <cstdlib>      // provides atof()
#include <iostream>     // provides cout, cin, precision, fixed, scientific
#include <string>       // provides 'string()'

//#define HEAP_ALLOC

using namespace std;

int main(int nargc, char* argv[])
{

	const unsigned int N = 5;

	// initialize c-style array of integers / chars
	#ifndef HEAP_ALLOC
		cout << endl << "Using the stack..." << endl;

		char a[N] {'b', 'r', 'o', 'w', 'n'};

	#else
		cout << endl << "Using the heap..." << endl;

		char* a;
		a = new char[N] {'b', 'r', 'o', 'w', 'n'};
	
	#endif //HEAP_ALLOC
	
	// display contents of c-style array
	cout << "a[n] = \"";
	for (unsigned int n=0; n < N; n++){
		cout << a[n];
	}
	cout << "\"" << endl;


    return 0;
}










/*
	#ifdef HEAP_ALLOC
	delete[] a;
	#endif
*/
