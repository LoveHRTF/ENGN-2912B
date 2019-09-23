#include <omp.h>
#include <iostream>
#include <string>

// compile using: g++ firstPrivateExample.cpp -fopenmp -o firstPrivateExample

int main () {
	
	std::string a = "x";
	std::string b = "y";
	int c = 3;
	
	#pragma omp parallel firstprivate(a,c) shared(b) num_threads(2)
	{
	    a += "k"; // string concatenation
	    c += 7;
	    std::cout << "A becomes (" << a << "), b is (" << b << ")" << std::endl;
	    std::cout << c << std::endl;
	}

	return 0;
}
