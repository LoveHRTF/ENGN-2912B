#include <iostream>
#include <string>
#include <armadillo>

using namespace std;
using namespace arma;

/******************************************************* I/O Functions *******************************************************/
arma::vec readBinaryFile(std::string filename) {                       // readBinaryFile method
  auto inputVector = arma::vec();
  inputVector.load(filename);
  return inputVector;
}

void saveBinaryFile(std::string filename, arma::vec const& signal) {   // saveBinaryFile method
  signal.save(filename,raw_binary);
}

/******************************************************* Filter Function *******************************************************/
class Filter {
  public:
    virtual arma::vec execute( arma::vec observedSignal, arma::vec noiseReferenceSignal ) = 0;
    arma::vec getFilterWeights() {            // Implement the getFilterWeights method
      return filterWeights_;                  
    }
  protected:
    arma::vec filterWeights_;
};

/******************************************************* Winner Filter *******************************************************/
class WienerFilter : public Filter { 
  public:
    WienerFilter(int M){                                              // Constructor
      filterWeights_ = zeros<vec>(M);                                 // Setup a vector with width of M
      M_ = M;
    }
    arma::vec execute( arma::vec observedSignal, arma::vec noiseReferenceSignal ) {           // Execute method

      /*                              Compute Noise Statics                             */
      int Length = filterWeights_.n_elem;
      Rxx_ = flipud(conv(noiseReferenceSignal,flipud(noiseReferenceSignal)));                 // Perform cross corrlation
      Rxx_ = Rxx_ / noiseReferenceSignal.size();                                              // Normalization
      Rxx_ = Rxx_.rows(M_ , (M_ + M_ - 1));                                                   // Take elements within range
      
      Rxx_ = toeplitz(Rxx_);     
                                                                 
      rdx_ = flipud(conv(observedSignal, flipud(noiseReferenceSignal)));                      // Perform corss corrlation
      rdx_ = rdx_ / noiseReferenceSignal.size();                                              // Normalization
      rdx_ = rdx_.rows(M_ , (M_+ M_ - 1));                                                    // Take elements within range
 
      /*                           Compute Wiener Filter Coff                           */
      w = inv(Rxx_) * rdx_;                                                                   // Matlab: w = inv(Rxx)*rdx;
      filterWeights_ = w;
      /*              Filter Reference Noise Sequence and subtract from signal          */
      y = conv(w, noiseReferenceSignal);                                                      // Matlab: y = fftfilt(w,x);

      arma::vec y_Resize = y.rows(0, 19999);
      e = observedSignal - y_Resize;

      return e;                             // Return filtered signal

    }

  private:
    arma::mat Rxx_;
    arma::vec rdx_;
    arma::mat w;
    arma::vec y;
    arma::vec e;
    int M_;
};

/******************************************************* LMSFilter Filter *******************************************************/
class LMSFilter : public Filter {
  public:
    LMSFilter(int M, int L = 500, double mu = 0.0) {                                        // Constructor
      filterWeights_ = zeros<vec>(M); 
      M_ = M;
      L_ = L;
      mu_ = mu;
    }

    arma::vec execute( arma::vec observedSignal, arma::vec noiseReferenceSignal ) {         // Execute method

      N = noiseReferenceSignal.size();

      if (mu_ == 0) {                                                                       // if mu_ is zero, estimate mu as in MATLAB implementation
        int Length = noiseReferenceSignal.size();
        rxx_ = flipud(conv(noiseReferenceSignal, flipud(noiseReferenceSignal)));
        rxx_ = rxx_ / Length;
        rxx_ = rxx_.rows(0,(L_-1));

        mu_ = 2.0 / (3.0 * M_ * rxx_(L_));
        mu_ = mu_/2.0;
        cout << "Setting mu = " << mu_ << endl;
      }

      /*                           Preallocate arrays                           */
      w_ = zeros<vec>(M_); 
      y_ = zeros<vec>(N); 
      e_ = zeros<vec>(N); 

      /*                            inerativly filter                           */
      for (int n = M_; n < N; n++ ){
        arma::vec x1 = flipud(noiseReferenceSignal);                                        // MATLAB: x1 = x(n:-1:n-M+1); 
        arma::vec x1_slide = x1.rows( n - M_ , n - 1);                                      // Flip and slide the noise

        y_(n-1) = as_scalar( w_.t() * x1_slide );                                           // MATLAB: y(n) = w.'* x1;

        e_(n-1) = observedSignal(n-1) - y_(n-1);                                             // Subtract filtered noise reference from signal

        w_ = w_ + 2.0 * mu_ * e_(n-1);                                                      // * x1;  // MATLAB: w = w + 2 * mu * e(n) * x1;
      }
      filterWeights_ = w_;
      return w_;
    }

  private:
    int L_;
    double mu_;
    arma::vec rxx_;
    arma::vec y_;
    arma::vec e_;
    arma::vec w_;
    arma::mat w_hat;
    int N;
    int M_;
};
