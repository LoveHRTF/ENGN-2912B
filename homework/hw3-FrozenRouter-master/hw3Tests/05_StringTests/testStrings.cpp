#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "concat.h"
#include "substr.h"
#include "erase.h"

using namespace std;

TEST(hw3StringTests, ConcatTest){

    bool testFlag;
    int currentPoints_concat = 0;
    int maxPoints = 5;

    testFlag = true;

    char s1[5] = {'e', 'n', 'g', 'n', '\0'};
    char s2[6] = {'2', '9', '1', '2', 'b', '\0'};
    char *res = concat(s1, s2);
    string myres(res);

    EXPECT_EQ("engn2912b", myres);
    if(HasFailure())
    {
	      cerr << "\nString concatenation test has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_concat += 5;
    }

    cout << "\nConcat Test: " << currentPoints_concat << "/" << maxPoints << endl;
    delete [] res;

}

TEST(hw3StringTests, SubstrTest){

    bool testFlag;
    int currentPoints_substr = 0;
    int maxPoints = 5;

    testFlag = true;

    unsigned pos;
    char s1[10] = {'e', 'n', 'g', 'n', '2', '9', '1', '2', 'b', '\0'};
    char s2[5] = {'2', '9', '1', '2', '\0'};

    bool res = substr(s1, s2, pos);

    EXPECT_EQ(true, res);
    if(HasFailure())
    {
	      cerr << "\nSubstring test 1 has failed" << endl;
	      testFlag = false;
    }

    EXPECT_EQ(4, pos);
    if(HasFailure())
    {
	      cerr << "\nSubstring test 2 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_substr += 5;
    }

    cout << "\nSubstr Test: " << currentPoints_substr << "/" << maxPoints << endl;

}

TEST(hw3StringTests, EraseTest){

    bool testFlag;
    int currentPoints_erase = 0;
    int maxPoints = 5;

    testFlag = true;

    char s1[10] = {'e', 'n', 'g', 'n', '2', '9', '1', '2', 'b', '\0'};
    char s2[5] = {'2', '9', '1', '2', '\0'};

    char *res = erase(s1, s2);
    string myres(res);

    EXPECT_EQ("engnb", myres);
    if(HasFailure())
    {
	      cerr << "\nErase test has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_erase += 5;
    }

    cout << "\nErase Test: " << currentPoints_erase << "/" << maxPoints << endl;
    if(string(res).size() < string(s1).size()){
      delete [] res;
    }

}

TEST(hw3StringTests, CombinationTest){

    bool testFlag;
    int currentPoints_comb = 0;
    int maxPoints = 5;

    testFlag = true;

    char s1[10] = {'e', 'n', 'g', 'n', '2', '9', '1', '2', 'b', '\0'};
    char s2[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char s3[3] = {'1', '2', '\0'};
    char s4[4] = {'b', 'h', 'e', '\0'};

    char *res1 = concat(s1, s2);
    char *res2 = erase(res1, s3);
    unsigned pos;
    bool ret = substr(res2, s4, pos);

    EXPECT_EQ(true, ret);
    if(HasFailure())
    {
	      cerr << "\nCombination test 1 has failed" << endl;
	      testFlag = false;
    }

    EXPECT_EQ(6, pos);
    if(HasFailure())
    {
	      cerr << "\nCombination test 2 has failed" << endl;
	      testFlag = false;
    }

    if(testFlag)
    {
	     currentPoints_comb += 5;
    }

    cout << "\nCombination Test: " << currentPoints_comb << "/" << maxPoints << endl;
    if(string(res2).size() < string(res1).size()){
      delete [] res2;
    }
    delete [] res1;

}
