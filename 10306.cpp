#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAX 43
#define LIM 303
#define INF 1<<22

int m,gol;
int cashA[ MAX ],cashB[ MAX ];
int dp[ LIM ][ LIM ];

int mod( int x , int y )
{
  if( ( x * x ) + ( y * y ) == gol )
    return 0;
  if( ( x * x ) + ( y * y ) > gol )
    return INF;
  if( dp[ x ][ y ] != -1 )
    return dp[ x ][ y ];
  int men = INF ;
  for( int i = 0 ; i < m ; ++i )
    men = min( men , mod( x + cashA[ i ] , y + cashB[i] ) + 1  );
    return dp[ x ][ y ] = men;
}

int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int s;
    scanf("%d %d",&m,&s);
    for( int i = 0 ; i < m ; ++i )
    {
      scanf("%d %d", &cashA[i] , &cashB[i] );
    }
    gol = s * s;
    memset( dp , -1 , sizeof dp );
    int res = mod(  0  ,  0  );
    if( res == INF )
      printf("not possible\n");
    else
      printf("%d\n", res );
  }
  return 0 ;
}
