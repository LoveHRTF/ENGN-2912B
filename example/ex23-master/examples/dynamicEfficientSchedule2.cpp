#include <omp.h>
#include <unistd.h>
#include <iostream>
#include <chrono>

// compile using: g++ dynamicEfficientSchedule2.cpp -fopenmp -o dynamicEfficientSchedule2

#define THREADS 16
#define N 100000000
#define CHUNK 100

int main () {
	
	int i;
	
	std::cout << "Running " << N << " iterations on " << THREADS << " threads dynamically" << std::endl;
		
	auto t1 = std::chrono::high_resolution_clock::now();

	#pragma omp parallel for schedule(dynamic, CHUNK) num_threads(THREADS)
	for(i=0; i < N; i++)
	{
		// a loop that does not take very long
	}

	auto t2 = std::chrono::high_resolution_clock::now();

	// measure execution time
	std::chrono::duration<double> executionTime = t2 - t1;
	
	// all threads done
	std::cout << "All done!" << std::endl;
	std::cout << "Total execution time: " << executionTime.count() << " seconds" << std::endl;
	return 0;
}



