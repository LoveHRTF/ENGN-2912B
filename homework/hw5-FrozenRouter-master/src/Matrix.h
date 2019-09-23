#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <complex>
#include <typeinfo>
#include <cmath>

#ifndef Matrix_h
#define Matrix_h
// #ifdef DEBUG
// #endif


using namespace std;

template<typename T, unsigned int rowSize = 2, unsigned int columnSize = 2>
class Matrix{
private:

  T** data_;
  unsigned int rowSize_;
  unsigned int columnSize_;

public:
/*********************************************** Get Functions ***********************************************/
  unsigned int getRowSize() const {                        // Return row size
    return rowSize_;
  }

  unsigned int getColumnSize() const {                     // Return column size
    return columnSize_; 
  }
/*********************************************** Con/Destructors ***********************************************/
  Matrix(){                                                              // Default Constructor
    rowSize_ = rowSize; columnSize_ = columnSize;
    data_ = new T* [rowSize_];                                           // DMA Pointer Array
    for (unsigned int i = 0; i < rowSize_; i++){                         // DMA Each Array Element
        data_[i] = new T[columnSize_];
    }
    for (unsigned int i = 0; i < rowSize_; i++){                         // Assign Value for each element in array
        for (unsigned int j = 0; j < columnSize_; j++){
            data_[i][j] = static_cast<T>(0);
        }
    }
  }

  Matrix(Matrix const& referenceMatrix){                                 // Copy Constructor
  
    rowSize_ = rowSize; columnSize_ = columnSize;
    data_ = new T* [rowSize_];
    for (unsigned int i = 0; i < rowSize_; i++){data_[i] = new T[columnSize_];}
    for (unsigned int i = 0; i < rowSize_; i++){                         // Assign Value for each element in array
        for (unsigned int j = 0; j < columnSize_; j++){
            data_[i][j] = referenceMatrix.data_[i][j];
        }
    }
  }

  Matrix(T const * const& data) {                                        // Implement the data array constructor
    rowSize_ = rowSize; columnSize_ = columnSize;
    data_ = new T* [rowSize_];
    for (unsigned int i = 0; i < rowSize_; i++){data_[i] = new T[columnSize_];}
    unsigned int k = 0;
    for (unsigned int i = 0; i < rowSize_; i++){                         // Assign Value for each element in array
        for (unsigned int j = 0; j < columnSize_; j++){
            data_[i][j] = data[k];
            k++;
        }
    }
  }

  Matrix(vector<T> const& data) {                                        // Implement the data vector constructor
    rowSize_ = rowSize; columnSize_ = columnSize;
    data_ = new T* [rowSize_]; 
    for (unsigned int i = 0; i < rowSize_; i++){data_[i] = new T[columnSize_];}
    unsigned int k = 0;
    for (unsigned int i = 0; i < rowSize_; i++){                        // Assign Value for each element in array
        for (unsigned int j = 0; j < columnSize_; j++){
            data_[i][j] = data.at[k];
            k++;
        }
    }
  }

  ~Matrix(){                                                            // Remove Memorys on Heap (Dynamically Allocated Memory)
    for (unsigned int i = 0; i < columnSize_; i++){ delete [] data_[i]; }
    delete [] data_;
  }
/*********************************************** Operator Overloads ***********************************************/
  T& operator()(unsigned const row, unsigned const column){                                     // Overload the parenthesis operator
    return data_[row][column];
  }

  friend ostream& operator<< (ostream& out, Matrix& referenceMatrix) {                          // Overload the << operator : "introvert" friend
    if (typeid(referenceMatrix.data_[0][0]) == typeid(complex<double>)){                        // Check if the datatype was double
      for (unsigned int indexRow = 0; indexRow < referenceMatrix.rowSize_; indexRow++){         // Print complex<double> datatype
        out << "|";
        for (unsigned int indexCol = 0; indexCol < referenceMatrix.columnSize_; indexCol++){

         double realPart = real(referenceMatrix.data_[indexRow][indexCol]); double imagPart = imag(referenceMatrix.data_[indexRow][indexCol]);
         double realABS = abs(realPart); double imagABS = abs(imagPart);

          out.width(1); out.precision(4); out << scientific; out << right;

          if (realPart >= 0) { out << "  " << realABS; } else { out << " -" << realABS; }
          if (imagPart >= 0) { out << " + " << imagABS << 'i' << ' ';} else { out << " - " << imagABS << "i" << ' ';}
        }
        out << "|" <<  endl;
      }

    } else if (typeid(referenceMatrix.data_[0][0]) == typeid(int)) {                           // Print int datatype
      for (unsigned int indexRow = 0; indexRow < referenceMatrix.rowSize_; indexRow++){
        out << "| ";
        for (unsigned int indexCol = 0; indexCol < referenceMatrix.columnSize_; indexCol++){
          out.width(4); out.precision(4); out << scientific; out << right;
          out << referenceMatrix.data_[indexRow][indexCol] << " ";
        }
        out << "|" <<  endl;
      }
    } else {                                                                                   // Print all other datatypes
      for (unsigned int indexRow = 0; indexRow < referenceMatrix.rowSize_; indexRow++){
        out << "|";
        for (unsigned int indexCol = 0; indexCol < referenceMatrix.columnSize_; indexCol++){
          float val = real(referenceMatrix.data_[indexRow][indexCol]);
          float valABS = abs(val);
          out.width(1); out.precision(3); out << scientific; out << right;
          if (val >= 0){cout << "  " << valABS;} else {cout << " -" << valABS;}
        }
        out << " |" <<  endl;
      }
    }
    return out;
  }

