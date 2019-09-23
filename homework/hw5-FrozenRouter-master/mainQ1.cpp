// DO NOT MODIFY

//#define DEBUG

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <complex>
#include <cmath>
#include "Matrix.h"

using namespace std;

template<typename T, unsigned int M = 2, unsigned int N = 2>
void test1(const T* data)
{
	// create separator string
	string eq(60, '=');
	string sep(60, '=');
	sep = '\n' + eq + '\n';

	cout << eq + '\n' << "default constuctor" << sep << endl;
	Matrix<T, M, N> A;
	cout << "A() =>" << endl;
	A.Print();

	cout << sep << "copy constructor" << sep << endl;
	Matrix<T, M, N> B = A;
	cout << "B = A =>" << endl;
	B.Print();

	cout << sep << "assignment constructor" << sep << endl;
	Matrix<T, M, N> C(data);
	cout << "C(data) =>" << endl;
	C.Print();

	cout << sep << "indexing operator" << sep << endl;
	C(1, 0) = static_cast<T>(1.0);
	cout << "C(1,0) => " << C(1, 0) << endl;
	C.Print();

	cout << sep << "determinant method" << sep << endl;
	T d;
	cout << "d = C.Det() => ";
	try {
		d = C.Det();
		cout << d << endl;
	}
	catch (length_error) {
		d = static_cast<T>(NAN);
		cout << "Exception! Cannot take determinant of a non-square matrix" << endl;
	}

	cout << sep << "inverse method" << sep << endl;
	Matrix<T, M, N> E = C;
	cout << "E = C.Inv() =>" << endl;
	try {
		E = C.Inv();
		E.Print();
	}
	catch (length_error) {
		cout << "Exception! Cannot take inverse of a non-square matrix" << endl;
	}
	catch (range_error) {
		cout << "Exception! Cannot take inverse of a singular matrix" << endl;
	}

	cout << sep << "Matrix assignment (operator=)" << sep << endl;
	Matrix<T, M, N> F;
	F = E;
	cout << "F = E =>" << endl;
	F.Print();

	cout << sep << "overloaded unary subtraction (operator-)" << sep << endl;
	Matrix<T, M, N> G;
	G = -F;
	cout << "G = -F =>" << endl;
	G.Print();

	cout << sep << "overloaded binary addition/subtraction (operator+/-)" << sep << endl;
	cout << "C =>" << endl;
	C.Print();
	cout << "F =>" << endl;
	F.Print();

	Matrix<T, M, N> H1, H2;
	H1 = C + F;
	cout << "H1 = C + F =>" << endl;
	H1.Print();

	H2 = C - F;
	cout << "H2 = C - F =>" << endl;
	H2.Print();

	cout << sep << "scalar multiplication method" << sep << endl;
	Matrix<T, M, N> I = H2 * (T) 3.14159265;
	cout << "I = H2 * PI =>" << endl;
	I.Print();

	I = (T) 3.14159265 * H2;
	cout << "I = PI * H2 =>" << endl;
	I.Print();

	cout << sep << "Matrix multiplication method" << sep << endl;
	cout << "H1 =>" << endl;
	H1.Print();
	cout << "H2 =>" << endl;
	H2.Print();

	cout << "J = H1 * H2 =>" << endl;
	Matrix<T, M, N> J;
	try {
		J = H1 * H2;
		J.Print();
	}
	catch (length_error) {
		J = H1;
		cout << "Exception! Cannot multiply matrices with inner dimension mismatch" << endl;
	}

	cout << sep << "ostream (operator<<)" << sep << endl;
	cout << "cout << J << endl;" << endl;
	cout << J;

}

int main(int argc, char* argv[]) {

	// Test your templated Matrix class implementation by entering a test case on the command line from the set {1,2,3,4,5}
	unsigned testcase;
	if (argc > 1) {
		testcase = atof(argv[1]);
	}
	else {
		cin >> testcase;
	}

	switch (testcase) {
		case 1:
		{
			const float dArr[4] = { 1.0, 2.0, 3.0, 4.0 };
			test1<float>(dArr);
			break;
		}
		case 2:
		{
			const int iArr[4] = { 1, -2, 3, -4 };
			test1<int>(iArr);
			break;
		}
		case 3:
		{
			const complex<double> cArr[4] = { { sqrt(2),-sqrt(2) },{ 0,2 },{ 3,0 },{ 4,4 } };
			test1<complex<double>>(cArr);
			break;
		}
		case 4:
		{
			double dArr[16] = { 3,7,4,2,0,3,4,5,1,10,8,4,8,0,8,6 };
			test1<double, 4, 4>(dArr);
			break;
		}
		case 5:
		{
			double dArr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
			test1<double, 5, 3>(dArr);
			break;
		}
		default:
		cerr << "Invalid test case" << endl;
	}

	return 0;

}
