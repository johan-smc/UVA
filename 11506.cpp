#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAX 200
#define INF 1e9
#define INI 1
#define SECOND 60

vector < vector< int >  > g;
int f[ MAX ][ MAX ];
int p[ MAX ];
int FIN;

bool bfs()
{
  memset( p , -1 , sizeof p );
  queue< int > q;
  q.push( INI );
  p[ INI ] = -2;
  int u,v;
  while( !q.empty() )
  {
    u = q.front();
    p.pop();
    if( u == FIN )
      return true;
    for( int i = 0; i < g[ u ].size() ; ++i )
    {
      v=  g[ u ][ i ];
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
    for( int now = FIN , father = p[ father ] ; father != -1 ; now = father , father = p[ now ])
    {
      men = min( men , f[ father ][ now ] );
    }
    for( int now = FIN , father = p[ father ] ; father != -1 ; now = father , father = p[ now ])
    {
      f[ father ][ now ] -= men;
      f[ now ][ father ] += men;
    }
    flow += men;
  }
  return flow;
}

int main()
{
  int m ,w ;
  int u,v,ff;
  while( cin >> m >> w && ( m || w ) )
  {
    FIN = m;
    memset( f , 0 , sizeof f );
    g.assign( MAX ,vector< int >() );
    for( int i = 0; i < m-2 ; ++i )
    {
      cin >> u >> v;
      g[ u ].push_back( u+SECOND );
      g[ u+SECOND ].push_back( u );
      f[ u ][ u+SECOND ] = v;
    }
    for( int i = 0 ; i < w ; ++i )
    {
      cin >> u >> v >> ff;
      if( u == 1 )
      {
        g[ u ].push_back( v );
        g[ v ].push_back( u );
        f[ u ][ v ] += ff;
      }
      else if( v == m )
      {
        g[ u+SECOND ].push_back( v );
        g[ v ].push_back( u+SECOND );
        f[ u+SECOND ][ v ] += ff;

      }
      else
      {
        g[ u+SECOND ].push_back( v+SECOND );
        g[ v+SECOND ].push_back( u+SECOND );
        f[ u+SECOND ][ v+SECOND ] += ff;
      }
    }
    cout << flujo() << "\n";
  }
  return 0;
}
