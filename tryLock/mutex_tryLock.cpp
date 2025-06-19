#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Time(){
    for(int i = 0 ; i < 100000; ++i){
        if(mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
    }
}

int main(){
    thread t1(increaseTheCounterFor100000Time);
    thread t2(increaseTheCounterFor100000Time);

    t1.join();
    t2.join();

    cout << " counter could increase up to :  " << counter  << endl;
}