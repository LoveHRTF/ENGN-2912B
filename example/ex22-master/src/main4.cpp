// example adapted from Williams "C++ Concurrency in Action" (Manning, 2nd Ed., 2019)
// listing_2.8.cpp

#include <thread>
#include <numeric>      // provides accumulate (serial)
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <cassert>
#include <chrono>
#include <cmath>

namespace chrono = std::chrono;

#define DEBUG
#define CHRONO

template<typename Iterator,typename T>
struct accumulate_block {
    void operator()(const unsigned long id, Iterator first, Iterator last, T& result) {

        // track the timing of current thread
        #ifdef CHRONO
        auto t0 = chrono::steady_clock::now();
        #endif // CHRONO

        // perform serial accumulation of data block
        result = std::accumulate(first,last,result);

        // report timing of current thread
        #ifdef CHRONO
        auto t1 = chrono::steady_clock::now();
        std::cout << "Thread " << id << " time:  " << chrono::duration <double, std::micro> (t1-t0).count() << " us" << std::endl;
        #endif // CHRONO

    }
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init) {

    // track the timing of each section
    #ifdef CHRONO
    auto t0 = chrono::steady_clock::now();
    std::vector<decltype(t0)> timestamps;
    timestamps.push_back(chrono::steady_clock::now());
    #endif // CHRONO

    // get vector length
    unsigned long const length = std::distance(first,last);
    #ifdef DEBUG
    std::cout << "Vector contains " << length << " elements" << std::endl;
    #endif //DEBUG

    // return with initial value if length is 0
    if(!length)
        return init;

    // define min/max values
    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length+min_per_thread-1) / min_per_thread;

    // get number of available processing cores
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    #ifdef DEBUG
    std::cout << "Found " << hardware_threads << " processor cores" << std::endl;
    #endif //DEBUG

    // determine number of threads (default to 2 if we can't tell)
    unsigned long const num_threads =
        std::min(hardware_threads!=0 ? hardware_threads : 2, max_threads);
    #ifdef DEBUG
    std::cout << "Using " << num_threads << " threads" << std::endl;
    #endif //DEBUG

    // determine block size
    unsigned long const block_size = length / num_threads;
    #ifdef DEBUG
    std::cout << "Block size is " << block_size << " elements" << std::endl;
    #endif //DEBUG

    // initialize vectors
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);

    #ifdef CHRONO
    timestamps.push_back(chrono::steady_clock::now());
    #endif // CHRONO

    // launch a new thread for each block
    Iterator block_start = first;
    for(unsigned long i=0; i<(num_threads-1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);    // move block_end to start of next block
        threads[i] = std::thread(               // launch new thread, store object in vector of threads
            accumulate_block<Iterator,T>(),     // thread executes with function object
            i+1, block_start, block_end,        // pass id and indices by value
            std::ref(results[i]));              // pass shared memory vector by reference
        block_start = block_end;
    }

    #ifdef CHRONO
    timestamps.push_back(chrono::steady_clock::now());
    #endif // CHRONO

    // add remaining values in main thread
    accumulate_block<Iterator,T>()(0, block_start,last,results[num_threads-1]);

    #ifdef CHRONO
    timestamps.push_back(chrono::steady_clock::now());
    #endif // CHRONO

    // join each thread to main - block execution until all threads are complete
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    #ifdef CHRONO
    timestamps.push_back(chrono::steady_clock::now());
    #endif // CHRONO

    // sum results of each thread and return
    auto res = std::accumulate(results.begin(), results.end(), init);

    #ifdef CHRONO
    timestamps.push_back(chrono::steady_clock::now());
    #endif // CHRONO

    // report timing of each section
    #ifdef CHRONO
    for (auto t = timestamps.begin()+1; t < timestamps.end(); t++)
        std::cout << chrono::duration <double, std::micro> (*t-*(t-1)).count() << " us" << std::endl;
    #endif // CHRONO

    return res;
}

int main(int argc, char* argv[])
{
    // accept optional input parameter for vector size
    unsigned long vSize = 1000;
    if (argc > 1){
        int exponent = atoi(argv[1]);
		vSize = static_cast<unsigned long>(pow(10,exponent));
	}
    assert(vSize);      // verify positive integer entered

    // populate vector with integers
    std::vector<int> vi;
    for(unsigned long i=0; i<vSize; ++i) {
        vi.push_back(10);
    }

    // run serial accumulation (and time it)
    #ifdef CHRONO
    auto ser_start = chrono::steady_clock::now();
    #endif // CHRONO

    long int ser_sum = accumulate(vi.begin(), vi.end(), 5);

    #ifdef CHRONO
    auto ser_end = chrono::steady_clock::now();

    std::cout << "Serial Elapsed Time = " <<
        chrono::duration <double, std::milli> (ser_end-ser_start).count() <<
        " ms" << std::endl;
    #endif //CHRONO

    std::cout << "Serial sum = " << ser_sum << "\n\n" << std::endl;

    // run parallel accumulation (and time it)
    #ifdef CHRONO
    auto par_start = chrono::steady_clock::now();
    #endif // CHRONO

    long int par_sum = parallel_accumulate(vi.begin(), vi.end(), 5);

    #ifdef CHRONO
    auto par_end = chrono::steady_clock::now();

    std::cout << "Parallel Elapsed Time = " <<
        chrono::duration <double, std::milli> (par_end-par_start).count() <<
        " ms" << std::endl;
    #endif // CHRONO

    std::cout << "Parallel sum = " << par_sum << std::endl;
}
