#include "estimategoldenratio.h"
#include "fibonacci.h"
#include <math.h>
#include <iostream>
#include <cmath>

using namespace std;

// TODO: Determine the limiting golden ratio.

double estimategoldenratio(){

  double my_Fibonacci_1; double my_Fibonacci_2;
  double my_Goden_Ratio = 0; double my_Goden_Ratio_Prev = 0;

  int Flag_YES = 0;
  int N = 2;

  while(Flag_YES == 0){

    my_Fibonacci_1 = fibonacci(N);
    my_Fibonacci_2 = fibonacci(N+1);

    my_Goden_Ratio_Prev = my_Goden_Ratio;             // Save Previous Value Before Calculate Next
    my_Goden_Ratio = my_Fibonacci_2 / my_Fibonacci_1;   // Calculate New Value

    double Ratio_Diff = abs(my_Goden_Ratio_Prev - my_Goden_Ratio);
    
    if (Ratio_Diff <= 0.00000000001){
      Flag_YES = 1;
    }
   
    N ++;
  }
  return my_Goden_Ratio;

}
