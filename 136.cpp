#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define foi( i , n , k ) for(int i = n; i < k ; ++i )
using namespace std;

int main()
{
  long long n=2;
  int c=1;
  while( c<1500)
  {
    if(n%2==0||n%3==0||n%5==0)
      c++;
    n++;
  }
  printf("The 1500'th ugly number is %lld.\n",n);
}
