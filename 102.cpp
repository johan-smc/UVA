#include <iostream>
#include <cstdio>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i)
#define ll long long
using namespace std;

ll bb[6][3]={{0,2,1},{0,1,2},{2,0,1},{2,1,0},{1,0,2},{1,2,0}};
char ccc[3]={'B','G','C'};

int main()
{
  ll a[3];
  ll b[3];
  ll c[3];
  while( scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2],&c[0],&c[1],&c[2])!=EOF)
  {
    ll men=999999999999;
    string s;
    foi( i , 0 , 6 )
    {
      ll x,y,z;
      x=bb[i][0];
      y=bb[i][1];
      z=bb[i][2];
      ll sum=0;
      sum+=b[x]+c[x];
      sum+=a[y]+c[y];
      sum+=a[z]+b[z];
      string temp="";
      temp+=ccc[x];
      temp+=ccc[y];
      temp+=ccc[z];
      if( men > sum )
      {
        men=sum;
        s=temp;
      }
    }
    cout<<s;
    printf(" %lld\n",men);
  }
  return 0;
}
