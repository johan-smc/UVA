#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

int fun(vector<int>&v,int m)
{
  int ma=999999;
  int num=0;
  foi( i , 0 , v.size() )
  {
    foi( j , i+1 , v.size() )
    {
      if(abs(v[i]+v[j]-m)<ma)
      {
        ma=abs(v[i]+v[j]-m);
        num=v[i]+v[j];
      }
    }
  }
  return num;
}

int main()
{
  int n,q,c=0;
  while( scanf("%d",&n)!=EOF && n!=0)
  {
    printf("Case %d:\n",++c);
    vector<int> v(n);
    foi( i , 0 , n)
    {
      scanf("%d",&v[i]);
    }
    scanf("%d",&q);
    int ser=0;
    foi( i , 0 , q)
    {
      int m;
      scanf("%d",&m);
      printf("Closest sum to %d is %d.\n",m,fun(v,m));
    }
  }
  return 0;
}
