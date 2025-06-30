#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
using namespace std;

//Example of Data Race
long  long balance = 0;
mutex m;

void addMoney(int val){
  m.lock();
  balance += val;
  m.unlock();
}



int main(){
    thread t1(addMoney,100);
    thread t2(addMoney,200);
    t1.join();
    t2.join();

    cout << "Final Bank balance : " << balance<< endl;
    return 0;
}
