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

using namespace std;

double epx_tolerance_test(double v);

int main(){

    double test_value = - 3.1415926535;
    double previous_tolerance = 1.000; double tolerance = 1.000;
    int count_Increase = 0; int count_Decrease = 0; int count_Equal = 0;
    cout << "STARTS!!" << endl;
    /*-------------------------------------------------------------------------------*/
    // For testing the linera part
    for (int index = 0; index <= 10; index ++){

        tolerance = epx_tolerance_test (test_value);

        test_value = test_value + 3.1415926535;      // Increase testing value

        if (index >= 1){
            if (tolerance > previous_tolerance){
                count_Increase ++;
            } else if (tolerance < previous_tolerance){
                count_Decrease ++;
            } else{
                count_Equal ++;
            }
        }
        previous_tolerance = tolerance;
    }
    // Print out linear section
    cout << "Linear Done!!" << endl;
    cout << "Increase Count" << endl; cout << count_Increase << endl;
    cout << "Decrease Count" << endl; cout << count_Decrease << endl;
    cout << "Equal Count" << endl;    cout << count_Equal << endl;
    /*-------------------------------------------------------------------------------*/
    test_value = - 3.1415926535;
    previous_tolerance = 1.000; tolerance = 1.000;
    count_Increase = 0; count_Decrease = 0; count_Equal = 0;
        for (int index = 0; index <= 10; index ++){

        tolerance = epx_tolerance_test (test_value);

        test_value = pow(test_value,2);      // Increase testing value

        if (index >= 1){
            if (tolerance > previous_tolerance){
                count_Increase ++;
            } else if (tolerance < previous_tolerance){
                count_Decrease ++;
            } else{
                count_Equal ++;
            }
        }
        previous_tolerance = tolerance;
    }
    // Print out power section
    cout << "Pwr Done!!" << endl;
    cout << "Increase Count" << endl; cout << count_Increase << endl;
    cout << "Decrease Count" << endl; cout << count_Decrease << endl;
    cout << "Equal Count" << endl;    cout << count_Equal << endl;
    /*-------------------------------------------------------------------------------*/
    return 0;
}


// This function was from the homework question
double epx_tolerance_test (double v){

    int vpow = ilogb(v) - 52;
    double eps = ldexp(1.0,vpow); //ldexp returns 1.0*2^vpow
    return eps;
}