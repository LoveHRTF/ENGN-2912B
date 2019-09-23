// DO NOT MODIFY

#pragma once
#include <string>
#include <vector>

using namespace std;

class Image
{
public:

  Image();
  ~Image();

  bool readImage(string const& inputFileName);
  bool writeImage(string const& outputFileName);
  unsigned int getPixelIntensity(unsigned int const r, unsigned int const c) const;
  void setPixelIntensity(unsigned int const r, unsigned int const c, unsigned int const intensity);
  unsigned int getHeight() const;
  unsigned int getWidth() const;
  bool isEmpty() const;
  vector< vector<unsigned int> > getData() const;
  void setData(unsigned int const rowSize, unsigned int const colSize, unsigned int pixelIntensity);

private:
  vector<vector<unsigned int> > data;
  unsigned int width;
  unsigned int height;
  bool empty;
};
