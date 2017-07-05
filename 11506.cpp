#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX 200
#define INF 1<<30
#define INI 1
#define SECOND 60

vector < vector< int >  > g;
int f[ MAX ][ MAX ];
int p[ MAX ];
bool vi[ MAX ];
int FIN;

bool bfs()
{
  memset( p , -1 , sizeof p  );
  queue< int >q;
  q.push( INI );
  p[ INI ] = -2;
  int u , v ;
  while( !q.empty() )
  {
    u = q.front() ; q.pop();
    if( u == FIN )
      return true;
    for( int i = 0 ; i < (int)g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      if( p[ v ] == -1 && f[ u ][ v ] > 0 )
      {
        // cout << "GO "<<u << " " << v << "\n";
        q.push(v );
        p[ v ] = u;
      }
    }
  }
  return false;
}

int flujo( )
{
  int flow = 0;
  while( bfs( ) )
  {
    int men = INF;
    for( int now  = FIN , father = p[ now ] ; father != -2 ; now = father , father = p[ now ] )
    {
      men = min( men , f[ father ][ now ] );
    }
    for( int now  = FIN , father = p[ now ] ; father != -2 ; now = father , father = p[ now ] )
    {
      // cout << father << " " << now << " " << f[ father ][ now ] << "\n";

      f[ father ][ now ] -= men;
      f[ now ][ father ] += men;
    }
    flow += men;
    // cout << " ans " << flow << "\n";
  }
  return flow;
}


int main()
{
  int m , w , u , v  , ff;
  while( cin >> m >> w && ( m || w ) )
  {
    FIN = m + SECOND;
    memset( f , 0 , sizeof f );
    g.assign( MAX , vector< int >() );
    g[ INI ].push_back( INI+SECOND );
    g[ INI+SECOND ].push_back( INI );
    f[ INI ][ INI+SECOND ] = INF;
    g[ m ].push_back( m+SECOND );
    g[ m+SECOND ].push_back( m );
    f[ m ][ m+SECOND ] = INF;
    for( int i = 0; i < m-2 ; ++i )
    {
      cin >> u >> ff;
      g[ u ].push_back( u +SECOND );
      g[ u+SECOND ].push_back( u );
      f[ u ][ u+SECOND ]  += ff;
    }
    for( int i = 0; i < w ; ++i )
    {
      cin >> u >> v >>ff;
      g[ u+SECOND ].push_back( v );
      g[ v ].push_back( u+SECOND );
      g[ v+SECOND ].push_back( u );
      g[ u ].push_back( v+SECOND );
      f[ u+SECOND ][ v ] += ff;
      f[ v+SECOND ][ u ] += ff;
    }
    cout << flujo() << "\n";
  }
  return 0;
}
