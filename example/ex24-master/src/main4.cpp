// example adapted from cppreference.com (https://en.cppreference.com/w/cpp/thread/unique_lock)
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

struct Box {
    explicit Box(int num) : num_things{num} {}

    int num_things;
    std::mutex m;
};

void transfer(Box &from, Box &to, int num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);

    from.num_things -= num;
    to.num_things += num;

    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}

int main()
{
    Box acc1(100);
    Box acc2(50);

    std::cout << "Box 'acc1' contains " << acc1.num_things << "things" << std::endl;
    std::cout << "Box 'acc2' contains " << acc2.num_things << "things" << std::endl;

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

    t1.join();
    t2.join();

    std::cout << "Box 'acc1' now contains " << acc1.num_things << " things" << std::endl;
    std::cout << "Box 'acc2' now contains " << acc2.num_things << " things" << std::endl;
}
