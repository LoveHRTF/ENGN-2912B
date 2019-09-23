// TODO: Implement the Matrix2x2 class methods
#include "Matrix2x2.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stdexcept>

using namespace std;
/*********************************************** Con/Destructors ***********************************************/
Matrix2x2::Matrix2x2(){                                                                   // Default Constructor
    // DMA Pointer Array for size of 2
    Mat = new double*[2];
    // DMA Each Array Element for size of 2
    for (int i = 0; i < 2; i++){
        Mat[i] = new double[2];
    }
    // Assign Value for each element in array
    for (int i = 0; i <2; i++){
        for (int j = 0; j <2; j++){
            Mat[i][j] = 0;
        }
    }
}


Matrix2x2::Matrix2x2(double Val_a1, double Val_a2, double Val_a3, double Val_a4){         // Input Constructor (Individual Entry)
    // DMA Pointer Array for size of 2
    Mat = new double*[2];
    // DMA Each Array Element for size of 2
    for (int i = 0; i < 2; i++){
        Mat[i] = new double[2];
    }
    // Assign Value for each element in array
    for (int i = 0; i <2; i++){
        for (int j = 0; j <2; j++){
            Mat[i][j] = 0;
        }
    }
    Mat[0][0] = Val_a1;Mat[0][1] = Val_a2;
    Mat[1][0] = Val_a3;Mat[1][1] = Val_a4;
}

Matrix2x2::Matrix2x2(double Array[]){                                                     // Input Constructor (Array)
    // DMA Pointer Array for size of 2
    Mat = new double*[2];
    // DMA Each Array Element for size of 2
    for (int i = 0; i < 2; i++){
        Mat[i] = new double[2];
    }
    // Assign Value for each element in array
    for (int i = 0; i <2; i++){
        for (int j = 0; j <2; j++){
            Mat[i][j] = 0;
        }
    }
    Mat[0][0] = Array[0]; Mat[0][1] = Array[1];
    Mat[1][0] = Array[2]; Mat[1][1] = Array[3];
}

Matrix2x2::Matrix2x2(const Matrix2x2& Matrix){                                            // Copy Constructor
    // DMA Pointer Array for size of 2
    Mat = new double*[2];
    // DMA Each Array Element for size of 2
    for (int i = 0; i < 2; i++){
        Mat[i] = new double[2];
    }
    // Assign Value for each element in array
    for (int i = 0; i <2; i++){
        for (int j = 0; j <2; j++){
            Mat[i][j] = 0;
        }
    }
    Mat[0][0] = Matrix.geta1(); Mat[0][1] = Matrix.geta2();
    Mat[1][0] = Matrix.geta3(); Mat[1][1] = Matrix.geta4();
}

Matrix2x2::~Matrix2x2(){                                                                  // Destructor
    // Remove Memorys on Heap (Dynamically Allocated Memory)
   for (int i = 0; i < 2; i++){
       delete [] Mat[i];
   }
   delete [] Mat;
}
/*********************************************** Get Functions ***********************************************/
double Matrix2x2::geta1() const {                                // Accessor Methods
    return Mat[0][0];
}
double Matrix2x2::geta2() const {
    return Mat[0][1];
}
double Matrix2x2::geta3() const {
    return Mat[1][0];
}
double Matrix2x2::geta4() const {
    return Mat[1][1];
}
/*********************************************** Set Functions ***********************************************/
void Matrix2x2::seta1(double val1){                              // Set Methods
    Mat[0][0] = val1;
}
void Matrix2x2::seta2(double val2){
    Mat[0][1] = val2;
}
void Matrix2x2::seta3(double val3){
    Mat[1][0] = val3;
}
void Matrix2x2::seta4(double val4){
    Mat[1][1] = val4;
}
/*********************************************** Operation Functions ***********************************************/
void Matrix2x2::Print(){                                       // Printer with 4 significant digits
    cout << *this << endl;
}
double Matrix2x2::Det(){                                       // Return Determinant
    double det_A;
    det_A = (geta1() * geta4()) - (geta2() * geta3());
    return det_A;
}
Matrix2x2 Matrix2x2::Inv(){                                    // Return Inverse if exists, Otherwise throw exception error
          Matrix2x2 temp_Inv;
          double temp_Det;
          temp_Det = Det();
          if (temp_Det == 0){
              throw std::invalid_argument("ERROR: Determinant Does Not Exist");
          }
          temp_Inv.seta1(geta4() * (1/temp_Det));
          temp_Inv.seta2(-geta2() * (1/temp_Det));
          temp_Inv.seta3(-geta3() * (1/temp_Det));
          temp_Inv.seta4(geta1() * (1/temp_Det));
      return temp_Inv;
  }
