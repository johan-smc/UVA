#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;
#define MAX 105

typedef pair< int , int > ii;
typedef pair< int , ii > iii;

int graph[ MAX ][ MAX ];

int n,r;

void floyd()
{
  int dt;
  for( int k = 0 ; k < n ; ++k )
    for( int i = 0 ; i < n ; ++i )
      for( int j = 0 ; j < n ;++j )
      {
        dt =   graph[ i ][ k ] + graph[ k ][ j ];
        if( graph[ i ][ j ] > dt )
        {
          graph[ i ][ j ] = dt ;
          path[ i ][ j ] = path[ k ][ j ];
        }
      }
}

void re( int i , int j )
{

}

int main()
{
  int t,c;
  int a,b;
  c = 0;
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d %d",&n ,&r);
    for( int i = 0 ; i < n ; ++i )
      for( int j = 0 ; j < n ; ++j )
      {
        if( j == i )
          graph[ i ][ j ] = 0;
        else
          graph[ i ][ j ] = INF;
        path[ i ][ j ] = i;
      }
    for( int  i = 0 ; i < r  ; ++i )
    {
      scanf("%d %d",&a,&b);
      graph[ a ][ b ] = min(1,graph[a][b]);
      graph[ b ][ a ] = min(1,graph[b][a]);
    }
    scanf("%d %d",&a,&b );
    printf("Case %d: %d\n",++c,totW );
  }
  return 0;
}
