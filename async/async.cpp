#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <algorithm>
using namespace std;
typedef long int ull;

ull findOdd(ull start, ull end){
    ull OddSum = 0 ;
    cout << "ThreadID of findOdd : " << this_thread::get_id() << endl;
    for(ull i = start ;  i <= end ; ++i)
    {
        if(i&1){
            OddSum += i;
        }
    }
    return OddSum;
}

int main(){
    ull start = 0 , end = 1900000000;
    cout << "ThreadID of findOdd : " << this_thread::get_id() << endl;
    cout << "Thread created if policy is std::launch::async !! " << endl;
    future<ull> OddSum = std::async(launch::async, findOdd,start,end); //launch::deferred wont create a new thread

    cout << "Waiting For Result !! " << endl;
    cout << "OddSum : " << OddSum.get() << endl;

    cout << "Completed!! " << endl;
    return 0;
}