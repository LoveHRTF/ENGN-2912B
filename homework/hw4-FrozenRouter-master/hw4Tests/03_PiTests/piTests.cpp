#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "estimatePiSeries.h"
#include "estimatePiRecurrence.h"

using namespace std;

double eps = 4.65e-10;

TEST(hw4PiTests, SeriesTest){

  bool testFlag;
  int currentPoints_series_test = 0;
  int maxPoints = 5;

  testFlag = true;

  double pi_est = estimatePiSeries(eps);

  EXPECT_NEAR(REF_PI, pi_est, eps);
  if(HasFailure())
  {
      cerr << "\nSeries Test has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
     currentPoints_series_test += 5;
  }

  cout << "\nSeries Test: " << currentPoints_series_test << "/" << maxPoints << endl;

}

TEST(hw4PiTests, RecurrenceTest){

  bool testFlag;
  int currentPoints_recurrence_test = 0;
  int maxPoints = 5;

  testFlag = true;

  double pi_est = estimatePiRecurrence(eps);

  EXPECT_NEAR(REF_PI, pi_est, eps);
  if(HasFailure())
  {
      cerr << "\nRecurrence Test has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
     currentPoints_recurrence_test += 5;
  }

  cout << "\nRecurrence Test: " << currentPoints_recurrence_test << "/" << maxPoints << endl;

}
