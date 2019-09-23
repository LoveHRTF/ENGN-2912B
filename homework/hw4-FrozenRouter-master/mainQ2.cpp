#include <iostream>
#include <string>
#include "pairs.h"

using namespace std;

int main()
{
    //Question 2: Pairs class
    pairs<int, double> p1;
    pairs<int, double> p2 = p1;
    pairs<double, string> p3(1.6666, "Who am I? I'm a string!");

    p1.set_first(10);
    p1.set_second(2.7183);

    cout << "p1 => (" << p1.get_first() << ", " << p1.get_second() << ")" << endl;
    cout << "p2 => "; p2.print();
    cout << "p3 => " << p3 << endl << endl;

    cout << "p1 == p2 ? " << (p1==p2) << endl;
    cout << "p1 != p2 ? " << (p1!=p2) << endl <<endl;

    p2 = p1;
    cout << "p2 => " << p2 << endl << endl;

    cout << "p1 == p2 ? " << (p1==p2) << endl;
    cout << "p1 != p2 ? " << (p1!=p2) << endl;

    return 0;

}
