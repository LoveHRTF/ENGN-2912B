#include <random>
#include <iostream>
#include "firFilter.h"

using namespace std;

//fill vector with wgn
void fill_vec(vector<double> &vd, int const& seed) {             // Fill vector vd using the knuth_b engine with "seed"
  double radNum = 0; unsigned vectorSize = 0;
  knuth_b generator (seed);                                      // Initialize kunth_b generator using input seed
  normal_distribution<double> noise(0,1);                        // Set distribution with mean 0 and std 1
  vectorSize = vd.size();                                        // Get Target Vector Size
  for (unsigned i = 0; i < vectorSize; i++){ vd.at(i) = noise(generator);}
}

firFilter::firFilter(){}                                         // the default constructor, needs no further implementation

firFilter::firFilter(vector<double> const& referenceFilter) {    // Vector instantiation based constructor
  h = referenceFilter;                                           // Set filter coff in constructor
}

void firFilter::SetCoef(vector<double> const& referenceFilter) { // SetCoef method
  h = referenceFilter;                                           // Set filter coff in Set method
}

vector<double> firFilter::GetCoef() {                            // GetCoef() method
  return h;
}

vector<double> firFilter::filter(vector<double> const& input) { // 1) create an output vector of type double with an appropriate size that can correctly hold the filtered signal
                                                                // 2) store the filtered signal samples in the output vector and return it
  unsigned inputSize = input.size(); unsigned filterOrder = h.size();
  vector<double> output = input;

  for (unsigned outputIndexN = 0; outputIndexN < inputSize; outputIndexN ++){             // For every element in input sequence
    
    double outputElement = 0.0;
    for (unsigned filterIndexK = 0; filterIndexK <  filterOrder; filterIndexK ++){        // For every element in filter
      int diff = outputIndexN - filterIndexK;
      if (diff < 0){break;}
      outputElement += (h.at(filterIndexK) * input.at(diff));
    }

    output.at(outputIndexN) = outputElement;
  }
  return output;
}
