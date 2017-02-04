#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 101


int main()
{
  int rutesM[ MAX ], rutesE[ MAX ];
  int n,d,r,sum;
  while( scanf("%d %d %d",&n,&d,&r ) , (n||d||r) )
  {
    sum = 0;
    for( int i = 0 ; i < n ; ++i )
      scanf("%d",&rutesM[ i ] );
    for( int i = 0 ; i < n ; ++i )
      scanf("%d",&rutesE[ i ] );
    sort( rutesM , rutesM + n );
    sort( rutesE , rutesE + n , greater<int>() );
    for( int i = 0; i < n ; ++i )
      if( rutesM[ i ] + rutesE[ i ] > d )
        sum += ( (rutesM[ i ]+rutesE[ i ]) - d );
    printf("%d\n", sum*r );
  }
  return 0;
}
