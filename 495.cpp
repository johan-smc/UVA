#include <iostream>
#include <cstdio>
#include <map>

#define foi( i ,  n , k ) for( int i = m ; i <k ; ++i )
#define ll long long
using namespace std;

map<ll,ll> mp;
ll fibo( ll n ){
  if( n == 0)
    return 0;
  if( n == 1 )
    return 1;
  if( mp.find(n)!=mp.end() )
    return mp[n];

  mp[n]=fibo(n-1)+fibo(n-2);
  return mp[n];
}

int main()
{
  int n;
  while( scanf("%d",&n) != EOF )
    printf("The Fibonacci number for %d is %lld\n",n,fibo(n));
  return 0;
}
