#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor)
{
    lock_guard<mutex> lock(m1);
    for(int i = 0 ; i < loopFor; ++i){
        buffer++;
        cout << threadNumber << ' ' <<  buffer << endl;
    }
}

int main(){
  thread t1(task,"T0",10);
  thread t2(task,"T1",10);
  t1.join();
  t2.join();
  return 0;
}