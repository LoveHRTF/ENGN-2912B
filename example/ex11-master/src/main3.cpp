#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

// adopted from Pitt-Francis & Whiteley 2nd Ed., Listing 4.3
int main(int argc, char* argv[]) {

	// initialize pointers and dynamically allocate new memory
	shared_ptr<int> p_x(new int);
	*p_x = 5;

	// the use_count() method tells hom many pointers exist to this memory
	cout << "p_x use count:  " << p_x.use_count() << endl << endl;

	// a weak_ptr can be initialized from a shared_ptr
	weak_ptr<int> p_y(p_x);
	cout << "Initialize p_y(p_x)" << endl;
	cout << "p_x use count:  " << p_x.use_count() << endl;
	cout << "p_y use count:  " << p_y.use_count() << endl << endl;

	// the reset() method tells the smart pointer that it is no longer needed.
	p_y.reset();
	cout << "Reset p_y" << endl;
	cout << "p_x use count:  " << p_x.use_count() << endl;
	cout << "p_y use count:  " << p_y.use_count() << endl << endl;

	// when shared_ptr reaches use_count==0, it implicitly calls delete for this unused memory
	p_x.reset();
	cout << "Reset p_x" << endl;
	cout << "p_x use count:  " << p_x.use_count() << endl;
	cout << "p_y use count:  " << p_y.use_count() << endl << endl;

	// what happens when we try to access memory through p_x after it is reset?
	// *p_x = 10;
	// cout << *p_x << endl;

	return 0;
}
