// DO NOT MODIFY

#pragma once
#include "Image.h"

class ImageDenoiser
{
public:

  ImageDenoiser(unsigned int const filterHeight, unsigned int const filterWidth);
  ~ImageDenoiser();

  bool denoiseImage(Image const& inputImage, Image& outputImage);

private:
  unsigned int hFilter;
  unsigned int wFilter;
};
