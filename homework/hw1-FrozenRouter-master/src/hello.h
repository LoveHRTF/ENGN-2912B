#pragma once

#include <iostream>
#include <string>

using namespace std;

void hello(istream& input)
{
    // TODO: Use the input stream to take in a name and use the standard output stream cout to print out "Hello, my name is <name>!"
    /* Enter your code here. Read input from STDIN to variable 'name'. Print output to STDOUT */
    string name;

    input >> name;
    // cin == input statement, input from name
    std::cout << "Hello, my name is " << name << "!";
    /* std:cout == fprintf() in MATLAB
    *  instead of type cout <<, std::cout << specifies the library it would be using (std lib)
    *  :: == scope resultion operator
    *  << == overload in C++ (function and operator overload), however bit shift in C
    *  "" == string value
    */
}





