#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

// shared variable
int num = 0;

// mutex object
mutex mux;

void increment() {
    mux.lock();

    for(int i = 0; i < 1000000; i++) {
        num++;
    }

    mux.unlock();
}

int main() {
    thread t1(increment);
    thread t2(increment);

    // stop the main thread and start thread t1 and thread t2, simultaneously
    t1.join();
    t2.join();

    cout << "Shared Number: " << num << endl;
    return 0;
}
