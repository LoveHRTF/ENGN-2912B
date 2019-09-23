#include <iostream>
#include "gtest/gtest.h"
#include "translation.h"

using namespace std;

TEST(hw3TranslationTests, TranslationTest1){

    bool testFlag;
    int currentPoints_Translation = 0;
    int maxPoints = 5;

    testFlag = true;
    double p1_x = 4.0;
    double p1_y = 6.1;
    double p2_x = 200.1;
    double p2_y = 3.14;

    double res_x;
    double res_y;

    bool ret = translation(p1_x, p1_y, p2_x, p2_y, res_x, res_y);

    EXPECT_NEAR(196.1, res_x, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 1 has failed" << endl;
	      testFlag = false;
    }

    EXPECT_NEAR(-2.96, res_y, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 1 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_Translation+= 5;
    }

    cout << "\nTranslation Test 1: " << currentPoints_Translation << "/" << maxPoints << endl;

}

TEST(hw3TranslationTests, TranslationTest2){

    bool testFlag;
    int currentPoints_Translation = 0;
    int maxPoints = 5;

    testFlag = true;
    double p2_x = 200.1;
    double p2_y = 3.14;
    double p3_x = 92.6;
    double p3_y = 20.7114;
    double res_x;
    double res_y;

    bool ret = translation(p2_x, p2_y, p3_x, p3_y, res_x, res_y);

    EXPECT_NEAR(-107.5, res_x, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 2 has failed" << endl;
	      testFlag = false;
    }

    EXPECT_NEAR(17.5714, res_y, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 2 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	      currentPoints_Translation += 5;
    }

    cout << "\nTranslation Test 2: " << currentPoints_Translation << "/" << maxPoints << endl;

}

TEST(hw3TranslationTests, TranslationTest3){

    bool testFlag;
    int currentPoints_Translation = 0;
    int maxPoints = 5;

    testFlag = true;
    double p3_x = 92.6;
    double p3_y = 20.7114;
    double p4_x = 83.7;
    double p4_y = 7.41;
    double res_x;
    double res_y;

    bool ret = translation(p3_x, p3_y, p4_x, p4_y, res_x, res_y);

    EXPECT_NEAR(-8.9, res_x, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 3 has failed" << endl;
	      testFlag = false;
    }

    EXPECT_NEAR(-13.3014, res_y, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 3 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	      currentPoints_Translation += 5;
    }

    cout << "\nTranslation Test 3: " << currentPoints_Translation << "/" << maxPoints << endl;

}

TEST(hw3TranslationTests, TranslationTest4){

    bool testFlag;
    int currentPoints_Translation = 0;
    int maxPoints = 5;

    testFlag = true;
    double p1_x = 4.0;
    double p1_y = 6.1;
    double p4_x = 83.7;
    double p4_y = 7.41;
    double res_x;
    double res_y;

    bool ret = translation(p4_x, p4_y, p1_x, p1_y, res_x, res_y);

    EXPECT_NEAR(-79.7, res_x, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 4 has failed" << endl;
	      testFlag = false;
    }

    EXPECT_NEAR(-1.31, res_y, 1e-4);
    if(HasFailure())
    {
	      cerr << "\nTranslation Test 4 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	      currentPoints_Translation += 5;
    }

    cout << "\nTranslation Test 4: " << currentPoints_Translation << "/" << maxPoints << endl;

}
