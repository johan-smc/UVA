#include <iostream>
#include <cstdio>
#include <vector>

#define foi( i , n , k ) for( int i =  n ; i <k ; ++i )
using namespace std;


int main()
{
  int n,c=0;
  while( scanf("%d",&n) != EOF && n!=0 )
  {
    if(c!=0)
      printf("\n");
    c++;
    vector<int> v(n);
    foi( i , 0 , n )
    {
      scanf("%d",&v[i]);
    }
    foi( i , 0 , n-5 )
    {
      foi( j , i+1 , n -4 )
      {
        foi( k , j+1, n -3  )
        {
          foi( m , k+1 , n-2)
          {
            foi( l , m+1, n-1 )
            {
             foi( y , l +1 , n )
             {
              printf("%d %d %d %d %d %d\n",v[i],v[j],v[k],v[m],v[l],v[y]);
             }
            }
          }
        }
      }
    }
  }
  return 0;
}
