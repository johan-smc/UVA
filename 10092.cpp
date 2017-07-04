#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
#define MAX 1500
#define INF 1e9
#define INI 0
#define FIN 1450
#define FIRST 1
#define SECOND 30


vector< vector< int > > g;
int f[ MAX ][ MAX ];
int p[ MAX ] ;

bool bfs( )
{
  memset( p , -1 , sizeof p );
  queue< int > q;
  q.push( INI );
  p[ INI ] = -2;
  int u , v;
  while( !q.empty() )
  {
    u = q.front();
    q.pop();
    if( u == FIN )
      return true;
    for( int i = 0 ; i < g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      if( p[ v ] == -1 && f[ u ][ v ] > 0 )
      {
        q.push( v ) ;
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
int main()
{
  int k , p , ff , t , tot , v , u ,cont ;
  while( cin >> k >> p && ( k || p ) )
  {
    memset( f , 0 , sizeof f ) ;
    g.assign( MAX , vector< int > () );
    tot = 0;
    for( int i = 0  ; i < k ; ++i )
    {
      g[ INI ].push_back( i + FIRST );
      g[ i + FIRST ].push_back( INI );
      cin >> ff;
      f[ INI ][ i + FIRST ] = ff ;
      tot += ff;
    }
    for( int i = 0; i < p ; ++i )
    {
      cin >> t;
      while( t-- )
      {
        cin >> ff;
        g[ ff ].push_back( i + SECOND );
        g[ i + SECOND ].push_back( ff );
        f[ ff ][ i + SECOND ] = 1;
      }

      g[ i + SECOND ].push_back( FIN );
      g[ FIN ].push_back( i + SECOND );
      f[ i + SECOND ][ FIN ] = 1;
    }
    if( flujo() == tot )
    {
      cout << "1\n";
      for( int i = 0; i  < k ; ++i )
      {
        u = i+FIRST;
        cont = 0;
        for( int j = 0 ; j < g[ u ].size() ; ++j )
        {
          v = g[ u ][ j ];
          if( f[ u ][ v ] == 0 && f[ v ][ u ] > 0 )
          {
            if( cont++ )
              cout << " ";
            cout << v-SECOND+1;
          }
        }
        cout << "\n";
      }
    }
    else
      cout << "0\n";
  }
  return 0;
}
