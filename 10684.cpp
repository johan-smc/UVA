#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i)
using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF && n!=0 )
  {
    vector<int> v(n);
    foi( i , 0 , n )
      scanf("%d",&v[i] );
    int sum,may=-99999;
    foi( i , 0 , n )
    {
      sum=0;
      foi( j , i , n )
      {
        sum+=v[j];
        may=max(sum,may);
      }
    }
    if(may>0)
      printf("The maximum winning streak is %d.\n",may);
    else
      printf("Losing streak.\n" );
  }
  return 0;
}
