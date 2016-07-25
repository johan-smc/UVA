#include <iostream>
#include <cstdio>
#include <vector>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i)
#define ll long long
using namespace std;

bool fun( vector< int > &v, ll n  )
{
  ll pos=0, l = 0 ;
  while( n >= 0 && pos < (int)v.size() )
  {
    if(v[pos]-l > n)
      return false;
    if( v[pos]-l ==n)
      n--;
    l=v[pos];
    pos++;
  }
  if( n < 0 || pos < (int)v.size() )
    return false;
  return true;
}

ll bisection( vector< int > &v, ll HI)
{
  ll lo=0,hi=HI,ans=hi;
  while( lo != (lo+hi)/2 )
  {
    ll mid=(lo+hi)/2;
    if( fun(v,mid) )
    {
      hi=mid;
      ans=hi;
    }
    else
      lo=mid;
  }
  return ans;
}

int main()
{
  int t;
  scanf("%d",&t);
  foi( k , 0 , t)
  {
    int n;
    ll hi=0;
    scanf("%d",&n);
    vector<int> v(n);

    foi( i , 0 , n)
    {
      scanf("%d",&v[i]);
      hi+=v[i];
    }
    printf("Case %d: %lld\n",k+1,bisection(v,hi));
  }
  return 0;
}
