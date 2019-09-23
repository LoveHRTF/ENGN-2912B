#include <iostream>
#include <iomanip>
#include <complex>
#include "gtest/gtest.h"
#include "Matrix.h"

using namespace std;

template<typename T, unsigned int M = 2, unsigned int N = 2>
Matrix<T, M, N> test1(const T* data)
{
  Matrix<T, M, N> C(data);
  C(1, 0) = static_cast<T>(1.0);
  Matrix<T, M, N> E = C;
  E = C.Inv();
  Matrix<T, M, N> F;
  F = E;
  Matrix<T, M, N> G;
  G = -F;
  Matrix<T, M, N> H1, H2;
  H1 = C - G;
  cout << "\nTesting print function:" << endl;
  H1.Print();
  H2 = C + G;
  Matrix<T, M, N> I = H2 * (T) 3.14159265;
  return I;
}

TEST(hw5TemplatedMatrixTests, 2x2FloatTest){

  bool testFlag = true;
  int currentPoints_Matrix = 0;
  int maxPoints = 5;

  const float dArr[4] = { 1.0, 2.0, 3.0, 4.0 };
  Matrix<float, 2, 2> I = test1<float>(dArr);

  EXPECT_NEAR(-3.142, I(0,0), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2FloatTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(9.425, I(0,1), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2FloatTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(4.712, I(1,0), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2FloatTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(10.995, I(1,1), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2FloatTest has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
      currentPoints_Matrix += 5;
  }

  //cout << "\n2x2FloatTest:" << currentPoints_Matrix << "/" << maxPoints << endl << endl;

}


TEST(hw5TemplatedMatrixTests, 2x2IntTest){

  bool testFlag = true;
  int currentPoints_Matrix = 0;
  int maxPoints = 5;

  const int iArr[4] = { 1, -2, 3, -4 };
  Matrix<int, 2, 2> I = test1<int>(iArr);

  EXPECT_EQ(-3, I(0,0));
  if(HasFailure())
  {
      cerr << "\n2x2IntTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_EQ(-3, I(0,1));
  if(HasFailure())
  {
      cerr << "\n2x2IntTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_EQ(3, I(1,0));
  if(HasFailure())
  {
      cerr << "\n2x2IntTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_EQ(-12, I(1,1));
  if(HasFailure())
  {
      cerr << "\n2x2IntTest has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
      currentPoints_Matrix += 5;
  }

  //cout << "\n2x2IntTest:" << currentPoints_Matrix << "/" << maxPoints << endl << endl;

}

TEST(hw5TemplatedMatrixTests, 2x2ComplexTest){

  bool testFlag = true;
  int currentPoints_Matrix = 0;
  int maxPoints = 5;

  const complex<double> cArr[4] = { { sqrt(2),-sqrt(2) },{ 0,2 },{ 3,0 },{ 4,4 } };
  Matrix<complex<double>, 2, 2> I = test1<complex<double>>(cArr);

  EXPECT_NEAR(3.5562, real(I(0,0)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(-5.7103, imag(I(0,0)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR(-0.0952, real(I(0,1)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(6.8217, imag(I(0,1)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR(3.4109, real(I(1,0)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(0.0476, imag(I(1,0)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR(12.1183, real(I(1,1)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(12.8799, imag(I(1,1)), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2ComplexTest has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
      currentPoints_Matrix += 5;
  }

  //cout << "\n2x2ComplexTest:" << currentPoints_Matrix << "/" << maxPoints << endl << endl;

}

TEST(hw5TemplatedMatrixTests, 4x4DoubleTest){

  bool testFlag = true;
  int currentPoints_Matrix = 0;
  int maxPoints = 5;

  double dArr[16] = { 3,7,4,2,0,3,4,5,1,10,8,4,8,0,8,6 };
  Matrix<double, 4, 4> I = test1<double, 4, 4>(dArr);


  EXPECT_NEAR(8.647, I(0,0), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x2DoubleTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(9.275, I(1,1), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x22x2DoubleTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(12.218, I(2,3), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x22x2DoubleTest has failed" << endl;
      testFlag = false;
  }
  EXPECT_NEAR(24.863, I(3,0), 1e-3);
  if(HasFailure())
  {
      cerr << "\n2x22x2DoubleTest has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
      currentPoints_Matrix += 5;
  }

  //cout << "\n2x2DoubleTest:" << currentPoints_Matrix << "/" << maxPoints << endl << endl;

}