/*********************************************** Operator Overloads ***********************************************/

Matrix2x2& Matrix2x2::operator = (const Matrix2x2& Matrix){  // Assignment Operator Overload
    seta1(Matrix.geta1());
    seta2(Matrix.geta2());
    seta3(Matrix.geta3());
    seta4(Matrix.geta4());
    return *this;
}

Matrix2x2& Matrix2x2::operator - (){                         // Unary Subtraction Operator Overload (Reverse Value)
    seta1(- (this-> geta1()));
    seta2(- (this-> geta2()));
    seta3(- (this-> geta3()));
    seta4(- (this-> geta4()));
    return *this;
}

Matrix2x2& Matrix2x2::operator + (const Matrix2x2& Matrix){  // Binary Addition Operator Overload (Add)
    seta1(this-> geta1() + Matrix.geta1());
    seta2(this-> geta2() + Matrix.geta2());
    seta3(this-> geta3() + Matrix.geta3());
    seta4(this-> geta4() + Matrix.geta4());
    return *this;
}
Matrix2x2& Matrix2x2::operator - (const Matrix2x2& Matrix){  // Binary Subtraction Operator Overload (Subtract)
    seta1(this-> geta1() - Matrix.geta1());
    seta2(this-> geta2() - Matrix.geta2());
    seta3(this-> geta3() - Matrix.geta3());
    seta4(this-> geta4() - Matrix.geta4());
    return *this;
}
Matrix2x2& Matrix2x2::operator * (const Matrix2x2& Matrix){  // Binary Multiplication Operator Overload
    seta1((this-> geta1()) * Matrix.geta1() + (this-> geta2()) * Matrix.geta3()); seta2((this-> geta1()) * Matrix.geta2() + (this-> geta2()) * Matrix.geta4());
    seta3((this-> geta3()) * Matrix.geta1() + (this-> geta4()) * Matrix.geta3()); seta4((this-> geta3()) * Matrix.geta2() + (this-> geta4()) * Matrix.geta4());
    return *this;
}

Matrix2x2& Matrix2x2::operator * (double Val){               // Double Precision Multiplication helper function
    seta1(this-> geta1() * Val);
    seta2(this-> geta2() * Val);
    seta3(this-> geta3() * Val);
    seta4(this-> geta4() * Val);
    return *this;
}

ostream& operator<<(ostream& os, const Matrix2x2& Matrix){  // ostream operator overload
    os.precision(3);
    string positive_1 = "|  ";string negative_1 = "| ";
    string positive_2 = "  " ;string negative_2 = " ";
    string positive_3 = "|  ";string negative_3 = "| ";
    string positive_4 = "  " ;string negative_4 = " ";

    string UpLeft; string UpRight;
    string DnLeft; string DnRight;

    if(Matrix.geta1() >= 0){
        UpLeft = positive_1;
    }else{
        UpLeft = negative_1;
    }
    if(Matrix.geta2() >= 0){
        UpRight = positive_2;
    }else{
        UpRight = negative_2;
    }
    if(Matrix.geta3() >= 0){
        DnLeft = positive_3;
    }else{
        DnLeft = negative_3;
    }
    if(Matrix.geta4() >= 0){
        DnRight = positive_4;
    }else{
        DnRight = negative_4;
    }

    os << UpLeft<< (Matrix.geta1()) << UpRight << (Matrix.geta2()) << " |" << '\n' << std::scientific;
    os << DnLeft << (Matrix.geta3()) << DnRight << (Matrix.geta4()) << " |" << '\n' << std::scientific;
    return os;
}
