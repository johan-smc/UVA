#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n,x,t,k,lim,CC;
int favour[ 105 ], cost[ 105 ];
int dp[ 105 ][ 1200 ];

int buy( int tea, int  f )
{
  // cout << tea << " " << f << endl;
  if( tea == n+1 )
    return 0;
  if( dp[ tea ][ f ] != -1 )
    return dp[ tea ][ f ];
  int n0,n1,n2;
  n0 = buy( tea + 1 , f );
  n1 = ceil((f+(cost[tea])+CC)*0.1)+(f+(cost[tea])) <= lim ? buy( tea + 1 , f + (cost[tea]) ) + favour[ tea ] : 0;
  n2 = ceil((f+(cost[tea]*2+CC))*0.1)+(f+(cost[tea])*2) <= lim  ? buy( tea + 1 , f + (cost[tea]*2) ) + favour[ tea ] * 2 : 0;
  return dp[ tea ][ f ] = max( n0 , max( n1 , n2 ) );
}

int main()
{
      int sum = 0 ;
  while( scanf("%d %d %d %d",&n,&x,&t,&k) , (n||x||t||k) )
  {
    for( int i = 0 ; i < k ; ++i )
    {
      scanf("%d",&cost[i]);
      favour[ i ] = 0 ;
      for( int j = 0  ; j < n + 1 ; ++j  )
      {
        scanf( "%d" , &sum );
        favour[ i ] += sum;
      }
    }
    lim = ((n+1)*x)-((n+1)*t);
    CC  = ((n+1)*t);
    // cout << lim << endl;
    memset( dp , -1 , sizeof dp );
    printf( "%.2lf\n", (double)buy(0, 0 )/(double)(n+1) );
  }
  return 0;
}
