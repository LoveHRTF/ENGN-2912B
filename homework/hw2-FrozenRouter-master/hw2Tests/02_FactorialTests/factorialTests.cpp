#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "factorial.h"

using namespace std;

int currentPoints_FactorialCheck = 0;
int maxPoints = 20;

TEST(hw2FactorialTests, equalityTests){

    for(unsigned i = 0; i < 2; i++)
    {
        if(i == 0)
            EXPECT_EQ(120, factorial(5));
        else
            EXPECT_EQ(120, factorial2(5));
        
        if(HasFailure()){ 
            cerr << "\nequalityTests1 has failed" << endl;
            break;
        }
    }

    for(unsigned i = 0; i < 2; i++)
    {
        if(i == 0)
            EXPECT_EQ(479001600, factorial(12));
        else
            EXPECT_EQ(479001600, factorial2(12));
        
        if(HasFailure()){ 
            cerr << "\nequalityTests2 has failed" << endl;
            break;
        }
    }

    bool testFlag = true;
    for(unsigned i = 0; i < 2; i++)
    {
        if(i == 0)
            EXPECT_EQ(2004310016, factorial(15));
        else
            EXPECT_EQ(1307674368000, factorial2(15));
        
        if(HasFailure()){ 
            cerr << "\nequalityTests3 has failed" << endl;
            testFlag = false;
            break;
        }
    }

    if(testFlag){
        currentPoints_FactorialCheck += 10;
    }

    testFlag = true;
    for(unsigned i = 0; i < 2; i++)
    {
        if(i == 0)
            EXPECT_EQ(2076180480, factorial(25));
        else
            EXPECT_NEAR(1.5511210043330986e+25, factorial2(25), 1e+5);
        
        if(HasFailure()){ 
            cerr << "\nequalityTests4 has failed" << endl;
            testFlag = false;
            break;
        }
    }

    if(testFlag){
        currentPoints_FactorialCheck += 10;
    }
    
    cout << "\nCurrent Score Factorial Check Test: " << currentPoints_FactorialCheck << "/" << maxPoints << endl;

}


