#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define foi( i , n , k) for( int i = n ; i < k ; i++)
using namespace std;

int main()
{
  int n,c=0;
  while(scanf("%d",&n)!=EOF && n!= 0)
  {
    vector<int> v(n),vv;
    foi( i , 0 , n )
      scanf("%d",&v[i]);
    foi( i , 0 , n )
      foi( j , i+1 , n)
        vv.push_back(v[i]+v[j]);
    int q;
    scanf("%d",&q);
    printf("Case %d:\n",++c);
    foi( i , 0 , q )
    {
      int m;
      scanf("%d",&m);
      int men,num=0;
      foi( j , 0 , vv.size() )
      {
        if( j == 0)
        {
          num=vv[j];
          men=abs(num-m);
        }
        else if( men > abs(vv[j]-m))
        {
          men=abs(vv[j]-m);
          num=vv[j];
        }
      }
      printf("Closest sum to %d is %d.\n",m,num);
    }
  }
  return 0;
}
