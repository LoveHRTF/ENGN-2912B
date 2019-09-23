#include "ImageDenoiser.h"
#include <iostream>

using namespace std;

//constructor and destructor are provided
ImageDenoiser::ImageDenoiser(unsigned int const filterHeight, unsigned int const filterWidth)
{
  this->hFilter = filterHeight;
  this->wFilter = filterWidth;
}

ImageDenoiser::~ImageDenoiser(){}

//if the inputImage is empty cout a warning and return false`
//else resize the member variable data of outputImage to the same size as inputImage and apply median filter, if successful return true
bool ImageDenoiser::denoiseImage(Image const& inputImage, Image& outputImage){

  if(inputImage.isEmpty()){
    cout << "Warning: ImageDenosier -> Input Image Data Empty" << endl;
    return false;

  } else {
    unsigned int imageRow = inputImage.getHeight();                   // Get Image width and height
    unsigned int imageCol = inputImage.getWidth();
    unsigned int pixValInitial = 0;
    outputImage.setData(imageRow, imageCol, pixValInitial);           // Initialize and resize outputImage
    
  
    int isfilterHEven = 1; if (hFilter %2 != 0){isfilterHEven = 0;}   // Check if filter is even
    int isfilterWEven = 1; if (wFilter %2 != 0){isfilterWEven = 0;}
    

    unsigned int offsetH = 0; unsigned int offsetW = 0;                                 // Calculate Filter Offset
    if ((isfilterHEven == 1) && (isfilterWEven == 1)){
      offsetH = (hFilter - 1)/2; offsetW = (wFilter - 1)/2;
    } else{
      offsetH = hFilter/2; offsetW = wFilter/2;
    }

    int filterLength = hFilter * wFilter;                             // Create Filter Pixal Array                  
    unsigned int *filterPixArray = new unsigned int [filterLength];

    unsigned int arrayIndex = 0;
    for (unsigned int indexCol = 0; indexCol < imageCol; indexCol++){     // Loop every pixcel in image
      for (unsigned int indexRow = 0; indexRow < imageRow; indexRow++){
        arrayIndex = 0;
        // Loop every pixcel in window
        for (unsigned int indexfilterH = 0; indexfilterH < hFilter; indexfilterH ++){
          for(unsigned int indexfilterW = 0; indexfilterW < wFilter; indexfilterW ++){

            unsigned int colPixNum = indexCol - offsetW + indexfilterW;
            unsigned int rowPixNum = indexRow - offsetH + indexfilterH;
            
            if ((colPixNum < imageCol) && (rowPixNum < imageRow)){

              filterPixArray[arrayIndex] = inputImage.getPixelIntensity(rowPixNum, colPixNum);
              arrayIndex ++;
            }
          }
        }
        unsigned int arrayLength = arrayIndex - 1;

        /* Find the median value */
        // Bubble Short
        for (int indexBubble = 0; indexBubble < arrayLength; indexBubble++){
          for (int indexBubble = 0; indexBubble < arrayLength; indexBubble++){
            int pixVal = filterPixArray[indexBubble];
            int pixValNext = filterPixArray[indexBubble + 1];

            if (pixVal > pixValNext){
              filterPixArray[indexBubble + 1] = pixVal;
              filterPixArray[indexBubble] = pixValNext;
            }
          }
        }
        // Find Median Value
        unsigned int medianVal = filterPixArray[(arrayLength+1) /2];
        outputImage.setPixelIntensity(indexRow, indexCol, medianVal);
      }
    }
    delete []filterPixArray;
    return true;
  }
}
