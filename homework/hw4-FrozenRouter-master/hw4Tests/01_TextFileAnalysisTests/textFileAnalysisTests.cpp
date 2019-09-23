#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "analyzeTextFile.h"

using namespace std;

int maxPoints = 10;

TEST(hw4TextFileAnalysisTests, validFileAnalysisTest){

  int currentPoints_TextFileAnalysis = 0;
  bool testFlag = true;
  unsigned int outputLineCount = 0;
  unsigned int outputCharacterCount = 0;
  vector<unsigned int> output;
  vector<unsigned int> expected;

  // run a valid test
  analyzeTextFile("../sampleTextFile.txt", outputLineCount, outputCharacterCount);

  output.clear();
  output.push_back(outputLineCount);
  output.push_back(outputCharacterCount);

  expected.clear();
  expected.push_back(19);
  expected.push_back(1270);

  for(unsigned i = 0; i < expected.size(); i++)
  {
    EXPECT_EQ(expected.at(i), output.at(i));
    if(HasFailure())
    {
      cerr << "\nvalidFileAnalysisTest has failed" << endl;
      testFlag = false;
      break;
    }
  }

  if(testFlag)
  {
    currentPoints_TextFileAnalysis += 5;
  }

  cout << "\nCurrent Score Valid Text File Analysis Test: " << currentPoints_TextFileAnalysis << "/" << maxPoints << endl;

}

TEST(hw4TextFileAnalysisTests, invalidFileAnalysisTest){

  int currentPoints_TextFileAnalysis = 0;
  bool testFlag = true;
  unsigned int outputLineCount = 0;
  unsigned int outputCharacterCount = 0;
  vector<unsigned int> output;
  vector<unsigned int> expected;

  // run an invalid test
  analyzeTextFile("../sample_file.txt", outputLineCount, outputCharacterCount);

  output.clear();
  output.push_back(outputLineCount);
  output.push_back(outputCharacterCount);

  expected.clear();
  expected.push_back(0);
  expected.push_back(0);

  for(unsigned i = 0; i < expected.size(); i++)
  {
    EXPECT_EQ(expected.at(i), output.at(i));
    if(HasFailure())
    {
      cerr << "\ninvalidFileAnalysisTest has failed" << endl;
      testFlag = false;
      break;
    }
  }


  if(testFlag)
  {
    currentPoints_TextFileAnalysis += 5;
  }

  cout << "\nCurrent Score Invalid Text File Analysis Test: " << currentPoints_TextFileAnalysis << "/" << maxPoints << endl;

}
