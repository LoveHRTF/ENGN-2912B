#include <iostream>
#include "gtest/gtest.h"
#include "firFilter.h"

using namespace std;

TEST(hw5FIRTests, Filter1Test){

  bool testFlag = true;
  int currentPoints_FIR = 0;
  int maxPoints = 5;

  int seed1 = 1;
  unsigned nSamp = 1000;

  vector<double> h1 {-1.298243e-02, -1.344417e-02, -6.731882e-03,  4.616917e-03,
       1.522680e-02,  1.928825e-02,  1.353457e-02, -6.473290e-04, -1.716425e-02,
      -2.754786e-02, -2.486875e-02, -7.564225e-03,  1.865813e-02,  4.200030e-02,
       4.871157e-02,  2.870871e-02, -1.960063e-02, -8.742606e-02, -1.576804e-01,
      -2.104837e-01,  7.699227e-01, -2.104837e-01, -1.576804e-01, -8.742606e-02,
      -1.960063e-02,  2.870871e-02,  4.871157e-02,  4.200030e-02,  1.865813e-02,
      -7.564225e-03, -2.486875e-02, -2.754786e-02, -1.716425e-02, -6.473290e-04,
       1.353457e-02,  1.928825e-02,  1.522680e-02,  4.616917e-03, -6.731882e-03,
      -1.344417e-02, -1.298243e-02};

  vector<double> x(nSamp);
  fill_vec(x,seed1);

  firFilter filt1(h1);
  vector<double> y1;

  y1 = filt1.filter(x);

  EXPECT_NEAR(-0.0032, y1[2], 1e-4);
  if(HasFailure())
  {
      cerr << "\nFilter1Test has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR(-0.0418, y1[9], 1e-4);
  if(HasFailure())
  {
      cerr << "\nFilter1Test has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
    currentPoints_FIR += 5;
  }

  //cout << "\nFilter1Test:" << currentPoints_FIR << "/" << maxPoints << endl << endl;

}

TEST(hw5FIRTests, Filter2Test){

  bool testFlag = true;
  int currentPoints_FIR = 0;
  int maxPoints = 5;

  int seed1 = 1;
  unsigned nSamp = 1000;

  vector<double> x(nSamp);
  fill_vec(x,seed1);

  vector<double> h1 {-1.298243e-02, -1.344417e-02, -6.731882e-03,  4.616917e-03,
       1.522680e-02,  1.928825e-02,  1.353457e-02, -6.473290e-04, -1.716425e-02,
      -2.754786e-02, -2.486875e-02, -7.564225e-03,  1.865813e-02,  4.200030e-02,
       4.871157e-02,  2.870871e-02, -1.960063e-02, -8.742606e-02, -1.576804e-01,
      -2.104837e-01,  7.699227e-01, -2.104837e-01, -1.576804e-01, -8.742606e-02,
      -1.960063e-02,  2.870871e-02,  4.871157e-02,  4.200030e-02,  1.865813e-02,
      -7.564225e-03, -2.486875e-02, -2.754786e-02, -1.716425e-02, -6.473290e-04,
       1.353457e-02,  1.928825e-02,  1.522680e-02,  4.616917e-03, -6.731882e-03,
      -1.344417e-02, -1.298243e-02};


  vector<double> h2 {-1.306267e-02, -6.026515e-03,  6.431116e-03,  1.604891e-02,
       1.538888e-02,  3.302295e-03, -1.327078e-02, -2.296994e-02, -1.739909e-02,
       2.345903e-03,  2.466317e-02,  3.355522e-02,  1.895021e-02, -1.488158e-02,
      -4.858100e-02, -5.632421e-02, -1.992927e-02,  5.922448e-02,  1.576357e-01,
       2.388548e-01,  2.702639e-01,  2.388548e-01,  1.576357e-01,  5.922448e-02,
      -1.992927e-02, -5.632421e-02, -4.858100e-02, -1.488158e-02,  1.895021e-02,
       3.355522e-02,  2.466317e-02,  2.345903e-03, -1.739909e-02, -2.296994e-02,
      -1.327078e-02,  3.302295e-03,  1.538888e-02,  1.604891e-02,  6.431116e-03,
      -6.026515e-03, -1.306267e-02};

  firFilter filt1(h1);
  firFilter filt2(h2);
  vector<double> y1, y2;

  y1 = filt1.filter(x);
  y2 = filt2.filter(y1);

  EXPECT_NEAR(-0.0047, y2[12], 1e-4);
  if(HasFailure())
  {
      cerr << "\nFilter2Test has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR(0.0348, y2[23], 1e-4);
  if(HasFailure())
  {
      cerr << "\nFilter2Test has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
    currentPoints_FIR += 5;
  }

  //cout << "\nFilter1Test:" << currentPoints_FIR << "/" << maxPoints << endl << endl;

}

TEST(hw5FIRTests, Filter3Test){

  bool testFlag = true;
  int currentPoints_FIR = 0;
  int maxPoints = 5;

  int seed1 = 1;
  unsigned nSamp = 1000;

  vector<double> h3 { 6.057912e-03,  4.997166e-03,  1.699037e-04, -6.038081e-03,
      -9.677095e-03, -7.681461e-03, -1.997255e-04,  8.867318e-03,  1.382346e-02,
       1.070499e-02,  2.200201e-04, -1.198782e-02, -1.832361e-02, -1.393487e-02,
      -2.286805e-04,  1.525392e-02,  2.295976e-02,  1.720970e-02,  2.243804e-04,
      -1.849567e-02, -2.748475e-02, -2.035104e-02, -2.067248e-04,  2.153133e-02,
       3.164057e-02,  2.317702e-02,  1.763222e-04, -2.418150e-02, -3.517865e-02,
      -2.551676e-02, -1.347681e-04,  2.628356e-02,  3.788006e-02,  2.722439e-02,
       8.453932e-05, -2.770508e-02, -3.957370e-02, -2.819123e-02, -2.880816e-05,
       2.835499e-02,  4.015069e-02,  2.835499e-02, -2.880816e-05, -2.819123e-02,
      -3.957370e-02, -2.770508e-02,  8.453932e-05,  2.722439e-02,  3.788006e-02,
       2.628356e-02, -1.347681e-04, -2.551676e-02, -3.517865e-02, -2.418150e-02,
       1.763222e-04,  2.317702e-02,  3.164057e-02,  2.153133e-02, -2.067248e-04,
      -2.035104e-02, -2.748475e-02, -1.849567e-02,  2.243804e-04,  1.720970e-02,
       2.295976e-02,  1.525392e-02, -2.286805e-04, -1.393487e-02, -1.832361e-02,
      -1.198782e-02,  2.200201e-04,  1.070499e-02,  1.382346e-02,  8.867318e-03,
      -1.997255e-04, -7.681461e-03, -9.677095e-03, -6.038081e-03,  1.699037e-04,
       4.997166e-03,  6.057912e-03};

   vector<double> x(nSamp);
   fill_vec(x,seed1);

   firFilter filt3(h3);
   vector<double> y3;

   y3 = filt3.filter(x);

   EXPECT_NEAR(-0.0087, y3[5], 1e-4);
   if(HasFailure())
   {
       cerr << "\nFilter3Test has failed" << endl;
       testFlag = false;
   }

   EXPECT_NEAR(-0.0053, y3[13], 1e-4);
   if(HasFailure())
   {
       cerr << "\nFilter3Test has failed" << endl;
       testFlag = false;
   }

   if(testFlag)
   {
     currentPoints_FIR += 5;
   }

   //cout << "\nFilter3Test:" << currentPoints_FIR << "/" << maxPoints << endl << endl;

}

TEST(hw5FIRTests, Filter4Test){

  bool testFlag = true;
  int currentPoints_FIR = 0;
  int maxPoints = 5;

  vector<double> h2 {-1.306267e-02, -6.026515e-03,  6.431116e-03,  1.604891e-02,
       1.538888e-02,  3.302295e-03, -1.327078e-02, -2.296994e-02, -1.739909e-02,
       2.345903e-03,  2.466317e-02,  3.355522e-02,  1.895021e-02, -1.488158e-02,
      -4.858100e-02, -5.632421e-02, -1.992927e-02,  5.922448e-02,  1.576357e-01,
       2.388548e-01,  2.702639e-01,  2.388548e-01,  1.576357e-01,  5.922448e-02,
      -1.992927e-02, -5.632421e-02, -4.858100e-02, -1.488158e-02,  1.895021e-02,
       3.355522e-02,  2.466317e-02,  2.345903e-03, -1.739909e-02, -2.296994e-02,
      -1.327078e-02,  3.302295e-03,  1.538888e-02,  1.604891e-02,  6.431116e-03,
      -6.026515e-03, -1.306267e-02};

  firFilter defaultfilt;

  defaultfilt.SetCoef(h2);

  EXPECT_NEAR(-2.296994e-02, defaultfilt.GetCoef()[7], 1e-5);
  if(HasFailure())
  {
      cerr << "\nFilter4Test has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR(-4.858100e-02, defaultfilt.GetCoef()[14], 1e-5);
  if(HasFailure())
  {
      cerr << "\nFilter4Test has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
    currentPoints_FIR += 5;
  }

  //cout << "\nFilter4Test:" << currentPoints_FIR << "/" << maxPoints << endl << endl;

}
