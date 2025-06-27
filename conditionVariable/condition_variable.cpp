#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
using namespace std;

condition_variable cv;
mutex m;
long balance = 0;

void addMoney(int money){
    lock_guard<mutex> lg(m);
    balance += money;
    cout << "Amount added current balance : " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money){
    unique_lock<mutex> ul(m);
    cv.wait(ul,[] {return (balance != 0)? true : false;});
    if(balance >= money){
        balance -= money;
        cout << "Amount deducted : " << money << endl;
    }else{
        cout << "Amount cant be deducted, current balance is less than : " << money << endl;
    }
    cout << "Current balance is : " << balance << endl;
}

int main(){
    thread t1(withdrawMoney,600);
    //this_thread::sleep_for(chrono::seconds(2));
    thread t2(addMoney,500);
    t1.join();
    t2.join();
    return 0;
}
