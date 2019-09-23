// example adapted from Williams "C++ Concurrency in Action" (Manning, 2nd Ed., 2019)
// listing_2.7.cpp

#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <chrono>

namespace chrono = std::chrono;

void do_work(unsigned id) {
	for (int j; j < 1e8; j++){};
	std::cout << id << std::endl;
}

int main(int argc, char* argv[]) {
	unsigned N=10;
	if (argc > 1)
		N = atoi(argv[1]);

	auto start = chrono::steady_clock::now();

    std::vector<std::thread> threads;
    for(unsigned i=0;i<N;++i)
    {
        threads.push_back(std::thread(do_work,i));
    }
    std::for_each(threads.begin(),threads.end(),
        std::mem_fn(&std::thread::join));  // std::thread::join() would fail

	auto end = chrono::steady_clock::now();
	std::cout << "Tot: " << chrono::duration <double, std::milli> (end-start).count() << " ms" << std::endl;
}
