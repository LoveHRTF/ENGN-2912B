#include <omp.h>
#include <iostream>
#include <string>

// compile using: g++ lastPrivateExample.cpp -fopenmp -o lastPrivateExample

int main () {
    
    int i;
    int x = 44;
	
	#pragma omp parallel for lastprivate(x) num_threads(4)
	for(i = 0; i <= 10; i++)
	{
	    x = i;
	    std::cout << "Thread number: " << omp_get_thread_num() << " x: " << x << std::endl;
	}
	
	std::cout << "x is " << x << std::endl;
	
	return 0;
}




