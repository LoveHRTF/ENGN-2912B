#include <iostream>
//#include <cmath>
#include "factorial.h"

using namespace std;

unsigned factorial(unsigned n)
{
   unsigned res = 1;
   for(unsigned i = 1; i <= n; ++i)
   {
      res *= i;
   }

   return res;
}

// TODO: Implement a correct factorial2 function that can handle very large integer values. 
double factorial2(unsigned n)
{
       double res = 1;
   for(unsigned i = 1; i <= n; ++i)
   {
      res *= i;
   }

   return res;

}
