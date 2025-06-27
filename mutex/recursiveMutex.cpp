#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

//Exemple 1 : with Recursion
recursive_mutex m1;
int buffer = 0;

void recursion(char c, int loopFor){
    if(loopFor<0)
       return;
    m1.lock();
    cout << "ThreadID : " << c << " " << buffer++ << endl;
    recursion(c, --loopFor);
    m1.unlock();
    cout << "unlock by thread " << c << endl;
}

int main(){
    thread t1(recursion, '1',10);
    thread t2(recursion, '2',10);
    t1.join();
    t2.join();
    return 0;
}