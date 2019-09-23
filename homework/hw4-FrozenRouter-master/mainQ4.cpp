#include <iostream>
#include "Image.h"
#include "ImageDenoiser.h"

using namespace std;

int main(int argc, char *argv[])
{
  // Question 4: Image Denoising
  Image inputImage;
  inputImage.readImage("../noisyImage.pgm");
  cout << "inputImage.getHeight(): " << inputImage.getHeight() << endl;
  cout << "inputImage.getWidth(): " << inputImage.getWidth() << endl;
  cout << "inputImage.isEmpty(): " << inputImage.isEmpty() << endl;

  // print out some pixel intensities
  cout << "inputImage[120][145]: " << inputImage.getPixelIntensity(120, 145) << endl;
  cout << "inputImage[145][67]: " << inputImage.getPixelIntensity(145, 67) << endl;
  cout << "inputImage[200][14]: " << inputImage.getPixelIntensity(200, 14) << endl;
  cout << "inputImage[12][25]: " << inputImage.getPixelIntensity(12, 25) << endl;

  Image outputImage;
  ImageDenoiser imd(3,3);
  bool success = imd.denoiseImage(inputImage, outputImage);

  if(success)
  {
    // check that size of the output image matches to that of the input image
    cout << "outputImage.getHeight(): " << outputImage.getHeight() << endl;
    cout << "outputImage.getWidth(): " << outputImage.getWidth() << endl;
    cout << "outputImage.isEmpty(): " << outputImage.isEmpty() << endl;

    // print out some pixel intensities
    cout << "outputImage[120][145]: " << outputImage.getPixelIntensity(120, 145) << endl;
    cout << "outputImage[145][67]: " << outputImage.getPixelIntensity(145, 67) << endl;
    cout << "outputImage[200][14]: " << outputImage.getPixelIntensity(200, 14) << endl;
    cout << "outputImage[12][25]: " << outputImage.getPixelIntensity(12, 25) << endl;

    outputImage.writeImage("../filteredImage.pgm");
  }

  return 0;
}
