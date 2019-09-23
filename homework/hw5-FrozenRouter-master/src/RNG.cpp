#include <random>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include "RNG.h"

using namespace std;

void fill_vec(vector<double> &vd, int const& seed) {                                                // Fill vector vd using the knuth_b engine with "seed"
  double radNum = 0; unsigned vectorSize = 0;
  knuth_b generator (seed);                                                                         // Initialize kunth_b generator using input seed
  normal_distribution<double> distribution(-10,5);                                                  // Set distribution with mean -10 and std 5
  vectorSize = vd.size();                                                                           // Get Target Vector Size
  for (unsigned i = 0; i < vectorSize; i++){ vd.at(i) = distribution(generator);}
}


pair<double, double> convert_to_fixed(vector<double> const& vd, vector<int32_t>& vi, unsigned const& nBits){ //convert vector of floating-point format to fixed-point format
  /* Find the minimum and maximum values in vd, store them in a pair container and return it */
  vector<double> vdTmp = vd;                                                                                 // Create Temp Vector for proessing
  unsigned vectorSize = vdTmp.size();                                                                        // Bubble Short
  for (int i = 0; i < vectorSize - 1; i++){
    for (int i = 0; i < vectorSize - 1; i++){
      double vecVal = vdTmp.at(i); double vecValNext = vdTmp.at(i+1);
      if (vecVal > vecValNext){vdTmp.at(i+1) = vecVal; vdTmp.at(i) = vecValNext;}
    }
  }
  pair<double, double> minmax;
  minmax = make_pair(vdTmp.at(0), vdTmp.at(vectorSize - 1));                                                 // Store Min/Max in a container

  /* convert each floating-point number in vd to a fixed-point format using a precision of nBits and store in vi */
  int Max = 0; int Min = 0;                                                                                  // Calculate the new Min/Max
  Max = pow(2, nBits) / 2 - 1; Min = pow(2, nBits) / 2 * -1;
  
  double rangeFixed = (Max - Min); double rangeFloat = (vdTmp.at(vectorSize - 1) - vdTmp.at(0));             // Find the range and range ratio
  double rangeRatio = rangeFixed/rangeFloat;
  
  vector<double> viTmp = vdTmp;                                                                              // Linear Mapping
  unsigned int viSize = viTmp.size();
  for (unsigned int viIndex = 0; viIndex < viSize; viIndex++) {
    if (viIndex == 0){ viTmp.at(viIndex) = Min;} 
    else if (viIndex == viSize - 1) { viTmp.at(viIndex) = Max;}
    else {
      viTmp.at(viIndex) = viTmp.at(viIndex - 1) + (vdTmp.at(viIndex) - vdTmp.at(viIndex - 1)) * rangeRatio;
    }
  }

  vi.resize(viSize);                                                                                         // Static cast from float to cast and Output
  for (unsigned int viIndex = 0; viIndex < viSize; viIndex++) {
    vi.at(viIndex) = static_cast<int>(viTmp.at(viIndex));
  }

  vector<double> viReOrder = vdTmp;                                                                          // Adjust Order to Original
  for (unsigned int viIndex = 0; viIndex < viSize; viIndex++) {
    for (unsigned int vdIndex = 0; vdIndex < viSize; vdIndex++) {
      if (vdTmp.at(viIndex) == vd.at(vdIndex)) { viReOrder.at(vdIndex) = vi.at(viIndex);}
    }
  }

  for (unsigned int viIndex = 0; viIndex < viSize; viIndex++) {                                              // Assign Value to Output
    vi.at(viIndex) = viReOrder.at(viIndex);
  }

  return minmax;
}

//convert fixed-point format back to floating-point format
void convert_to_float(vector<int32_t> const& vi, vector<double>& vd, unsigned const& nBits, pair<double, double> const& minmax){
  vector<int32_t> viTmp = vi;                                                                 // Create Temp Vector for proessing
  unsigned vectorSize = viTmp.size();                                                         // Bubble Short for temp var vi
  for (int i = 0; i < vectorSize - 1; i++){
    for (int i = 0; i < vectorSize - 1; i++){
      double vecVal = viTmp.at(i); double vecValNext = viTmp.at(i+1);
      if (vecVal > vecValNext){viTmp.at(i+1) = vecVal; viTmp.at(i) = vecValNext;}
    }
  }

  double floatMin = minmax.first; double floatMax = minmax.second;                           // Find float range
  double floatRange = floatMax - floatMin;                                                   // Find fixed range
  
  int Max = 0; int Min = -1;
  Max = pow(2, nBits) / 2 - 1; Min = pow(2, nBits) / 2 * -1;
  double rangeFixed = (Max - Min);                                                           // Find the ratio
  double rangeRatio = floatRange/rangeFixed;                                                 // Assign Val

  unsigned int vdSize = vi.size();
  vd.resize(vdSize);
  for (unsigned int vdIndex = 0; vdIndex < vdSize; vdIndex++) {                              // Assign in the order of small to large
    if (vdIndex == 0){ vd.at(vdIndex) = floatMin;} 
    else if (vdIndex == vdSize - 1) {vd.at(vdIndex) = floatMax;} 
    else {
      vd.at(vdIndex) = vd.at(vdIndex - 1) + (viTmp.at(vdIndex) - viTmp.at(vdIndex - 1)) * rangeRatio;
    }
  }

  vector<double> vdReOrder = vd;                                                             // Adjust Order to Original
  for (unsigned int vdIndex = 0; vdIndex < vdSize; vdIndex++) {
    for (unsigned int viIndex = 0; viIndex < vdSize; viIndex++) {
      if (viTmp.at(vdIndex) == vi.at(viIndex)) { vdReOrder.at(viIndex) = vd.at(vdIndex); }
    }
  }
  for (unsigned int i = 0; i < vdSize; i++) { vd.at(i) = vdReOrder.at(i); }                  // Assign Value to Output
}


void save_vec(vector<int32_t> const& vi, string const& filename){                            // Save a fixed-point vector to a file
  unsigned int viSize = vi.size();
  ofstream outputFile; outputFile.open (filename, ios::out | ios::binary);                   // Open the output file
  for (unsigned int viIndex = 0; viIndex < viSize; viIndex++){
    int32_t num = vi.at(viIndex);
    outputFile.write((char *) &num, sizeof(int32_t));
  }
  outputFile.close();
}
