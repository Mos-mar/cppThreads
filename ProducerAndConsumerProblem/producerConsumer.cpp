#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <chrono>
#include <algorithm>
#include <deque>
using namespace std;
/*Producer-Consumer Problem (Buffer Problem)

The Producer-Consumer problem is a classic synchronization problem where:

    The Producer generates data and puts it into a shared buffer.

    The Consumer takes data from the buffer for processing.

    The buffer has a limited size, so:

        -The Producer must wait if the buffer is full.

        -The Consumer must wait if the buffer is empty.

To avoid race conditions, mutual exclusion (via a mutex) and synchronization 
(via condition variables or semaphores) are used to coordinate access to the buffer.*/

mutex mu;
condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize = 50;

void producer(int val){
    while(val){
        unique_lock<mutex> locker(mu);
        cond.wait(locker,[] () {return buffer.size() < maxBufferSize;});
        buffer.push_back(val);
        cout << "Produced : " << val << endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer(){
    while(true){
        unique_lock<mutex> locker(mu);
        cond.wait(locker,[] () {return buffer.size() > 0;});
        int val = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << val << endl;
        locker.unlock();
        cond.notify_one();
    }
}
int main(){
    thread t1(producer,100);
    thread t2 (consumer);

    t1.join();
    t2.join();
    return 0;
}