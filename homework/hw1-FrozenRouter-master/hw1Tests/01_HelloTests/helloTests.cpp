#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "hello.h"

using namespace std;

int currentPoints_Hello = 0;
int maxPoints = 10;

TEST(hw1HelloTests, stringComparisonTests){

    bool testFlag = true;

    stringstream myStream;
    string output;

    myStream << "Jason";
    testing::internal::CaptureStdout();
    hello(myStream);
    output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ("Hello, my name is " + myStream.str() + "!", output); 
    if(HasFailure()) 
    {
	cerr << "\n<<stringComparisonTests1 has failed" << endl;
	testFlag = false;
    }


    testFlag = true;
    myStream.str(string());
    myStream.clear();

    myStream << "Snuffles";
    testing::internal::CaptureStdout();
    hello(myStream);
    output = testing::internal::GetCapturedStdout(); 

    EXPECT_EQ("Hello, my name is " + myStream.str() + "!", output); 
    if(HasFailure()) 
    {
	cerr << "\n<<stringComparisonTests2 has failed" << endl;
	testFlag = false;
    }

    if(testFlag)
    {
            currentPoints_Hello += 10;
    }


    cout << "\nCurrent Score Hello Test: " << currentPoints_Hello << "/" << maxPoints << endl;

}


