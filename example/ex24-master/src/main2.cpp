// example adapted from Williams "C++ Concurrency in Action" (Manning, 2nd Ed., 2019)
// listing_3.1.cpp

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <thread>
#include <functional>
#include <chrono>

std::list<int> some_list;

// This function is not thread-safe!
void add_to_list(int new_value) {
    std::this_thread::sleep_for(std::chrono::microseconds(2000));
    some_list.push_back(new_value);
}

// What happens if find iterates through 'some_list' while it is being modified?
bool list_contains(int value_to_find) {
    return std::find(some_list.begin(),some_list.end(),value_to_find)
        != some_list.end();
}

int main()
{
    std::vector<std::thread> wThreads;
    for (int i=0; i < 100; i++) {
        wThreads.push_back(std::thread(add_to_list,i));

    }
    std::for_each(wThreads.begin(),wThreads.end(),
        std::mem_fn(&std::thread::detach)); // what if we used join()?

    for(int i=0; i < 100; i++){
        std::cout << "contains(" << i << ")=" << list_contains(1) << std::endl;
    }
}
