#include <iostream>
#include <sstream>
#include "factorial.h"


using namespace std;

int main(int argc, char *argv[]){
    for(int index = 1; index < argc; index++){
        
        cout << "Process element #" << index << endl;

        // Convert input stream to double and uint
        stringstream inputvalue(argv[index]);

        // Store double double
        double x;
        inputvalue >> x;

        // Convert to int
        unsigned y;
        y = atoi(argv[index]);
        // Convert to int value double
        double x_int = static_cast<double>(y);

        // Check decimal points
        double x_decimal;
        x_decimal = x - x_int;

        // Check zero condition
        unsigned zero_pass;
        zero_pass = 2; 
        if (x == 0){   // Read In Value is zero
            //char* temp;
            //temp = 0;
            if (argv[index][1] == 0){
            // Then it is zero
            zero_pass = 1;
            } else {
            zero_pass = 0; 
            }
        }


        if (((x < 0) || (x_decimal != 0)) || (zero_pass == 0)){  // Check in input is valid (neg/float)
            cout << "Warning: Invalid input " << argv[index] << "." << endl;
            cout << " " << endl;

        } else {
            // Convert double value back to int
            unsigned input_value;
            input_value = static_cast<unsigned>(x);

            unsigned out1 = factorial(input_value);
            double out2 = factorial2(input_value);

            cout << "factorial 1: " << out1 << endl;
            cout << "factorial 2: " << out2 << endl;
            cout << " " << endl;
        }

        // TODO: 1) Using command-line parameters argc and argv, parse the input stream.
        //       2) For valid input (non-negative integers), output the factorial using
        //	     "factorial" function provided and the factorial function "factorial2" you are expected
        //       to implement (src/factorial.h and src/factorial.cpp) which can handle large inputs.
        //       3) For non valid input (negative integers, floating points, alphabetic characters etc.)
        //       output a warning message with the following format: "Warning: Invalid input <invalid input>."

        
    }
    return 0;
}
