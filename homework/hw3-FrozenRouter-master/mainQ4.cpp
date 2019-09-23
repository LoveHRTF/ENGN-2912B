#include <iostream>
#include "fibonacci.h"
#include "estimategoldenratio.h"
#include <math.h>

using namespace std;

// TODO:	 Implement src/fibonacci.cpp, and src/estimategoldenratio.cpp
// OPTIONAL: You may modify this file to profile your code using gprof. 

int main() {

	cout.precision(9);

	cout << "Golden ratio is: " << scientific << estimategoldenratio() << endl;
	return 0;

}
