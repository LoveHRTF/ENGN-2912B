#include <cmath>
#include <iostream>

#include "estimatePiSeries.h"
#include "estimatePiRecurrence.h"

using namespace std;

/*
 * Calculate the error tolerance, epsilon
 */
double calcEpsilon(const double v, const unsigned int N){
  int vpow = ilogb(v) - N;
  double eps = ldexp(1.0, vpow);
  return eps;
}

 /*
  * Estimate value of PI using two different methods
  * Use calcEpsilon function to compute precision value
  * Profile your code using gprof
 */
int main() {

  // Question 3: PI Approximation

  // DO NOT MODIFY THESE VALUES
  unsigned errorTolerance = 32;
  unsigned printPrecision = 10;

  double eps = calcEpsilon(REF_PI, errorTolerance);
  cout.precision(printPrecision);
	cout << "Calculating Pi to the following precision:" << endl;
	cout << "Eps.  = " << eps << endl << endl;

  // Calculate pi using recurrence relation
  double pi_val_2 = estimatePiRecurrence(eps);
  cout.precision(printPrecision);
  cout << "Estimate of pi obtained from estimatePiRecurrence:" << endl;
  cout << pi_val_2 << endl << endl;

  // Calculate pi using Gregory series
  double pi_val_1 = estimatePiSeries(eps);
  cout.precision(printPrecision);
  cout << "Estimate of pi obtained from estimatePiSeries:" << endl;
  cout << pi_val_1 << endl << endl;

  return 0;

}
