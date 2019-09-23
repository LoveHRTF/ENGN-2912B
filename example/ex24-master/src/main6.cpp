#include <future>
#include <iostream>
#include <chrono>

int find_the_answer_to_ltuae() {
    std::cout << "Searching for the answer...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(6000));
    std::cout << "I've found the answer!" << std::endl;
    return 42;
}

void do_other_stuff() {
    std::cout << "Doing other stuff...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "Done doing other stuff!" << std::endl;
}

int main() {
    std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    int res = the_answer.get();     // this call to get() blocks until thread completes
    std::cout << "The answer is " << res << std::endl;
}
