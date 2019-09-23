/* File Name   : hw1p1.cpp
*  Author      : Ziwei Chen
*  Date        : 09/11/2018
*  Description : This file was for ENGN 2912B Assignment 01 part 4 Q1
*                Finding the best precision can achieve for fload and doubleclear.
*                Original code from instruction was not giving fixed digits output, therefore,
*                additional line of cout << fixed was added.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    double x = 0.14580858; float y = 0.14580858;
    int precision_min = 1; int persition_max = 70;

    // Find the precision for double
    for (int digit = precision_min; digit <= persition_max; ++ digit ){
        
        cout << fixed;
        cout.precision(digit);
        cout << x << endl;
    }

    // Find the precision for float
    for (int digit = precision_min; digit <= persition_max; ++ digit ){
        
        cout << fixed;
        cout.precision(digit);
        cout << y << endl;
    }
    return 0;
} 
