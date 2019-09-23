#pragma once

#include <iostream>

using namespace std;


void sumIntegers(istream& input)
{
    int a; int b;
    // TODO: Read input from input stream to variables 'a' and 'b'.
    // Compute a + b and print the result to STDOUT.
    // You may want to add another integer variable, but it is not necessary.
    input >> a;
    input >> b;
    std::cout << a + b;

}





