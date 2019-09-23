// example adapted from Williams "C++ Concurrency in Action" (Manning, 2nd Ed., 2019)
// listing_3.1.cpp

#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list;
std::mutex some_mutex;

// use a 'lock_guard<mutex>' instead of manual mutex.lock() and mutex.unlock()
void add_to_list(int new_value) {
    std::lock_guard<std::mutex> guard(some_mutex);  // locks until guard destructor called
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find) {
    std::lock_guard<std::mutex> guard(some_mutex);  // locks until guard destructor called
    return std::find(some_list.begin(),some_list.end(),value_to_find)
        != some_list.end();
}

int main()
{
    add_to_list(42);
    std::cout<<"contains(1)="<<list_contains(1)<<", contains(42)="<<list_contains(42)<<std::endl;
}
