/* File Name   : hw1p6.cpp
*  Author      : Ziwei Chen
*  Date        : 09/15/2018
*  Description : This program was base on the idea of hw1p6, to calculate the tolerance
*                base on the integer part, and any number within this tolerance would be
*                considered as equal.
*/
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>


using namespace std;

double epx_tolerance_test(double v);
/*-------------------------------------------------------------------------------*/
int main(){
    /*-------------------------------------------------------------------------------*/
    // Method from hw1p6
    double test_value_a = 4/3;
    double test_value_b_temp1 = 4/3;
    double test_value_b_temp2 = pow(test_value_b_temp1,2);
    double test_value_b = sqrt(test_value_b_temp2);
    double test_delta;   double test_delta_abs;
    
    test_delta = test_value_a - test_value_b;  // Calculate difference
    test_delta_abs = abs(test_delta);          // Calculate abs value
    double eps = epx_tolerance_test (test_value_a); // Get eps value
    
    if (test_delta_abs <= eps){
        cout << "Values are equal!" << endl;
        } else{
            cout << "Values are not equal" << endl;
            }
}

/*-------------------------------------------------------------------------------*/
// This function was from the homework question
double epx_tolerance_test (double v){

    int vpow = ilogb(v) - 52;
    double eps = ldexp(1.0,vpow); //ldexp returns 1.0*2^vpow
    return eps;
}
