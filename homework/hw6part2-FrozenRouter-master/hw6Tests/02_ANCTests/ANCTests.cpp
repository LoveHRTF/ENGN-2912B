#include <iostream>
#include "gtest/gtest.h"
#include "anc.h"

using namespace std;
using namespace arma;

TEST(hw6ANCTests, WienerFilterTest){

  bool testFlag = true;

  // collect data
  vec observedSignal = readBinaryFile("../data/observed.dat");
  vec noiseReferenceSignal = readBinaryFile("../data/noiseReference.dat");

  ASSERT_EQ( observedSignal.size() > 0, true );
  ASSERT_EQ( noiseReferenceSignal.size() > 0, true );

  // set parameters
  int M = 100;

  // run Wiener Filter
  WienerFilter wF(M);
  vec errorSignal_wF = wF.execute(observedSignal, noiseReferenceSignal);
  vec w_wF = wF.getFilterWeights();
  saveBinaryFile("../results/w_wF.dat", w_wF);
  saveBinaryFile("../results/errorSignal_wF.dat", errorSignal_wF);

  w_wF = readBinaryFile("../results/w_wF.dat");
  errorSignal_wF = readBinaryFile("../results/errorSignal_wF.dat");

  ASSERT_EQ( w_wF.size() > 45, true );
  ASSERT_EQ( errorSignal_wF.size() > 15000, true );

  EXPECT_NEAR( w_wF(45), -4.33306e-05, 1e-06 );
  if(HasFailure())
  {
      cerr << "\nWienerFilterTest has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR( errorSignal_wF(15000), 0.00526683, 1e-06 );
  if(HasFailure())
  {
      cerr << "\nWienerFilterTest has failed" << endl;
      testFlag = false;
  }

}

TEST(hw6ANCTests, LMSFilterTest){

  bool testFlag = true;

  // collect data
  vec observedSignal = readBinaryFile("../data/observed.dat");
  vec noiseReferenceSignal = readBinaryFile("../data/noiseReference.dat");

  ASSERT_EQ( observedSignal.size() > 0, true );
  ASSERT_EQ( noiseReferenceSignal.size() > 0, true );

  // set parameters
  int M = 100;
  int L = 500;
  double mu = 0.0075;

  // run LMS Filter
  LMSFilter lmsF(M, L, mu);
  vec errorSignal_lmsF = lmsF.execute(observedSignal, noiseReferenceSignal);
  vec w_lmsF = lmsF.getFilterWeights();
  saveBinaryFile("../results/w_lmsF.dat", w_lmsF);
  saveBinaryFile("../results/errorSignal_lmsF.dat", errorSignal_lmsF);

  w_lmsF = readBinaryFile("../results/w_lmsF.dat");
  errorSignal_lmsF = readBinaryFile("../results/errorSignal_lmsF.dat");

  ASSERT_EQ( w_lmsF.size() > 45, true );
  ASSERT_EQ( errorSignal_lmsF.size() > 15000, true );

  EXPECT_NEAR( w_lmsF(45), -1.7113e-05, 1e-06 );
  if(HasFailure())
  {
      cerr << "\nLMSFilterTest has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR( errorSignal_lmsF(15000), 0.00585813, 1e-06 );
  if(HasFailure())
  {
      cerr << "\nLMSFilterTest has failed" << endl;
      testFlag = false;
  }

}
