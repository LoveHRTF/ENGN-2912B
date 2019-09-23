#include "translation.h"
#include <iostream>

using namespace std;

int main() {

	double p1_x = 4.0;
	double p1_y = 6.1;

	double p2_x = 200.1;
	double p2_y = 3.14;

	double res_x;
	double res_y;

	bool check;
	check = translation(p1_x, p1_y, p2_x, p2_y, res_x, res_y);
	cout << "Translation Vector: x-axis " << res_x << " y-axis " << res_y << endl;
	
	// TODO: Implement the src/translation.cpp.
	// Pass arguments by reference and use const where appropriate
	// Print out the components of the translation vector (res_x and res_y) here (mainQ3.cpp)

}
