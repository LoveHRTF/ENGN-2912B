
#include <iostream>
#include <iomanip>
#include "points.hpp"

using std::cout;
using std::endl;
using std::setprecision;

int main()
{
	// test constructors
	point a, b(7, 9), c;

	// test setters (mutators)
	a.setx(3.141592653589);
	a.sety(-2.555555);
	
	// test binary addition
	c = a + b;
	cout << setprecision(6) << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a + b = " << a+b << endl;
	cout << "c = a + b = " << c << endl << endl;

	// test getters (accessors)
	cout << "a = (" << a.getx() << ", " << a.gety() << ")" << endl;
	cout << "b = (" << b.getx() << ", " << b.gety() << ")" << endl;
	cout << "c = (" << c.getx() << ", " << c.gety() << ")" << endl << endl;

	// test increment and decrement operators
	point d;
	cout << "d = " << d << endl;
	cout << "d++ = " << d++ << endl;
	cout << "++d = " << ++d << endl;
	cout << "--d = " << --d << endl;
	cout << "d-- = " << d-- << endl;
	cout << "d = " << d << endl;

	return 0;
}

