#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "RNG.h"

using namespace std;

void load_vec_gtest(string const& filename, vector<int32_t>& vec)
{
    // open file via ifstream
    ifstream inputFile(filename, ios::in | ios::binary);

    // verify file is open and read 32-bit integers until eof reached
    assert(inputFile.is_open());
    int32_t value;              // placeholder for each 32-bit integer value
    bool readFlag = true;
    while (readFlag)
    {
        inputFile.read(reinterpret_cast<char *>(&value), sizeof(value));  // read 32-bits at a time
        if (inputFile.eof())
        {
            readFlag = false;
            break;          // stop when eof reached
        }
        vec.push_back(value);
    }

    // close file
    inputFile.close();
}

TEST(hw5RNGTests, WhiteNoiseSeedTest){

  bool testFlag = true;
  int currentPoints_RNG = 0;
  int maxPoints = 5;

  int seed = 1;
  int nSamples = 20;
  unsigned int nBits = 4;

  vector<double> vd(nSamples);
  fill_vec(vd, seed);

  EXPECT_NEAR(-7.30517, vd[0], 1e-5);
  if(HasFailure())
  {
      cerr << "\nWhiteNoiseSeedTest has failed" << endl;
      testFlag = false;
      cout << "\nvd[0]: " << vd[0] << endl;
      cout << "vd[1]: " << vd[1] << endl << endl;
  }

  EXPECT_NEAR(0.909504, vd[7], 1e-5);
  if(HasFailure())
  {
      cerr << "\nWhiteNoiseSeedTest has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
    currentPoints_RNG += 5;
  }

  //cout << "\nWhiteNoiseSeedTest:" << currentPoints_RNG << "/" << maxPoints << endl << endl;

}

TEST(hw5RNGTests, ConvertToFixedTest){

  bool testFlag = true;
  int currentPoints_RNG = 0;
  int maxPoints = 5;

  int nSamples = 20;
  unsigned int nBits = 4;

  vector<double> vd;
  vd.push_back(-7.30517);
  vd.push_back(-10.7017);
  vd.push_back(-9.41018);
  vd.push_back(-10.6586);
  vd.push_back(-20.2995);

  vd.push_back(-5.83076);
  vd.push_back(-10.109);
  vd.push_back(0.909504);
  vd.push_back(-15.3716);
  vd.push_back(-9.93515);

  vd.push_back(-11.3489);
  vd.push_back(-12.9959);
  vd.push_back(-8.9738);
  vd.push_back(-8.74918);
  vd.push_back(-9.74288);

  vd.push_back(-6.89359);
  vd.push_back(-12.4921);
  vd.push_back(-2.56727);
  vd.push_back(-10.378);
  vd.push_back(-15.7444);

  vector<int32_t> vxx;
  pair<double, double> minmax;
  minmax = convert_to_fixed(vd, vxx, nBits);

  ASSERT_EQ(vxx.size(), vd.size());
  EXPECT_EQ(1, vxx[0]);
  if(HasFailure())
  {
      cerr << "\nConvertToFixed has failed" << endl;
      testFlag = false;
  }

  EXPECT_EQ(-8, vxx[4]);
  if(HasFailure())
  {
      cerr << "\nConvertToFixed has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
    currentPoints_RNG += 5;
  }

  //cout << "\nConvertToFixedTest:" << currentPoints_RNG << "/" << maxPoints << endl << endl;

}

TEST(hw5RNGTests, SaveReloadTest){

  bool testFlag = true;
  int currentPoints_RNG = 0;
  int maxPoints = 5;

  int seed = 1;
  int nSamples = 20;
  unsigned int nBits = 4;

  vector<int32_t> vi;
  vi.push_back(1);
  vi.push_back(-1);
  vi.push_back(0);
  vi.push_back(-1);
  vi.push_back(-8);

  string fileName = "RNGSaveReloadTest.dat";
  save_vec(vi, fileName);

  vector<int32_t> vi2;
  load_vec_gtest(fileName, vi2);

  ASSERT_EQ(vi2.size(), vi.size());
  EXPECT_EQ(-1, vi2[1]);
  if(HasFailure())
  {
      cerr << "\nSaveReload has failed" << endl;
      testFlag = false;
  }

  EXPECT_EQ(-1, vi2[3]);
  if(HasFailure())
  {
      cerr << "\nSaveReload has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
    currentPoints_RNG += 5;
  }

  //cout << "\nSaveReloadTest:" << currentPoints_RNG << "/" << maxPoints << endl << endl;

}


TEST(hw5RNGTests, CompleteTest){

  bool testFlag = true;
  int currentPoints_RNG = 0;
  int maxPoints = 5;

  int seed = 1;
  int nSamples = 20;
  unsigned int nBits = 4;

  vector<double> vd(nSamples);
  fill_vec(vd, seed);

  vector<int32_t> vi;
  pair<double, double> minmax;
  minmax = convert_to_fixed(vd, vi, nBits);

  string fileName = "RNGCompleteTest.dat";
  save_vec(vi, fileName);

  vector<int32_t> vi2;
  load_vec_gtest(fileName, vi2);

  vector<double> vd2;
  convert_to_float(vi2, vd2, nBits, minmax);

  ASSERT_EQ(vd2.size(), vd.size());
  EXPECT_NEAR(-8.98805, vd2[2], 1e-5);
  if(HasFailure())
  {
      cerr << "\nSaveReload has failed" << endl;
      testFlag = false;
  }

  EXPECT_NEAR(-6.16018, vd2[5], 1e-5);
  if(HasFailure())
  {
      cerr << "\nSaveReload has failed" << endl;
      testFlag = false;
  }

  if(testFlag)
  {
    currentPoints_RNG += 5;
  }

  //cout << "\nSaveReloadTest:" << currentPoints_RNG << "/" << maxPoints << endl << endl;


}
