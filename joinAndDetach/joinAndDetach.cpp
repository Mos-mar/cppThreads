#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

void run(int count){
    while(count -->0)
      cout << count <<  " Cpp threads" << endl; 
      //std::this_thread::sleep_for(chrono::seconds(5));
      cout << "thread finished"  << endl;
}

int main(){
    thread t1(run,20);
    cout << "main()" << endl;
    
    if(t1.joinable()){
        //t1.join();
        t1.detach();
    }

    cout << "main() after" << endl;
    //std::this_thread::sleep_for(chrono::seconds(5));
    return 0;
}