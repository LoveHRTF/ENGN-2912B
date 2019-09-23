// example adapted from Williams "C++ Concurrency in Action" (Manning, 2nd Ed., 2019)
// listing_1.1.cpp

#include <iostream>
#include <thread>

#define SYNC

// This function recursively spawns a series of nested threads to demonstrate join/detach behavior
void hello(unsigned id)
{
	std::cout<<"Hello Concurrent World " << id << "\n";
	if (id < 10) {
		std::thread t(hello,id+1);
		#ifndef SYNC
		t.detach();
		#else
		t.join();
		#endif
	}
	std::cout<<"Goodbye " << id << "\n";
}

int main()
{
    std::thread t(hello,0);
	#ifndef SYNC
	t.detach();
	#else
	t.join();
	#endif
}
