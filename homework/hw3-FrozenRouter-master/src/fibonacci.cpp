#include "fibonacci.h"

// TODO: Implement a recursive fibonacci function.

unsigned long long int fibonacci(int n){

  unsigned long long int my_Fibonacci;

  if (n == 0){
    my_Fibonacci = 0;
  } else if (n == 1){
    my_Fibonacci = 1;
  } else {
    my_Fibonacci = fibonacci(n-2) + fibonacci(n-1);
  }

  return my_Fibonacci;
}
