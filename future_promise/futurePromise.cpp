#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <chrono>
#include <algorithm>
using namespace std;

typedef long int ull;

void findOdd(promise<ull>&& OddSumPromise, ull start, ull end){
    ull OddSum =0;
    for(ull i = start; i <= end; ++i){
        if(i & 1){
            OddSum += i;
        }
    }
    OddSumPromise.set_value(OddSum);
}

int main(){
    ull start = 0 , end = 1900000000;

    promise<ull> OddSum;
    future<ull> OddFuture = OddSum.get_future();

    cout << "Thread Created!" << endl;
    thread t1(findOdd,move(OddSum), start,end);

    cout <<"Waiting for Result !" << endl;

    cout << "OddSum :  "  << OddFuture.get() << endl;

    cout << "COMPLETED ! " << endl;
    t1.join();
    return 0;
}