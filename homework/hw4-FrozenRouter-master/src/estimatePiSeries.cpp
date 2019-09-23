#include <cmath>
#include <iostream>
#include "estimatePiSeries.h"

using namespace std;

/*
 * Check error compared to REF_PI, defined in the header file
 * Use 'fabs()' to define a termination criteria
 */
double estimatePiSeries(const double eps) {

  int n = 1;
  double pi = 0;
  double piPrevious = 0;
  double piQuarter = 0;

  double piDiff = 10;
  cout << REF_PI << endl;
  while(piDiff > eps){
    // Calculate pi/4
    piQuarter = ( pow((-1.0),(n+1.0)) / ((2.0 * n) - 1.0) ) + piQuarter;
    
    // Calculate pi
    // piPrevious = pi;
    pi = piQuarter * 4.0;

    // find difference
    piDiff = fabs(REF_PI - pi);
    
    n++;
  }
  return pi;
}