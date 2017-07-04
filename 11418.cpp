#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <set>

using namespace std;
#define MAX 100
#define INF 1e9
#define INI 1
#define FIN 2

typedef pair< int , int > ii;

vector< vector< int > > g;
set< int > con;
int f[ MAX ][ MAX ];
int p[ MAX ];
bool visited[ MAX ];
vector< ii > res;

bool bfs()
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
    for( int i = 0;  i < (int)g[ u ].size() ; ++i )
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

void bfsa()
{
  con.clear();
  memset( visited , 0 , sizeof visited );
  queue< int > q;
  q.push( INI );
  visited[ INI ] = 1;
  int u ,v;
  con.insert(INI);
  while( !q.empty() )
  {
    u = q.front();
    q.pop();
    for( int i = 0; i < (int)g[ u ].size() ; ++i )
    {
       v = g[ u ][ i ];
      if( !visited[ v ] && f[ u ][ v ] > 0 )
      {
        q.push( v );
        visited[ v ] = 1;
        con.insert(v);
      }
    }
  }

}

void bfsU( int u )
{
  memset( visited , 0 , sizeof visited );
  queue< int > q;
  q.push( u );
  visited[ u ] = 1;
  int v;
  while( !q.empty() )
  {
    u = q.front();
    q.pop();
    for( int i = 0; i < (int)g[ u ].size() ; ++i )
    {
       v = g[ u ][ i ];
      if( !visited[ v ] && f[ u ][ v ] == 0 && con.find( v ) == con.end() )
      {
        res.push_back( ii(u,v) );
      }
    }
  }
}

void arist()
{
  res.clear();
  bfsa();
  set<int>::iterator it;
  for( it = con.begin(); it != con.end() ; ++it  )
  {
    bfsU( *it );
  }
}

int main()
{
  int n, m;
  int u , v,ff;
  while( cin >> n >> m && ( n|| m ) )
  {
    memset( f , 0 , sizeof f );
    g.assign( MAX , vector< int >() );
    for( int i = 0 ; i < m ;++i )
    {
      cin >> u >> v >> ff;
      g[ u ].push_back( v );
      g[ v ].push_back( u );
      f[ u ][ v ] += ff;
      f[ v ][ u ] += ff;
    }
    flujo() ;
    arist();
    for( int i = 0;  i < (int)res.size() ; ++i )
    {
      cout << res[ i ].first << " " << res[ i ].second << "\n";
    }
    cout << "\n";
  }
  return 0;
}
