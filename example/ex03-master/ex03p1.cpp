#include <cstdlib>      // provides atof()
#include <iostream>     // provides cout, cin, precision, fixed, scientific
//#include <iomanip>      // provides setprecision, setwidth
#include <string>       // provides 'string()'
#include <math.h>       // provides pow, sqrt, log, log2, log10, logb, exp, ldexp, and many others

/*
 * This program experiments with various logarithm and exponential functions
 *
 * Execute the program using numerical command line arguments.
 * What happens when we enter a non-numerical character or string of characters?
 * How much precision do you need to show numerical precision errors?
 */

using namespace std;

// We can accept command line parameters into main() when the program is run
int main(int nargc, char* argv[])
{

    // this modifies the standard output format
    cout.precision(8);
    //cout << setprecision(8); // alternative (requires <iomanip>)

    for (int n=1; n<nargc; n++){

        float v = atof(argv[n]);

        // echo input value
        cout << endl << string(40,'*') << endl << "v = " << v << endl;

        // compute ln(v) - natural log
        cout << "ln(v)       = " << log(v) << endl;

        // compute log10(v)
        cout << "log10(v)    = " << log10(v) << endl;

        // compute log2(v)
        cout << "log2(v)     = " << log2(v) << endl;

        // compute ln(v)/ln(2)
        cout << "ln(v)/ln(2) = " << (log(v)/log(2)) << endl;

        // compute double log2(|v|)
        cout << "log2(|v|)   = " << logb(v) << endl;

        // compute integer floor(log2(|v|))
        cout << "ilog2(|v|)  = " << ilogb(v) << endl;

        // compute 2^vlog
        cout << "2^v         = " << ldexp(1.0,v) << endl;
    }

    return 0;
}
