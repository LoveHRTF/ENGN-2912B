// DO NOT MODIFY

#include <iostream>
#include <vector>
#include <random>
#include "firFilter.h"

using namespace std;

void print_vec(vector<double> const &data)
{
    vector<double>::const_iterator it;
    for (it = data.begin(); it != data.end()-1; ++it)
        cout << *it << ", ";
    cout << *it;
}

int main(int argc, char* argv[])
{
    // define default input variables
    int seed = 1;
    unsigned nSamp = 100;

    // define filter coefficients

    // h1 = firls(40,[0 0.22 0.24 1],[0 0 1 1]); % MATLAB high-pass filter
    vector<double> h1 {-1.298243e-02, -1.344417e-02, -6.731882e-03,  4.616917e-03,
         1.522680e-02,  1.928825e-02,  1.353457e-02, -6.473290e-04, -1.716425e-02,
        -2.754786e-02, -2.486875e-02, -7.564225e-03,  1.865813e-02,  4.200030e-02,
         4.871157e-02,  2.870871e-02, -1.960063e-02, -8.742606e-02, -1.576804e-01,
        -2.104837e-01,  7.699227e-01, -2.104837e-01, -1.576804e-01, -8.742606e-02,
        -1.960063e-02,  2.870871e-02,  4.871157e-02,  4.200030e-02,  1.865813e-02,
        -7.564225e-03, -2.486875e-02, -2.754786e-02, -1.716425e-02, -6.473290e-04,
         1.353457e-02,  1.928825e-02,  1.522680e-02,  4.616917e-03, -6.731882e-03,
        -1.344417e-02, -1.298243e-02};

    // h2 = firls(40,[0 0.26 0.28 1],[1 1 0 0]); % MATLAB low-pass filter
    vector<double> h2 {-1.306267e-02, -6.026515e-03,  6.431116e-03,  1.604891e-02,
          1.538888e-02,  3.302295e-03, -1.327078e-02, -2.296994e-02, -1.739909e-02,
          2.345903e-03,  2.466317e-02,  3.355522e-02,  1.895021e-02, -1.488158e-02,
          -4.858100e-02, -5.632421e-02, -1.992927e-02,  5.922448e-02,  1.576357e-01,
          2.388548e-01,  2.702639e-01,  2.388548e-01,  1.576357e-01,  5.922448e-02,
          -1.992927e-02, -5.632421e-02, -4.858100e-02, -1.488158e-02,  1.895021e-02,
          3.355522e-02,  2.466317e-02,  2.345903e-03, -1.739909e-02, -2.296994e-02,
          -1.327078e-02,  3.302295e-03,  1.538888e-02,  1.604891e-02,  6.431116e-03,
          -6.026515e-03, -1.306267e-02};

    // generate array with awgn
    vector<double> x(nSamp);
    fill_vec(x,seed);

    cout << "x = [";
    print_vec(x);
    cout << "]" << endl << endl;

    // construct filter objects
    firFilter filt1(h1);
    firFilter filt2;
    filt2.SetCoef(h2);

    // print filter coefficients
    cout << "h2 = [";
    for (double coef : filt2.GetCoef())
        cout << coef << endl;
    cout << "]" << endl << endl;

    // create the output variables
    vector<double> y1, y2;

    // filter using the high-pass filter
    y1 = filt1.filter(x);
    cout << "y1 = [";
    print_vec(y1);
    cout << "]" << endl << endl;

    // second cascaded stage - 40th order low-pass filter
    y2 = filt2.filter(y1);
    cout << "y2 = [";
    print_vec(y2);
    cout << "]" << endl << endl;

    return 0;
}
