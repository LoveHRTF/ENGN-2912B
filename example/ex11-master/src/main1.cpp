#include <cassert>
#include <memory>

using std::unique_ptr;

// adopted from Pitt-Francis & Whiteley 2nd Ed., Listing 4.2
int main(int argc, char* argv[]) {

	// initialize pointers and dynamically allocate new memory
	unique_ptr<int> p_x(new int);
	int* p_y;
	unique_ptr<int> p_z;

	// unique_ptr dereferences in the same way as a "normal" pointer
	*p_x = 5;

	// we cannot directly copy a unique_ptr object, by design!
	// p_y = p_x;

	// the get() method retreives the raw pointer (this defeats the purpose, though)
	p_y = p_x.get();

	// we can transfer ownership using the std::move() algorithm
	p_z = std::move(p_x);

	// we can also check the status of a smart pointer
	assert(p_z);		// verifies that p_z is in use
	assert(!p_x);		// verifies that p_x is no longer in use

	// the reset() method tells the smart pointer that it is no longer needed.
	p_z.reset();		// unique_ptr implicitly calls delete for this unused memory
	assert(!p_z);		// verifies that p_z is no longer in use

	// what happens when we try to access memory through p_x after it is reset?
	// *p_x = 10;
	// cout << *p_x << endl;

	return 0;
}
