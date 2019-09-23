// example adapted from Williams "C++ Concurrency in Action" (Manning, 2nd Ed., 2019)
// listing_3.1.cpp

#include <iostream>
#include <list>
#include <algorithm>

std::list<int> some_list;

// This function is not thread-safe!
void add_to_list(int new_value) {
    some_list.push_back(new_value);
}

// What happens if find iterates through 'some_list' while it is being modified?
bool list_contains(int value_to_find) {
    return std::find(some_list.begin(),some_list.end(),value_to_find)
        != some_list.end();
}

int main()
{
    add_to_list(42);
    std::cout<<"contains(1)="<<list_contains(1)<<", contains(42)="<<list_contains(42)<<std::endl;
}
