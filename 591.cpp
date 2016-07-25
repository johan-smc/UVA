#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int i = n ; i <k ; ++i )
using namespace std;

int main()
{
  int n,c=1;
  while( scanf("%d",&n)!=EOF && n!=0 ){
    vector<int> v(n);
    int sum=0;
    foi( i , 0 , n)
    {
      scanf("%d",&v[i]);
      sum+=v[i];
    }
    sum/=n;
    int tot=0;
    foi( i , 0 , n)
    {
      if( v[i] - sum >0 )
        tot+=(v[i]-sum);
    }
    printf("Set #%d\n",c++);
    printf("The minimum number of moves is %d.\n\n",tot);
  }
  return 0;
}
