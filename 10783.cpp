#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define foi( i , n , k) for( int i = n ; i < k; ++i)
using namespace std;

vector<bool> pri;
vector<int> v;

void criba()
{
  pri.assign(105,true);
  pri[0]=pri[1]=false;
  foi( i , 2 ,101 )
  {
    if( pri[i] )
    {
      v.push_back(i);
      for( int j= i*i ; j < 101 ; j+=i)
      {
        pri[j]=false;
      }
    }
  }
}

int main()
{
  int n;
  scanf("%d",&n );
//  criba();
  foi( k , 0 , n )
  {
    int sum=0;
    int a,b;
    scanf("%d%d",&a,&b);
    foi( i , a, b+1)
    {
      if(i%2==1)
        sum+=i;
    }
    printf("Case %d: %d\n",k+1,sum);
  }
  return 0;
}
