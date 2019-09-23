#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "pairs.h"

using namespace std;

TEST(hw4PairsTests, ConstructorTests){

  int currentPoints = 0;
  int maxPoints = 2;
  bool testFlag = true;

  for(unsigned i = 0; i < 2; i++){

    if ( i == 0 )
    {

      testFlag = true;
      pairs<double, string> p3(2.7568, "C++ is fun!");

      EXPECT_NEAR(2.7568, p3.get_first(), 1e-5);
      if(HasFailure())
      {
        cerr << "\nConstructorTest1 has failed" << endl;
        testFlag = false;
      }

      EXPECT_EQ("C++ is fun!", p3.get_second());
      if(HasFailure())
      {
        cerr << "\nConstructorTest2 has failed" << endl;
        testFlag = false;
      }

      if(testFlag)
      {
        currentPoints += 1;
      }

    } else {

      testFlag = true;
      pairs<int, double> p1;
      pairs<int, double> p2 = p1;
      p1.set_first(-145);
      p1.set_second(-2.1459);

      EXPECT_EQ(0, p2.get_first());
      if(HasFailure())
      {
        cerr << "\nCopyConstructorTest1 has failed" << endl;
        testFlag = false;
      }

      EXPECT_EQ(0, p2.get_second());
      if(HasFailure())
      {
        cerr << "\nCopyConstructorTest2 has failed" << endl;
        testFlag = false;
      }

      if(testFlag)
      {
        currentPoints += 1;
      }

    }

  }
  cout << "\nConstructor Tests: " << currentPoints << "/" << maxPoints << endl;

}

TEST(hw4PairsTests, AccessorMutatorTests){

  int currentPoints = 0;
  int maxPoints = 2;
  bool testFlag = true;

  pairs<int, double> p1;
  p1.set_first(-145);
  p1.set_second(-2.1459);

  EXPECT_EQ(-145, p1.get_first());
  if(HasFailure())
  {
    cerr << "\nAccessorMutatorTest1 has failed" << endl;
    testFlag = false;
  }

  EXPECT_NEAR(-2.1459, p1.get_second(), 1e-5);
  if(HasFailure())
  {
    cerr << "\nAccessorMutatorTest2 has failed" << endl;
    testFlag = false;
  }

  if(testFlag)
  {
    currentPoints += 2;
  }
  cout << "\nAccessor Mutator Tests: " << currentPoints << "/" << maxPoints << endl;

}

TEST(hw4PairsTests, OperatorOverloadTests){

  int currentPoints = 0;
  int maxPoints = 2;
  bool testFlag = true;

  for(unsigned i = 0; i < 2; i++){
    if ( i == 0 )
    {
      testFlag = true;
      pairs<int, double> p1;
      pairs<int, double> p2 = p1;
      p1.set_first(-10);
      p1.set_second(-275);

      EXPECT_EQ(0, (p1 == p2));
      if(HasFailure())
      {
        cerr << "\n==OperatorTest1 has failed" << endl;
        testFlag = false;
      }

      if(testFlag)
      {
        currentPoints += 1;
      }

    } else {
      testFlag = true;
      pairs<int, double> p1;
      pairs<int, double> p2 = p1;
      p1.set_first(-10);
      p1.set_second(-275);

      EXPECT_EQ(1, (p1 != p2));
      if(HasFailure())
      {
        cerr << "\n!=OperatorTest2 has failed" << endl;
        testFlag = false;
      }

      if(testFlag)
      {
        currentPoints += 1;
      }

    }

  }
  cout << "\nOperator Tests: " << currentPoints << "/" << maxPoints << endl;

}

TEST(hw4PairsTests, PrintTest){

  int currentPoints = 0;
  int maxPoints = 2;
  bool testFlag = true;

  pairs<int, double> p1;
  p1.set_first(10);
  p1.set_second(3.0);

  testing::internal::CaptureStdout();
  p1.print();
  string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ("(10, 3)\n", output);
  if(HasFailure())
  {
    cerr << "\nPrintTest has failed" << endl;
    testFlag = false;
  }

  if(testFlag)
  {
    currentPoints += 2;
  }
  cout << "\nPrint Test: " << currentPoints << "/" << maxPoints << endl;

}

TEST(hw4PairsTests, OutputStreamTest){

  int currentPoints = 0;
  int maxPoints = 2;
  bool testFlag = true;

  pairs<int, double> p1;
  p1.set_first(10);
  p1.set_second(3.0);

  testing::internal::CaptureStdout();
  cout << p1 << endl;
  string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ("(10, 3)\n", output );
  if(HasFailure())
  {
    cerr << "\n<<OutputStreamTest has failed" << endl;
    testFlag = false;
  }

  if(testFlag)
  {
    currentPoints += 2;
  }

  cout << "\nOutput Stream Test: " << currentPoints << "/" << maxPoints << endl;

}
