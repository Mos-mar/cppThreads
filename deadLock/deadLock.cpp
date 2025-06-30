#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
using namespace std;


mutex m1,m2;

void thread1(){
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout << "Critical section of Thread Thread One\n";
    m1.unlock();
    m2.unlock();
}

/*to avoid deadlock just change the order of mutex lock to be the same in thread2
    m1.lock();
    m2.lock();
*/
void thread2(){
    m2.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout << "Critical section of Thread Thread Two\n";
    m2.unlock();
    m1.unlock();
}

void thread2NODEADLOCK(){
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout << "Critical section of Thread Thread Two\n";
    m2.unlock();
    m1.unlock();
}

int main(){
    thread t1(thread1);
    thread t2(thread2NODEADLOCK);
    t1.join();
    t2.join();
    return 0;
}
