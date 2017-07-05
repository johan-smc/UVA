#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9
#define MAX 300
#define INI 0
#define FIN 290
#define SECOND 110

vector< vector< int > > g;
int f[ MAX ][ MAX ];
int p[ MAX ];

bool bfs()
{
  memset( p , -1 , sizeof p );
  queue< int > q;
  q.push( INI );
  p[ INI ] = -2;
  int u , v;
  while( !q.empty() )
  {
    u = q.front() ; q.pop();
    if( u == FIN )
      return true;
    for( int i = 0 ; i < (int)g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      if( p[ v ] == -1 && f[ u ][ v] > 0 )
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
    for( int v = FIN , u = p[ v ] ; u != -2 ; v = u , u = p[ v ] )
    {
      men = min ( men , f[ u ][ v ] );
    }
    for( int v = FIN , u = p[ v ] ; u != -2 ; v = u , u = p[ v ] )
    {
      f[ u ][ v ] -= men;
      f[ v ][ u ] += men;
    }
    flow += men;
  }
  return flow;
}

int main()
{
  int n;
  int ff;
  int u , v;
  int w;
  int a, b;
  while ( cin >> n )
  {
    memset( f , 0 , sizeof f );
    g.assign( MAX , vector<int>() );
    for( int i = 1 ; i <= n ;++i )
    {
      cin >> ff;
      g[ i ].push_back( i+SECOND );
      g[ i+SECOND ].push_back( i );
      f[ i ][ i+SECOND ] += ff;
    }
    cin >> w;
    for( int i = 0 ; i < w ; ++i )
    {
      cin >> u >> v >> ff;
      g[ u+SECOND ].push_back( v );
      g[ v ].push_back( u+SECOND );
      g[ v+SECOND ].push_back( u );
      g[ u ].push_back( v+SECOND );
      f[ u+SECOND ][ v ] +=ff ;
    }
    cin >> a >> b;
    for( int i = 0  ; i < a ; ++i )
    {
      cin >> u;
      g[ INI ].push_back( u );
      g[ u+SECOND ].push_back( INI );
      f[ INI ][ u ] = INF;
    }
    for( int i = 0  ; i < b ; ++i )
    {
      cin >> u;
      g[ u+SECOND ].push_back( FIN );
      g[ FIN ].push_back( u );
      f[ u+SECOND ][ FIN ] = INF;
    }
    cout << flujo() << "\n";
  }

    return 0;
}
