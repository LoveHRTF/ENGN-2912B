#include <cmath>
#include "estimatePiRecurrence.h"
#include <iostream>

using namespace std;

/*
*
* Check error compared to REF_PI, defined in the header file
* Use 'fabs()' to define a termination criteria
*/
double estimatePiRecurrence(const double eps){

  double fk = 1;
  double fkPrev = 0;
  double pi = 0;
  double piDiff = 10;
  int k = 0;

  while(piDiff > eps){
    
    // Calculate pi
    pi = pow(2.0,(k + 2)) * (fk - (pow(fk,3.0) / 3.0));
    // Calculate next fk
    k++;
    fkPrev = fk;
    fk = fkPrev / (1.0 + sqrt(1 + pow(fkPrev,2.0)));
    // find difference
    piDiff = fabs(REF_PI - pi);
  }
  return pi;
}