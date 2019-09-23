#include <omp.h>
#include <unistd.h>
#include <iostream>
#include <chrono>

// compile using: g++ guidedSchedule1.cpp -fopenmp -o guidedSchedule1

#define THREADS 16
#define N 100000000

int main () {
	
	int i;
	
	std::cout << "Running " << N << " iterations on " << THREADS << " threads guided" << std::endl;
		
	auto t1 = std::chrono::high_resolution_clock::now();

	#pragma omp parallel for schedule(guided) num_threads(THREADS)
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