  Matrix& operator= (Matrix const& referenceMatrix){                                            // Overload the assignment operator
    for (unsigned int i = 0; i < rowSize_; i++){                                                // Assign Value for each element in array
      for (unsigned int j = 0; j < columnSize_; j++){
          this-> data_[i][j] = referenceMatrix.data_[i][j];
      }
    }
    return *this;
  }

  Matrix operator-() {                                                                          // Overload the unary subtraction operator
    for (unsigned int i = 0; i < rowSize_; i++){                                                // Assign Value for each element in array
      for (unsigned int j = 0; j < columnSize_; j++){
          this-> data_[i][j] = -(this-> data_[i][j]);
      }
    }
    return *this;
  }

  Matrix operator+(Matrix const& referenceMatrix) {                                             // Overload the binary addition operator
  Matrix Mat = Matrix();
    for (unsigned int i = 0; i < rowSize_; i++){                                                // Assign Value for each element in array
      for (unsigned int j = 0; j < columnSize_; j++){
          Mat.data_[i][j] = (this-> data_[i][j]) + referenceMatrix.data_[i][j];
      }
    }
    return Mat;
  }

  Matrix operator-(Matrix const& referenceMatrix) {                                             // Overload the binary subtraction operator
  Matrix Mat = Matrix();
    for (unsigned int i = 0; i < rowSize_; i++){                                                // Assign Value for each element in array
      for (unsigned int j = 0; j < columnSize_; j++){
          Mat.data_[i][j] = (this-> data_[i][j]) - referenceMatrix.data_[i][j];
      }
    }
    return Mat;
  }

  template <unsigned rowSize2, unsigned columnSize2>                                             // Overload the binary multiplication operator
  Matrix<T, rowSize, columnSize2> operator*(Matrix<T, rowSize2, columnSize2>& referenceMatrix) { // rowSize from original matrix, columnSize from referenceMatrix
  Matrix Mat = Matrix();
    for (unsigned rowIndex = 0; rowIndex < columnSize2; rowIndex ++){                            // For every element in result matrix
      for (unsigned columIndex = 0; columIndex < this-> rowSize_; columIndex ++){
        T result = 0;
        for (unsigned multIndex = 0; multIndex < this-> rowSize_; multIndex ++){
          result = result + this->data_[rowIndex][multIndex] * referenceMatrix.data_[multIndex][columIndex];
        }
        Mat.data_[rowIndex][columIndex] = result;
      }
    }
    return Mat;
  }

  Matrix operator*(T const& scalar) {                                                            // Overload the scalar multiplication operator (matrix * scalar)
  Matrix Mat = Matrix();
    for (unsigned int i = 0; i < rowSize_; i++){                                                 // Assign Value for each element in array
      for (unsigned int j = 0; j < columnSize_; j++){
         Mat.data_[i][j] = (this-> data_[i][j]) * scalar;
      }
    }
    return Mat;
  }

