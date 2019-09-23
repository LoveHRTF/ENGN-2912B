#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "Matrix2x2.h"

using namespace std;

TEST(hw3ClassesTests, DetTest){

    bool testFlag;
    int currentPoints_Matrix = 0;
    int maxPoints = 5;

    testFlag = true;
    Matrix2x2 A(3.0, 2.0, 1.0, 3.0);
    double d = A.Det();

    EXPECT_NEAR(7, d, 1e-5);
    if(HasFailure())
    {
	      cerr << "\nDeterminant Test has failed" << endl;
	      testFlag = false;
    }
    if(testFlag)
    {
	      currentPoints_Matrix += 5;
    }

    cout << "\nDet Test: " << currentPoints_Matrix << "/" << maxPoints << endl;

}

TEST(hw3ClassesTests, InvTest){

    bool testFlag;
    int currentPoints_Matrix = 0;
    int maxPoints = 5;

    testFlag = true;
    double data[4] = {2.0, 5.0, 1.0, 3.0};
    Matrix2x2 A(data);
    Matrix2x2 B;
    B = A;
    Matrix2x2 C = B.Inv();

    EXPECT_NEAR(3.0, C.geta1(), 1e-5);
    if(HasFailure())
    {
	      cerr << "\nInverse Test has failed" << endl;
	      testFlag = false;
    }

    EXPECT_NEAR(-5.0, C.geta2(), 1e-5);
    if(HasFailure())
    {
  		cerr << "\nInverse Test has failed" << endl;
  		testFlag = false;
    }

    EXPECT_NEAR(-1.0, C.geta3(), 1e-5);
    if(HasFailure())
    {
  		cerr << "\nInverse Test has failed" << endl;
  		testFlag = false;
    }

    EXPECT_NEAR(2.0, C.geta4(), 1e-5);
    if(HasFailure())
    {
  		cerr << "\nInverse Test has failed" << endl;
  		testFlag = false;
    }

    if(testFlag)
    {
	      currentPoints_Matrix += 5;
    }

    cout << "\nInv Test: " << currentPoints_Matrix << "/" << maxPoints << endl;

}


TEST(hw3ClassesTests, AddTest){

    bool testFlag;
    int currentPoints_Matrix = 0;
    int maxPoints = 5;

    testFlag = true;
    Matrix2x2 A(3.0, 1.0, 2.0, 2.0);
    Matrix2x2 B(3.0, 1.0, 2.0, 2.0);
    Matrix2x2 C(A + (-B));

    EXPECT_NEAR(0.0, C.geta1(), 1e-5);
    if(HasFailure())
    {
  		cerr << "\nAddition Test has failed" << endl;
  		testFlag = false;
    }

    EXPECT_NEAR(0.0, C.geta2(), 1e-5);
    if(HasFailure())
    {
  		cerr << "\nAddition Test has failed" << endl;
  		testFlag = false;
    }

    EXPECT_NEAR(0.0, C.geta3(), 1e-5);
    if(HasFailure())
    {
  		cerr << "\nAddition Test has failed" << endl;
  		testFlag = false;
    }

    EXPECT_NEAR(0.0, C.geta4(), 1e-5);
    if(HasFailure())
    {
  		cerr << "\nAddition Test has failed" << endl;
  		testFlag = false;
    }

    if(testFlag) {
	      currentPoints_Matrix += 5;
    }

    cout << "\nAdd Test: " << currentPoints_Matrix << "/" << maxPoints << endl;

}

TEST(hw3ClassesTests, MultTest){

  bool testFlag;
  int currentPoints_Matrix = 0;
  int maxPoints = 5;

  testFlag = true;
  Matrix2x2 A(3.0, 1.0, 2.0, 2.0);
  Matrix2x2 B(1.0, 0.0, 2.0, 1.0);

  Matrix2x2 C = A * (B * 2.0);

  EXPECT_NEAR(10.0, C.geta1(), 1e-5);
  if(HasFailure())
  {
		cerr << "\nMultiplication Test has failed" << endl;
		testFlag = false;
  }

  EXPECT_NEAR(2.0, C.geta2(), 1e-5);
  if(HasFailure())
  {
		cerr << "\nMultiplication Test has failed" << endl;
		testFlag = false;
  }

  EXPECT_NEAR(12.0, C.geta3(), 1e-5);
  if(HasFailure())
  {
		cerr << "\nMultiplication Test has failed" << endl;
		testFlag = false;
  }

  EXPECT_NEAR(4.0, C.geta4(), 1e-5);
  if(HasFailure())
  {
		cerr << "\nMultiplication Test has failed" << endl;
		testFlag = false;
  }

  if(testFlag) {
      currentPoints_Matrix += 5;
  }

  cout << "\nMult Test: " << currentPoints_Matrix << "/" << maxPoints << endl;

}
