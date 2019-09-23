#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "Image.h"
#include "ImageDenoiser.h"

using namespace std;

TEST(hw4ImageDenoisingTests, ReadTest){

  int currentPoints = 0;
  int maxPoints = 5;

  bool testFlag = true;
  vector<unsigned int> expected;
  vector<unsigned int> output;

  Image inputImage;
  inputImage.readImage("../noisyImage.pgm");

  ASSERT_EQ(inputImage.getHeight(), 252) << "readImage row size does not match..";
  ASSERT_EQ(inputImage.getWidth(), 189) << "readImage col size does not match..";

  // check pixel intensities
  output.push_back( inputImage.getPixelIntensity(120, 145) );
  output.push_back( inputImage.getPixelIntensity(145, 67) );
  output.push_back( inputImage.getPixelIntensity(200, 14) );
  output.push_back( inputImage.getPixelIntensity(12, 25) );

  expected.push_back( 136 );
  expected.push_back( 153 );
  expected.push_back( 255 );
  expected.push_back( 153 );

  for(unsigned int i = 0; i < expected.size(); i++)
  {
    EXPECT_EQ(expected.at(i), output.at(i));
    if(HasFailure())
    {
      cerr << "\nReadTest has failed" << endl;
      testFlag = false;
      break;
    }
  }

  if(testFlag)
  {
    currentPoints += 5;
  }

  cout << "\nRead Test: " << currentPoints << "/" << maxPoints << endl;

}

TEST(hw4ImageDenoisingTests, FilterTest){

  int currentPoints = 0;
  int maxPoints = 5;

  bool testFlag = true;
  vector<unsigned int> expected;
  vector<unsigned int> output;

  Image inputImage;
  inputImage.readImage("../noisyImage.pgm");

  Image outputImage;

  ImageDenoiser imd(3,3);
  bool success = imd.denoiseImage(inputImage, outputImage);

  ASSERT_EQ(success, true) << "denoiseImage method failed...";

  // check pixel intensities
  output.push_back( outputImage.getPixelIntensity(120, 145) );
  output.push_back( outputImage.getPixelIntensity(145, 67) );
  output.push_back( outputImage.getPixelIntensity(200, 14) );
  output.push_back( outputImage.getPixelIntensity(12, 25) );

  expected.push_back( 119 );
  expected.push_back( 141 );
  expected.push_back( 61 );
  expected.push_back( 154 );

  for(unsigned int i = 0; i < expected.size(); i++)
  {
    EXPECT_EQ(expected.at(i), output.at(i));
    if(HasFailure())
    {
      cerr << "\nFilterTest has failed" << endl;
      testFlag = false;
      break;
    }
  }

  if(testFlag)
  {
    currentPoints += 5;
  }

  cout << "\nFilter Test: " << currentPoints << "/" << maxPoints << endl;

}

TEST(hw4ImageDenoisingTests, WriteTest){

  int currentPoints = 0;
  int maxPoints = 5;

  bool testFlag = true;
  vector<unsigned int> expected;
  vector<unsigned int> output;

  Image inputImage;
  inputImage.readImage("../noisyImage.pgm");

  Image outputImage;

  ImageDenoiser imd(5,11);
  bool success = imd.denoiseImage(inputImage, outputImage);

  ASSERT_EQ(success, true) << "denoiseImage method failed...";

  outputImage.writeImage("../filteredImage.pgm");

  Image savedImage;
  savedImage.readImage("../filteredImage.pgm");

  // check pixel intensities at boundaries
  output.push_back( savedImage.getPixelIntensity(0, 0) );
  output.push_back( savedImage.getPixelIntensity(0, 188) );
  output.push_back( savedImage.getPixelIntensity(251, 0) );
  output.push_back( savedImage.getPixelIntensity(251, 188) );

  expected.push_back( 152 );
  expected.push_back( 148 );
  expected.push_back( 54 );
  expected.push_back( 57 );

  for(unsigned int i = 0; i < expected.size(); i++)
  {
    EXPECT_EQ(expected.at(i), output.at(i));
    if(HasFailure())
    {
      cerr << "\nWriteTest has failed" << endl;
      testFlag = false;
      break;
    }
  }

  if(testFlag)
  {
    currentPoints += 5;
  }

  cout << "\nWrite Test: " << currentPoints << "/" << maxPoints << endl;

}

TEST(hw4ImageDenoisingTests, ReadWriteTest){

  int currentPoints = 0;
  int maxPoints = 5;

  bool testFlag = true;

  Image inputImage;
  inputImage.readImage("../originalImage.pgm");

  EXPECT_EQ(inputImage.isEmpty(), true);
  if(HasFailure())
  {
    cerr << "\nReadWriteTest has failed" << endl;
    testFlag = false;
  }

  if(testFlag)
  {
    currentPoints += 5;
  }

  cout << "\nRead Write Test: " << currentPoints << "/" << maxPoints << endl;

}
