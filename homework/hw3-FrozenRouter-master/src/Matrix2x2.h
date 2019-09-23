#ifndef Matrix2x2_h
#define Matrix2x2_h
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;
// TODO: Declare the Matrix2x
// TODO: Implement the Matrix2x2 class methods 
class Matrix2x2 {

    private:
        double** Mat;                                                          // double Pointer
    public:
    /******************************************* Con/Destructors ***********************************************/
        Matrix2x2(void);                                                       // Default Constructors
        Matrix2x2(const double Val_a1, double Val_a2, double Val_a3, double Val_a4); // Input Constructor (Element)
        Matrix2x2(double Array[]);                                             // Input Construcotr (Array)
        Matrix2x2(const Matrix2x2& Matrix);                                    // Copy Constructor
        ~Matrix2x2();                                                          // Destructor
    /******************************************* Get/Set Functions *********************************************/
        double geta1() const;                                                  // Accessors
        double geta2() const;     
        double geta3() const; 
        double geta4() const; 
        void seta1(double val1);                                                // Set Functions
        void seta2(double val2);
        void seta3(double val3);
        void seta4(double val4);
    /*************************************** Operation Functions ********************************************/
        void Print();                                                          // Printer with 4 significant digits
        double Det();                                                          // Return Determinant
        Matrix2x2 Inv();                                                       // Return Inverse if exists, Otherwise throw exception error
    /*************************************** Operator Overloads *********************************************/
        Matrix2x2& operator=(const Matrix2x2& Matrix);                         // Assignment Operator Overload
        Matrix2x2& operator-(const Matrix2x2& Matrix);                         // Binary Subtraction Operator Overload
        Matrix2x2& operator+(const Matrix2x2& Matrix);                         // Binary Addition Operator Overload (Add)
        Matrix2x2& operator-();                                                // Unary Subtraction Operator Overload (Reverse Value)
        Matrix2x2& operator*(const Matrix2x2& Matrix);                         // Binary Multiplication Operator Overload
        Matrix2x2& operator*(double Val);                                      // Double Precision Multiplication helper function
        friend ostream& operator<<(ostream& os, const Matrix2x2& Matrix);      // Ostream Operator Overload
};
#endif /* Matrix2x2_hpp */