  friend Matrix operator*(T const& scalar, Matrix const& referenceMatrix) {                      // Overload the scalar multiplication operator (scalar * matrix) : "introvert" friend
  Matrix Mat = Matrix();
  Mat.columnSize_ = referenceMatrix.getColumnSize();
  Mat.rowSize_ = referenceMatrix.getRowSize();

    for (unsigned int i = 0; i < Mat.rowSize_; i++){                                             // Assign Value for each element in array
      for (unsigned int j = 0; j < Mat.columnSize_; j++){
          Mat.data_[i][j] = scalar * referenceMatrix.data_[i][j];
      }
    }
    return Mat;
  }
// Above were finished
/*********************************************** Operation Functions ***********************************************/
// Under Construction...
  T Det() {                                                                                                  // Implement the determinant method
    T det_A = 0;
    if (rowSize_ != columnSize_){
      throw std::invalid_argument("length_error");
      } else {
        if (rowSize_ == 1){                                                                                  // Matrix of 1x1, det = matrix
          det_A = data_[0][0];
         } else if (rowSize_ == 2){                                                                          // Matrix of 2x2, original method
           det_A = (data_[0][0] * data_[1][1]) - (data_[0][1] * data_[1][0]);
       } else {                                                                                              // Matrix of 3x3 or larger, need recursive, working on this
          for(int colIndex = 0; colIndex < rowSize_; colIndex ++){                                           // For every element in first row
                                                                                                             // Calculate Cofactor
            Matrix subMatrix; subMatrix.rowSize_ = rowSize_ - 1; subMatrix.columnSize_ = columnSize_ - 1;
            unsigned int subRowIndex = 0; unsigned int subColIndex = 0;
            for (unsigned int colIndexOut = 0; colIndexOut < rowSize_; colIndexOut ++){                      // Loop Every Element in Large Mat
              for (unsigned int rowIndexOut = 0; rowIndexOut < columnSize_; rowIndexOut ++){
                if ((colIndexOut != colIndex) && (rowIndexOut != 0)){                                        // Assign Val to sub Matrix 
                  subMatrix.data_[subRowIndex][subColIndex] = data_[rowIndexOut][colIndexOut];
                  subRowIndex ++;
                  if (subRowIndex == subMatrix.rowSize_) {subRowIndex = 0; subColIndex++;}
                }
              }
           }
            det_A += pow(-1,colIndex) * data_[0][colIndex] * subMatrix.Det();                                // Use Recursive to solve problem
          }
        }
      }
    return det_A;
  }

  Matrix Inv() {                                                                                             // Implement the inverse method
     Matrix temp_Inv;
     Matrix adjMat;
    if (Det() == static_cast<T>(0)){
      throw std::invalid_argument("range_error");
    } else {
      if (rowSize_ == 1){
        adjMat.data_[0][0] = 0;
      } else if (rowSize_ == 2){
        temp_Inv.data_[0][0] = (data_[1][1] / Det());  temp_Inv.data_[0][1] = (-data_[0][1] / Det());
        temp_Inv.data_[1][0] = (-data_[1][0] / Det()); temp_Inv.data_[1][1] = (data_[0][0] / Det());
      } else {

        adjMat.rowSize_ = rowSize_; adjMat.columnSize_ = columnSize_;
        temp_Inv.rowSize_ = rowSize_; temp_Inv.columnSize_ = columnSize_;

        for (int rowIndex = 0; rowIndex < columnSize_; rowIndex ++){                                             // For every element in first row
          for (int colIndex = 0; colIndex < rowSize_; colIndex ++){
              /* Calculate Cofactor */
              Matrix subMatrix; subMatrix.rowSize_ = rowSize_ - 1; subMatrix.columnSize_ = columnSize_ - 1;
              unsigned int subRowIndex = 0; unsigned int subColIndex = 0;

              for (unsigned int rowIndexOut = 0; rowIndexOut < columnSize_; rowIndexOut ++){                      // Loop Every Element in Large Mat
                for (unsigned int colIndexOut = 0; colIndexOut < rowSize_; colIndexOut ++){
                  if ((colIndexOut != colIndex) && (rowIndexOut != rowIndex)){                                    // Assign Val to sub Matrix 
                    subMatrix.data_[subColIndex][subRowIndex] = data_[rowIndexOut][colIndexOut];
                    subRowIndex ++;
                    if (subRowIndex == subMatrix.rowSize_) {subRowIndex = 0; subColIndex++;}
                  }
                }
             }

            /* Calculate Sign */
            T sign = -1.0;
            if ((rowIndex + colIndex)%2 == 0){sign = 1.0;}
            /* Calculate Adj */
            adjMat.data_[rowIndex][colIndex] = sign * subMatrix.Det();
            
            }
          }
          
          for(int colIndex = 0; colIndex < rowSize_; colIndex ++){                                            // For every element in first row
            for(int rowIndex = 0; rowIndex < columnSize_; rowIndex ++){
              T detVal = Det();
              temp_Inv.data_[rowIndex][colIndex] = adjMat.data_[rowIndex][colIndex] / detVal;
            }
          } 




      }
    }
    return temp_Inv;
  }

  void Print() { // TODO: implement the Print() method
    cout << *this << endl;
  }


};
#endif // Matrix_hpp