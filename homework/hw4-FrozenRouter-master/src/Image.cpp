#include "Image.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Image::Image(){ this->empty = true; this->height = 0; this->width = 0; (this->data).clear(); }
Image::~Image(){}

//parse input file and store pixel intensities in private member varlable data, if read successful return true
//if input file does not exist, cout a warning and return false
bool Image::readImage(string const& inputFileName){

    ifstream imageData(inputFileName.c_str()); // Read Image Data as a C-Style String
    string imageType; string skipThis; string imageSize;

    if (!imageData){                                                           // Exit when read error occurs
      empty = 1;
      cout << "Warning: Image File Does Not Exist" << endl;
      return false;
    } else {
      empty = 0;
      getline(imageData, imageType);                                           // First read image Type, useless
      getline(imageData, imageSize);                                           // Second read image size, useful
      getline(imageData, skipThis);                                            // Image Max Value, useless, we already know that
      istringstream iss(imageSize);                                            // Use iss to read size information for calculat size
      iss >> width >> height;                                                  // Store image size to two vars
      data = vector<vector<unsigned int>>(height, vector<unsigned int>(width, 0));

      /* Image Data Read */
      int indexCol = 0; int indexRow = 0;
      while (!imageData.eof()){
        /* Assign Vals to Vector */
        unsigned int pixelVal = 0; imageData >> pixelVal;
        data.at(indexRow).at(indexCol) = pixelVal;
        /* Update Index */
        indexCol ++;
        if (indexCol == width){ indexRow ++; indexCol = 0; }
        if (indexRow >= height){ break; }
      }
      imageData.close();
      return true;
    }
}

bool Image::writeImage(string const& outputFileName)
{
  //if the member variable data is not empty, save image content to file (overwrite if neccessary), if write successful return true
  //if the member variable data is empty, cout a warning and return false
  if (this->empty){
    cout << "Warning: writeImage -> Data is Empty" << endl;
    return false;
  } else {
    /*************************************** Save ***************************************/
    ofstream outputImage;
    outputImage.open (outputFileName, std::ofstream::out | std::ofstream::trunc);
    outputImage << "P2 \n";
    outputImage << width << ' ' << height << "\n";
    outputImage << "255 \n";
    for (int indexRows = 0; indexRows < height; indexRows++){
      for (int indexCols = 0; indexCols < width; indexCols++){
        unsigned int pixVal = data.at(indexRows).at(indexCols);
        outputImage << pixVal << ' ';
      }
      if (indexRows < height - 1){
        outputImage << "\n";
      }
    }
    outputImage.close();
    cout << "Write Succeed" << endl;
    /*************************************** Done ***************************************/
    return true;
  }

}

unsigned int Image::getPixelIntensity(unsigned int const r, unsigned int const c) const
{
  //if pixel location (r,c) is out of the image boundaries return 0, else return the pixel intensity at (r,c)
  if ((height <= r) || (width <= c)){
    return 0;
  } else {
    unsigned int pixVal = data.at(r).at(c);                // get pixel intensity and return
    return pixVal;
  }
}

void Image::setPixelIntensity(unsigned int const r, unsigned int const c, unsigned int const intensity)
{
  //if pixel location (r,c) is out of the image boundaries do notthing, else set the pixel intensity at (r,c) to "intensity"
  if ((height <= r) || (width <= c)){  // Out of boundry, do nothing.
  } else {
    empty = 0;
    data.at(r).at(c) = intensity;
  }
}

void Image::setData(unsigned int const rowSize, unsigned int const colSize, unsigned int pixelIntensity)
{
  //cout << "Row: " << rowSize << " Col: " << colSize << endl;
  //clear the contents of the member variable data, resize it to [rowSize, colSize]
  //and initialize all the pixel intensities to "pixelIntensity"
  this->empty = true; this->height = rowSize; this->width = colSize; (this->data).clear();     // Clean up
  data.resize(height);
  for  (int i = 0; i < height; ++i){
    data[i].resize(width);
  }

  for (int indexRow = 0; indexRow < rowSize; indexRow ++){                         // Assign new val
    for (int indexCol = 0; indexCol < colSize; indexCol ++){
      data.at(indexRow).at(indexCol) = pixelIntensity;
    }
  }
}

unsigned int Image::getHeight() const { return this->height; }
unsigned int Image::getWidth() const { return this->width; }
bool Image::isEmpty() const { return this->empty; }
vector< vector<unsigned int> > Image::getData() const { return this->data; }
