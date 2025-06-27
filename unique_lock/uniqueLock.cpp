#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

//Example 1
/*
mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor){
    unique_lock<mutex> lock(m1); //automatically calls lock on mutext m1
    for(int i = 0 ; i <loopFor ; ++i){
        buffer++;
        cout << threadNumber << ' ' << buffer << endl;
    }
}

int main(){
    thread t1(task,"T1", 10);
    thread t2(task,"T2",10);
    t1.join();
    t2.join();
    return 0;
}
*/

//Example 2
mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor){
    unique_lock<mutex> lock(m1,defer_lock); //does not call lock on mutex m1, because used defer_lock
    lock.lock();// but then we will have to explicitly call lock() whenever we want to lock m1
    for(int i = 0 ; i <loopFor ; ++i){
        buffer++;
        cout << threadNumber << ' ' << buffer << endl;
    }
    //lock.unlock();// is not needed as it will be unlocked in destructor of unique_lock
}

int main(){
    thread t1(task,"T1", 10);
    thread t2(task,"T2",10);
    t1.join();
    t2.join();
    return 0;
}