#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    foi( i , 0 , n )
      scanf("%d",&v[i]);
    int sum=0;
    foi( i , 0 , n -1)
    {
      int men=99999999;
      foi( j , i+1 , n)
      {
        men=min(men,abs(v[i]-v[j]));
      }
      sum+=men;
    }
    printf("%d\n",sum);
  }

  return 0;
}
