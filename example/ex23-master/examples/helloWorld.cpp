#include <omp.h>
#include <iostream>

// compile using: g++ helloWorld.cpp -fopenmp -o helloWorld

int main () {
	
	#pragma omp parallel num_threads(4)
	{
		// code inside this region runs in parallel
		std::cout << "Thread id: " << omp_get_thread_num() << std::endl;
		std::cout << "Hello World!";
	}
	std::cout << std::endl;
	
	return 0;
}
