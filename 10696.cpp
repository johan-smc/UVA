#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int,int> mp;
int fun( int n )
{
  if(n>=101)
    return n-10;
  if(mp.find(n)!=mp.end())
    return mp[n];
  return mp[n]=fun(fun(n+11));
}

int main()
{
  int n;

  while(scanf("%d",&n)!=EOF && n!=0)
  {
    printf("f91(%d) = %d\n",n,fun(n));
  }
  return 0;
}
