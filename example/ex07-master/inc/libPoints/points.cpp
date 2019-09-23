#include "points.hpp"
#include <iostream>

using namespace std;

point::point()
{
	setx(0.0);
	sety(0.0);
}

// constructor definition using assignment
/*point::point(double ptx, double pty)
{
	setx(ptx);
	sety(pty);
}*/

point point::operator+ (const point& p) const{
	point sum(x + p.x, y + p.y);
	return sum;
}

point& point::operator-- (){
//cout << "--a\n";
    x--;
    y--;
    return *this;
}

point& point::operator++ (){
//cout << "++a\n";
    x++;
    y++;
    return *this;
}

point point::operator-- (int){
//cout << "a--\n";
    point tmp = *this;
    --*this;
    return tmp;
}

point point::operator++ (int){
//cout << "a++\n";
    point tmp = *this;
    ++*this;
    return tmp;
}


// This operator is not a member of the class 'point', but using "friend" allows access to private variables
ostream& operator<< (ostream& out, const point& p){
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

