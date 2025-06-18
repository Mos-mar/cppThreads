#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;


//Function pointer
// void fun(int x){
//     while(x --> 0){
//         cout << x << endl;
//     }
// }

// int main(){
//     thread t1(fun,11);
//     t1.join();

//     return 0;
// }


//Lambda
// int main(){
//     std::thread t2([](int x){
//          while(x --> 0){
//           cout << x << endl;
//          }
// },10);
// t2.join();
// return 0;
// }


//Functor (function object)
// class Base{
//     public:
//     void operator ()(int x){
//         while(x-->0){
//             cout << x << endl;
//         }
//     }
// };

// int main(){
//  std::thread t3((Base()),10);
//  t3.join();
//  return 0;
// }


//Non-static member function
// class Base{
//     public: 
//     void run(int x){
//         while(x-->0)
//         {
//             cout << x << endl;
//         }
//     }
// }; 


//  int main(){
//     Base b;
//     std::thread t4(&Base::run ,&b ,10);
//     t4.join();
    
//     return 0;
//  }


//Static member function
class Base{
    public: 
    static void run(int x){
        while(x-->0)
        {
            cout << x << endl;
        }
    }
}; 


 int main(){
    std::thread t4(&Base::run,10);
    t4.join();
    
    return 0;
 }
