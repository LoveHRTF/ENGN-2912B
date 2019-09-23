#include "gtest/gtest.h"
#include "newtonRaphson.h"

using namespace std;

int currentPoints_NewtonRaphsonCheck = 0;
int maxPoints = 25;

TEST(hw2NewtonRaphsonTests, nearEqualityTests){

    EXPECT_NEAR(1.1943, newtonRaphson(1, 0.1), 1e-5);
    if(HasFailure()) {
        cerr << "\nnearEqualityTest1 has failed" << endl;
    } else {
        currentPoints_NewtonRaphsonCheck += 5;
    }

    EXPECT_NEAR(1.19367, newtonRaphson(1, 0.01), 1e-5);
    if(HasFailure()) {
        cerr << "\nnearEqualityTest2 has failed" << endl;
    } else {
        currentPoints_NewtonRaphsonCheck += 5;
    }

    EXPECT_NEAR(1.19367, newtonRaphson(4, 0.001), 1e-5);
    if(HasFailure()) {
        cerr << "\nnearEqualityTest3 has failed" << endl;
    } else {
        currentPoints_NewtonRaphsonCheck += 5;
    }

    EXPECT_NEAR(1.1937, newtonRaphson(10, 0.01), 1e-5);
    if(HasFailure()) {
        cerr << "\nnearEqualityTest4 has failed" << endl;
    } else {
        currentPoints_NewtonRaphsonCheck += 5;
    }

    EXPECT_NEAR(1.1937, newtonRaphson(500, 0.01), 1e-5);
    if(HasFailure()) {
        cerr << "\nnearEqualityTest5 has failed" << endl;
    } else {
        currentPoints_NewtonRaphsonCheck += 5;
    }


    cout << "\nCurrent Score Newton-Raphson Check Test: " << currentPoints_NewtonRaphsonCheck << "/" << maxPoints << endl;

}


