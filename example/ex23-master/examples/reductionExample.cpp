#include <omp.h>
#include <iostream>
#include <string>

// compile using: g++ reductionExample.cpp -fopenmp -o reductionExample

int factorial (int number)
{
    int fac = 1;
    #pragma omp parallel for reduction(* : fac) num_threads(2)
    for(int n = 2; n <= number; n++)
    {
        fac *= n;
    }
    
    return fac;
}


int main () {
    
	std::cout << "10!: " << factorial(10) << std::endl;
	
	return 0;
}




