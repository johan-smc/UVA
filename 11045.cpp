#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define INF 1e9
#define MAX 200
#define INI 0
#define FIN 190
#define FIRST 1
#define SECOND 10

vector< vector< int > > g;
int f[ MAX ][ MAX ];
int p[ MAX ];

bool bfs()
{
  memset( p , -1 , sizeof p );
  queue< int > q;
  q.push(INI);
  p[ INI ] = -2;
  int u,v;
  while( !q.empty() )
  {
    u = q.front() ; q.pop();
    if( u == FIN )
      return true;
    for( int i = 0; i < (int)g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      if( p[ v ] == -1 && f[ u ][ v ] > 0 )
      {
        q.push( v );
        p[ v ] = u;
      }
    }
  }
  return false;
}


int flujo()
{
  int flow = 0;
  while( bfs() )
  {
    int men = INF;
    for( int now = FIN , father = p[ now ] ; father != -2 ; now = father , father = p[ now ] )
    {
      men = min( men , f[ father ][ now ] );
    }
    for( int now = FIN , father = p[ now ] ; father != -2 ; now = father , father = p[ now ] )
    {
      f[ father ][ now ] -= men;
      f[ now ][ father ] += men;
    }
    flow += men;
  }
  return flow;
}

map< string , int > cc;
int main()
{
  cc[ "XS" ] = 0;
  cc[ "S" ] = 1;
  cc[ "M" ] = 2;
  cc[ "L" ] = 3;
  cc[ "XL" ] = 4;
  cc[ "XXL" ] = 5;
  int t;
  cin >> t;
  int n , m;
  string a,b;
  while( t-- )
  {
    memset( f , 0 , sizeof f );
    g.assign( MAX , vector< int >() );
    cin >> n  >> m ;
    n/=6;
    for( int i = 0 ; i < 6 ;++i )
    {
      g[ INI ].push_back( FIRST + i );
      g[ FIRST + i ].push_back( INI );
      f[ INI ][ FIRST + i ] = n;
    }
    for( int i = 0 ; i  <  m ; ++i )
    {
      cin >> a >> b;
      g[ FIRST + cc[a] ].push_back( i + SECOND );
      g[ i+SECOND ].push_back( FIRST + cc[ a ] );
      f[ FIRST + cc[a] ][ i + SECOND ] = 1;

      g[ FIRST + cc[b] ].push_back( i + SECOND );
      g[ i+SECOND ].push_back( FIRST + cc[b] );
      f[ FIRST + cc[b] ][ i + SECOND ] = 1;

      g[ i + SECOND ].push_back( FIN );
      g[ FIN ].push_back( i + SECOND );
      f[ i + SECOND ][ FIN ] = 1;

    }
    if( flujo() == m )
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
