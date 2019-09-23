#include <iostream>
#include "gtest/gtest.h"
#include "fibonacci.h"
#include "estimategoldenratio.h"

using namespace std;

TEST(hw3FibonacciTests, FibonacciTest1){

    bool testFlag;
    int currentPoints_Fib = 0;
    int maxPoints = 5;

    testFlag = true;

    long long int res = fibonacci(0);

    EXPECT_EQ(0, res);
    if(HasFailure())
    {
	      cerr << "\nFibonacci Test 1 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_Fib+= 5;
    }

    cout << "\nFibonacci Test 1: " << currentPoints_Fib << "/" << maxPoints << endl;

}

TEST(hw3FibonacciTests, FibonacciTest2){

    bool testFlag;
    int currentPoints_Fib = 0;
    int maxPoints = 5;

    testFlag = true;

    long long int res = fibonacci(32);

    EXPECT_EQ(2178309, res);
    if(HasFailure())
    {
	      cerr << "\nFibonacci Test 2 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_Fib+= 5;
    }

    cout << "\nFibonacci Test 2: " << currentPoints_Fib << "/" << maxPoints << endl;

}

TEST(hw3FibonacciTests, FibonacciTest3){

    bool testFlag;
    int currentPoints_Fib = 0;
    int maxPoints = 5;

    testFlag = true;

    long long int res = fibonacci(42);

    EXPECT_EQ(267914296, res);
    if(HasFailure())
    {
	      cerr << "\nFibonacci Test 3 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_Fib+= 5;
    }

    cout << "\nFibonacci Test 3: " << currentPoints_Fib << "/" << maxPoints << endl;

}

TEST(hw3FibonacciTests, GoldenRatioTest){

    bool testFlag;
    int currentPoints_GR = 0;
    int maxPoints = 5;

    testFlag = true;

    double res = estimategoldenratio();

    EXPECT_NEAR(1.61803398875, res, 1e-8);
    if(HasFailure())
    {
	      cerr << "\nGoldren Ratio Test has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_GR+= 5;
    }

    cout << "\nGolden Ratio Test: " << currentPoints_GR << "/" << maxPoints << endl;

}
