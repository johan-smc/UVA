#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;
#define MAX 105
#define INF 1<<20

typedef pair< int , int > ii;
typedef pair< int , ii > iii;
bitset< MAX > visited;
int graph[ MAX ][ MAX ];
int path[ MAX ][ MAX ];
int ff[ MAX ];
vector< int > res;
bool fres;
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
          path[ i ][ j ] = path[ i ][ k ];
        }
      }
}

int re( int i , int j )
{
  // cout << i << " " << j << " " << visited[ i ]<< " " << visited[ j ] << endl;
  if( visited[ i ] )
    return i;
  int s = i;
  if( i != j ) s = re( path[ i ][ j ] , j );
  if( fres )
    res.push_back( i );

  visited[ i ]  = 1;
  return s;
}

int main()
{
  int t,c;
  int a,b;
  c = 0;
  scanf("%d",&t);
  while( t-- )
  {
    memset( ff , -1 , sizeof ff );
    scanf("%d %d",&n ,&r);
    for( int i = 0 ; i < n ; ++i )
      for( int j = 0 ; j < n ; ++j )
      {
        if( j == i )
          graph[ i ][ j ] = 0;
        else
          graph[ i ][ j ] = INF;
        path[ i ][ j ] = j;
      }
    for( int  i = 0 ; i < r  ; ++i )
    {
      scanf("%d %d",&a,&b);
      graph[ a ][ b ] = min(1,graph[a][b]);
      graph[ b ][ a ] = min(1,graph[b][a]);
    }
    scanf("%d %d",&a,&b );
    floyd();
    visited.reset();
    int totW = 0;
    // cout << a << " " << b << " " << graph[ a ][ b ] << endl;
    totW += graph[ a ][ b ];
    fres = true;
    res.clear();
    re( a , b  );
    fres = false;
    /*
    // cout << a <<  " "<< b << endl;
    // cout << "hola" << endl;
    int may = -1, tt = 0;
    for( int i = 0 ; i < n ; ++i )
    {
      temp = i;
      if( ! visited[ i ] )
      {

        temp = re( i , b );
      // cout << temp << endl;
      // totW += 2*graph[ i ][ temp ];
      // ff[ temp ] = max( ff[ temp ] , 2*graph[ i ][ temp ] );
      // may = max( may , graph[ i ][ temp ] + min(graph[ i ][ temp ] , graph[ i ][ b ] ) );
        tt = graph[ i ][ b ] - graph[ temp ][ b ];
        if ( tt < 0 )
          tt = 0;
        cout << "hk "<< tt << " i " << i  << " " << graph[ i ][ b ] << " " << graph[ temp ][ b ] << " temp " << temp<< endl;
        may = max( may , graph[ i ][ temp ] + ( min ( graph[ i ][ temp ] , tt )));
      }
      // cout << totW << endl;
    }
    */
    int may = 0, temp = 0  ;
    for( int i = 0; i < n ; ++i )
    {
      if( !visited[ i ] )
      {
        temp = INF;
        for( int j = 0 ; j < res.size() ; ++j )
        {
          int tt ;
          tt = graph[ i ][ b ] - graph[ res[ j ] ][ b ];
          if( tt < 0 )
            tt = 0;
          temp = min( temp , graph[ i ][ res[ j ] ] + min( graph[ i ][ res [ j ] ] , tt ));
        }
        may = max( may , temp );
      }
      // cout << "llegue" << endl;
    }
    totW += may;
    printf("Case %d: %d\n",++c,totW );
  }
  return 0;
}
