#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1<<21

int graph[ 101 ][ 101 ];

void floyd( int may )
{
  for( int k = 0 ; k < may ; ++k )
    for( int i = 0 ; i < may ; ++i )
      for( int j = 0 ; j < may ; ++j )
            graph[ i ][ j ] = min( graph[ i ][ j ] ,  graph[ i ][ k ] + graph[ k ][ j ]);
}

int main()
{
  int a,b,c=0;
  while( scanf("%d %d",&a,&b) , ( a || b ) )
  {
    int may = 0 ;
    for( int i = 0 ; i < 101 ; ++i )
      for( int j = 0 ; j < 101 ; ++j )
        if( i == j )
          graph[ i ][ j ] = 0;
        else
          graph[ i ][ j ] = INF;
    graph[ a-1 ][ b-1 ] = 1 ;
    may = max( a , b );
    while( scanf("%d %d",&a,&b) , ( a || b ) )
    {
        graph[ a-1 ][ b-1 ] = 1 ;
        may = max( max( may , a ) , b );
    }
    floyd( may );
    int sum,tot;
    sum = tot = 0 ;
    for( int i = 0 ; i < may ; ++i )
      for( int j = 0 ; j < may ; ++j )
        if( graph[ i ][ j ] != INF   )
        {
            sum += graph[ i ][ j ];
            if( graph[ i ][ j ])
              ++tot;
        }
    // for( int i = 0 ; i < may ; ++i )
    // {
    //   for( int j = 0 ; j < may ; ++j )
    //     cout << graph[ i ][ j ] << " ";
    //   cout << endl;
    // }
      printf("Case %d: average length between pages = %.3lf clicks\n",++c,(double)sum/(double)tot );
  }
  return 0;
}
