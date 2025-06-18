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
  findEven(start,end);
  findOdd(start,end);
  cout << oddSum << ' ' << evenSum << endl;
}