#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n,x,t,k,lim,CC,pLIM;
int favour[ 105 ], cost[ 105 ];
int dp[ 105 ][ 1200 ][ 24 ];

int buy( int tea, int  f , int llevo )
{
  if( tea == k )
    return 0;
  if( dp[ tea ][ f ][ llevo ] != -1 )
    return dp[ tea ][ f ][ llevo ];
  int n0,n1,n2;
  n0 = buy( tea + 1 , f , llevo );
  n1 = ceil((f+(cost[tea])+CC)*0.1)+(f+(cost[tea])) <= lim && llevo+1 < pLIM? buy( tea + 1 , f + (cost[tea]) , llevo + 1) + favour[ tea ] : 0;
  n2 = ceil((f+(cost[tea]*2+CC))*0.1)+(f+(cost[tea])*2) <= lim  && llevo+2 < pLIM ? buy( tea + 1 , f + (cost[tea]*2) , llevo + 2 ) + favour[ tea ] * 2 : 0;
  // cout << tea << " " << f << " " << llevo << " " << max( n0 , max( n1 , n2 ) ) <<  endl;
  return dp[ tea ][ f ][ llevo ] = max( n0 , max( n1 , n2 ) );
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
    pLIM = (n+1)*2;
    // cout << lim << endl;
    memset( dp , -1 , sizeof dp );
    // cout << buy( 0 , 0 , 0 ) << " " << n+1 << endl;
    printf( "%.2lf\n", (double)buy(0, 0, 0 )/(double)(n+1) );
  }
  return 0;
}
