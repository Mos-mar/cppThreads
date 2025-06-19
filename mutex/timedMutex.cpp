#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increment(int i){
    if(m.try_lock_for(chrono::seconds(1))) //try_lock_untill(chrono::steady_clock::now() + chrono::seconds(1)))
    {
        ++myAmount;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Thread " << i << " Entered"<< endl;
        m.unlock();
    }else{
        cout << "Thread " << i << " Couldn't Enter" << endl;
    }
}

int main(){
    thread th1(increment,1);
    thread th2(increment,2);
    th1.join();
    th2.join();

    cout << myAmount << endl;
    return 0;
}