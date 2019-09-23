#include <omp.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>

// compile using: g++ criticalSectionExample.cpp -fopenmp -o criticalSectionExample

#define SIZE 100000000

int main () {
    
    int data[SIZE];
    int maximumValue;
    std::chrono::duration<double> executionTime;

    // fill the data with random values
    for(int i = 0; i < SIZE; i++)
    {
        data[i] = rand();
    }
    
    // find the maximum using critical section
    maximumValue = data[0];

    auto t1 = std::chrono::high_resolution_clock::now();
    
    #pragma omp parallel for num_threads(4)
    for(int i = 1; i < SIZE; i++)
    {
        if (data[i] > maximumValue)
        {
            #pragma omp critical
            {
                // compare data[i] and maximumValue again because maximumValue 
                // could have been changed by another thread after the comparison
                // outside the critical section
                if (data[i] > maximumValue)
                    maximumValue = data[i];
            }
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    // measure execution time
    executionTime = t2 - t1;

    std::cout << "Maximum value (critical section): " << maximumValue << std::endl;
    std::cout << "Execution time: " << executionTime.count() << " seconds" << std::endl;
    
    
    // find the maximum using reduction
    maximumValue = data[0];
    
    t1 = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for reduction(max : maximumValue) num_threads(4)
    for(int i = 1; i < SIZE; i++)
    {
        if (data[i] > maximumValue)
            maximumValue = data[i];
    }

    t2 = std::chrono::high_resolution_clock::now();

    // measure execution time
    executionTime = t2 - t1;

    std::cout << "Maximum value (reduction): " << maximumValue << std::endl;
    std::cout << "Execution time: " << executionTime.count() << " seconds" << std::endl;

    return 0;    
    
}
