#include <iostream>
#include "gtest/gtest.h"
#include "dnaFindPattern.h"

using namespace std;

TEST(hw6DNAPatternTests, Pattern1Test){

  bool testFlag = true;

  vector<dnaPattern> myPatterns = dnaFindPatterns("../data/5052198779947.data", "(ACGT)TTTTGT");

  ASSERT_EQ(myPatterns.size(), 1);
  ASSERT_EQ(myPatterns.at(0).getSearchResults().size(), 4);

  EXPECT_EQ(std::get<1>(myPatterns.at(0)[2]), 12879);
  if(HasFailure())
  {
      cerr << "\nPattern1Test has failed" << endl;
      testFlag = false;
  }

  EXPECT_EQ(std::get<2>(myPatterns.at(0)[3]), 35);
  if(HasFailure())
  {
      cerr << "\nPattern1Test has failed" << endl;
      testFlag = false;
  }

}

TEST(hw6DNAPatternTests, Pattern2Test){

  bool testFlag = true;

  vector<dnaPattern> myPatterns = dnaFindPatterns("../data/8818484177433.data", "[^T]AAGCTGA");

  ASSERT_EQ(myPatterns.size(), 1);
  ASSERT_EQ(myPatterns.at(0).getSearchResults().size(), 70);

  EXPECT_EQ(std::get<1>(myPatterns.at(0)[67]), 16471);
  if(HasFailure())
  {
      cerr << "\nPattern2Test has failed" << endl;
      testFlag = false;
  }

  EXPECT_EQ(std::get<2>(myPatterns.at(0)[63]), 7);
  if(HasFailure())
  {
      cerr << "\nPattern2Test has failed" << endl;
      testFlag = false;
  }

}

TEST(hw6DNAPatternTests, Pattern3Test){

  bool testFlag = true;

  vector<dnaPattern> myPatterns = dnaFindPatterns("../data/2773426139260.data", "AC{3,6}TGA{5,7}");

  ASSERT_EQ(myPatterns.size(), 1);

  EXPECT_EQ(myPatterns.at(0).getSearchResults().size(), 0);
  if(HasFailure())
  {
      cerr << "\nPattern3Test has failed" << endl;
      testFlag = false;
  }

}

TEST(hw6DNAPatternTests, Pattern4Test){

  bool testFlag = true;

  vector<dnaPattern> myPatterns = dnaFindPatterns("../data/README.md", "ACG(GTA|TCC)");

  EXPECT_EQ(myPatterns.size(), 0);
  if(HasFailure())
  {
      cerr << "\nPattern4Test has failed" << endl;
      testFlag = false;
  }

}

TEST(hw6DNAPatternTests, Pattern5Test){

  bool testFlag = true;

  vector<dnaPattern> myPatterns = dnaFindPatterns("../dummy.data", "CGCG");

  EXPECT_EQ(myPatterns.size(), 0);
  if(HasFailure())
  {
      cerr << "\nPattern5Test has failed" << endl;
      testFlag = false;
  }

}
