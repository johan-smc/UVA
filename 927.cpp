#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int  i = n ; i < k ; ++i)
#define ull unsigned long long
using namespace std;

ull ele( int n, int e )
{
  if( e == 0 )
    return 1;
  if( n == 0)
    return 0;
  ull tot=n;
  foi( i, 1 , e )
  {
    tot*=n;
  }
  return tot;
}

ull funcion(vector<int>&an,int c)
{
  ull tot=0;
  foi( i , 0 , (int)an.size() )
  {
    tot+=(an[i]*ele(c,i));
  }
  return tot;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    vector<int> an(n+1);
    foi( i , 0 , n+1 )
    {
      scanf("%d",&an[i]);
    }
    int d,k;
    scanf("%d%d",&d,&k);
    int c=0;
    int temp=d;
    while( k > 0)
    {
      k-=d;
      d+=temp;
      c++;
    }
    // cout<<c<<endl;
    printf("%llu\n",funcion(an,c));
  }
  return 0;
}
