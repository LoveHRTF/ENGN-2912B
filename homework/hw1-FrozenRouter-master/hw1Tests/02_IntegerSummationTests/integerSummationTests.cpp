#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "sumIntegers.h"

using namespace std;

int currentPoints_IntegerSummation = 0;
int maxPoints = 20;

TEST(hw1IntegerSummationTests, stringComparisonTests){

    bool testFlag = true;

    stringstream myStream;
    string output;

    myStream << 1 << " " << 2;
    testing::internal::CaptureStdout();
    sumIntegers(myStream);
    output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ("3", output); 
    if(HasFailure()) 
    {
	cerr << "\n<<stringComparisonTests1 has failed" << endl;
	testFlag = false;
    }


    testFlag = true;
    myStream.str(string());
    myStream.clear();

    myStream << 5 << " " << 9;
    testing::internal::CaptureStdout();
    sumIntegers(myStream);
    output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ("14", output); 
    if(HasFailure()) 
    {
	cerr << "\n<<stringComparisonTests2 has failed" << endl;
	testFlag = false;
    }

    if(testFlag)
    {
            currentPoints_IntegerSummation += 10;
    }

    testFlag = true;
    myStream.str(string());
    myStream.clear();

    myStream << -5 << " " << 5;
    testing::internal::CaptureStdout();
    sumIntegers(myStream);
    output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ("0", output); 
    if(HasFailure()) 
    {
	cerr << "\n<<stringComparisonTests3 has failed" << endl;
	testFlag = false;
    }

    if(testFlag)
    {
            currentPoints_IntegerSummation += 10;
    }


    cout << "\nCurrent Score Integer Summation Test: " << currentPoints_IntegerSummation << "/" << maxPoints << endl;

}


