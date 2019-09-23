#include <iostream>
#include "newtonRaphson.h"

using namespace std;

int main() 
{
    // DO NOT MODIFY  
    //Question 1: Newton-Raphson iterative method
    cout << endl;
    cout << "Question 1: Newton-Raphson iterative method" << endl;
    double x0, epsilon;
    cout << "Please input an initial approximate value x0: ";
    cin >> x0;

    cout << "Please enter a tolerance value epsilon: ";
    cin >> epsilon;

    if(epsilon < 0)
    {
        cout << "Convergence tolerance epsilon cannot be negative" << endl;
    }
    else
    {
        cout << "The solution of the equation e^x + x^3 - 5 = 0 is " << newtonRaphson(x0, epsilon) << endl; 
    }

}





