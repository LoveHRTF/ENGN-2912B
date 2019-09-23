#include <omp.h>
#include <unistd.h>
#include <iostream>
#include <chrono>

// compile using: g++ staticInefficientSchedule.cpp -fopenmp -o staticInefficientSchedule

int main () {
	
	int i;
		
	auto t1 = std::chrono::high_resolution_clock::now();

	#pragma omp parallel for schedule(static) num_threads(4)
	for(i=0; i < 16; i++)
	{
		// wait for i seconds
		sleep(i);
		std::cout << "Thread " << omp_get_thread_num() << " has completed iteration " << i << std::endl;
	}

	auto t2 = std::chrono::high_resolution_clock::now();

	// measure execution time
	std::chrono::duration<double> executionTime = t2 - t1;
	
	// all threads done
	std::cout << "All done!" << std::endl;
	std::cout << "Total execution time: " << executionTime.count() << " seconds" << std::endl;
	return 0;
}
