#include <omp.h>
#include <iostream>

// compile using: g++ forLoop.cpp -fopenmp -o forLoop

int main () {
	
	// set the number of threads to maximum possible
	omp_set_num_threads( omp_get_max_threads() );
	
	#pragma omp parallel
	{
		#pragma omp for
		for(int n = 0; n < 10; n++)
		{
			std::cout << n << " ";
		}
	}
	std::cout << std::endl;
	
	return 0;
}








