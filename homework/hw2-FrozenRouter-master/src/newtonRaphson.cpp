#include <iostream>
#include "newtonRaphson.h"
#include <cmath>
using namespace std;


double newtonRaphson(double x0, double epsilon)
{
	
   //TODO: Given the initial value x0 and the convergence tolerance epsilon, return the solution of the equation e^x + x^3 - 5 = 0 
   double x_prev; double x_next;
   do {
       x_prev = x0;
       x0 = x0 - (exp(x0) + pow(x0,3) - 5)/(exp(x0) + 3 * pow(x0,2));
       x_next = x0;
       }
       while(abs(x_next - x_prev) >= epsilon);

       return x_next;
       }
