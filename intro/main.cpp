#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

typedef unsigned long long ull;
using namespace std;

ull oddSum = 0 ; ull evenSum = 1900000000;

void findEven(ull start, ull end)
{
    for(ull i = start ; i <= end; i++)
    {
        if((i & 1) == 0)
        evenSum += i;

    }
}

void findOdd(ull start, ull end)
{
    for(ull i = start ; i <= end; i++)
    {
        if((i & 1) == 1)
        oddSum += i;

    }
}
int main()
{
  ull start = 0; ull end = 1900000000;
  
  auto startTime = std::chrono::high_resolution_clock::now();
  
  //will run the two functions parallelly
  std::thread t1(findEven,start,end);
  std::thread t2(findOdd,start,end);

  t1.join();
  t2.join();

  //findEven(start,end);
  //findOdd(start,end);
  auto stopTime = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stopTime - startTime);
  cout << oddSum << ' ' << evenSum << endl;
  cout << "it took : " << duration.count()/1000000 << " seconds" << endl;
}