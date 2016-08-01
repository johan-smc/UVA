#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define foi( i , n , k ) for( int i = n ; i <  k ; ++i )
#define llo long long
using namespace std;

bool fun(vector<int> &v,int m,llo n)
{
  llo pos=0,c=0;
  while( pos < (llo)v.size() )
  {
    if(c>=m)
      return false;
    llo sum=0;
    while( sum+v[pos]<=n  && pos < (int)v.size() )
    {
      sum+=v[pos++];
    }
    c++;
  }
  return true;
}

llo bisection(vector<int> &v , int m,int HI )
{
  llo lo=0,hi=HI,ans=HI;
  while( lo != (lo+hi)/2 )
  {
    llo mid=(lo+hi)/2;
    if( fun( v,m,mid) )
    {
      hi=mid;
      ans=mid;
    }
    else
      lo=mid;
      // cout<<lo<<" "<<hi<<" "<<mid<<endl;
  }
  return ans;
}

int main()
{
  int n,m;
  while( scanf("%d%d",&n,&m)!=EOF )
  {
    vector<int> v(n);
    int hi=0;
    foi( i , 0 , n )
    {
      scanf("%d",&v[i]);
      hi+=v[i];
    }
    printf("%lld\n",bisection(v,m,hi));
  }
  return 0;
}
