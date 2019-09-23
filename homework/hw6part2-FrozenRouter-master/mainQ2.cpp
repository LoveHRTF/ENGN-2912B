#include <iostream>
#include <armadillo>
#include "anc.h"

using namespace std;
using namespace arma;

int main() {

  // collect data
  vec observedSignal = readBinaryFile("../data/observed.dat");
  vec noiseReferenceSignal = readBinaryFile("../data/noiseReference.dat");

  // set parameters
  int M = 100;
  int L = 500;
  double mu = 0.0075;

  // run Wiener Filter
  WienerFilter wF(M);
  vec errorSignal_wF = wF.execute(observedSignal, noiseReferenceSignal);
  vec w_wF = wF.getFilterWeights();
  saveBinaryFile("../results/w_wF.dat", w_wF);
  saveBinaryFile("../results/errorSignal_wF.dat", errorSignal_wF);

  // run LMS Filter
  LMSFilter lmsF(M, L, mu);
  vec errorSignal_lmsF = lmsF.execute(observedSignal, noiseReferenceSignal);
  vec w_lmsF = lmsF.getFilterWeights();
  saveBinaryFile("../results/w_lmsF.dat", w_lmsF);
  saveBinaryFile("../results/errorSignal_lmsF.dat", errorSignal_lmsF);

  return 0;

}
