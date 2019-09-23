#include <iostream>

using namespace std;

/*
 * This program demonstrates the usage of pointers and how they can be pointed
 * to one another by address.  Pointers are, for all intents and purposes, just 
 * an unsigned integer that stores an address.  As such, they can be manipulated
 * in a variety of ways.
 */

int main()
{
    // define a double type
    double x = 1.0;
    
    // pointer to x
    double *p_x;
    p_x = &x;
    
    // pointer to the pointer of x
    double **p_p_x;
    p_p_x = &p_x;
    
    // pointer to the pointer to the pointer of x
    double ***p_p_p_x;
    p_p_p_x = &p_p_x;
    
    cout << "[" << &x << "] = " << x << endl;
    cout << "[" << &p_x << "] = " << p_x << endl;
    cout << "[" << &p_p_x << "] = " << p_p_x << endl;
    cout << "[" << &p_p_p_x << "] = " << p_p_p_x << endl;
    
    return 0;
}

