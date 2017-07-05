#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX 200
#define INF 1e9
#define INI 1
#define SECOND 60

vector < vector< int >  > g;
int f[ MAX ][ MAX ];
int cost[ MAX ][ MAX ];
int p[ MAX ];
bool vi[ MAX ];
int FIN;
set< int > con;

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
    q.pop();
    if( u == FIN )
      return true;
    for( int i = 0; i < (int)g[ u ].size() ; ++i )
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
    for( int now = FIN , father = p[ now ] ; father != -2 ; now = father , father = p[ now ])
    {
      men = min( men , f[ father ][ now ] );
    }
    for( int now = FIN , father = p[ now ] ; father != -2 ; now = father , father = p[ now ])
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
  memset( vi , 0 , sizeof vi );
  queue< int > q;
  q.push( INI );
  vi[ INI ] = 1;
  con.insert( INI );
  int u , v;
  while( !q.empty() )
  {
    u = q.front(); q.pop();
    for( int i = 0 ; i < (int)g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      if( !vi[ v ] && f[ u ][ v ] > 0 )
      {
        q.push( v );
        vi[ v ] = true;
        con.insert( v );
      }
    }
  }
}




int bfsR( int u )
{
  int tot = 0 ;
  queue< int > q;
  q.push( u );
  int  v;
  while( !q.empty() )
  {
    u = q.front(); q.pop();
    for( int i = 0 ; i < (int)g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      if(  f[ u ][ v ] == 0 && con.find( v ) == con.end() )
      {
        // cout << u << " " << v << "--\n";
        tot += cost[ u ][ v ];
      }
    }
  }
  return tot;
}

int arist()
{
  bfsa();
  set< int >::iterator it;
  int tot = 0;
  // cout << "INI\n";
  for( it = con.begin() ; it != con.end() ; ++it )
  {
    // cout << *it << "\n";
    tot += bfsR( *it );
  }
  return tot;
}

int main()
{
  int m ,w ;
  int u,v,ff,uu,vv;
  while( cin >> m >> w && ( m || w ) )
  {
    FIN = m;
    memset( f , 0 , sizeof f );
    memset( cost , 0 , sizeof cost );
    g.assign( MAX ,vector< int >() );
    for( int i = 0; i < m-2 ; ++i )
    {
      cin >> u >> v;
      g[ u ].push_back( u+SECOND );
      g[ u+SECOND ].push_back( u );
      f[ u ][ u+SECOND ] = v;
      cost[ u ][ u+SECOND ] = v;
      // f[ u+SECOND ][ u ] = v;
      // cost[ u+SECOND ][ u ] = v;
    }
    for( int i = 0 ; i < w ; ++i )
    {
      cin >> u >> v >> ff;
      // if( u == 1 )
      // {
      //   g[ u ].push_back( v );
      //   g[ v ].push_back( u );
      //   f[ u ][ v ] += ff;
      //   cost[ u ][ v ] += ff;
      //   f[ v ][ u ] += ff;
      //   cost[ v ][ u ] += ff;
      // }
      // else if( v == m )
      // {
      //   g[ u+SECOND ].push_back( v );
      //   g[ v ].push_back( u+SECOND );
      //   f[ u+SECOND ][ v ] += ff;
      //   cost[ u+SECOND ][ v ] += ff;
      //   f[ v ][ u+SECOND ] += ff;
      //   cost[ v ][ u+SECOND ] += ff;
      //
      // }
      // else
      // {
      //   g[ u+SECOND ].push_back( v+SECOND );
      //   g[ v+SECOND ].push_back( u+SECOND );
      //   f[ u+SECOND ][ v+SECOND ] += ff;
      //   cost[ u+SECOND ][ v+SECOND ] += ff;
      //   f[ v+SECOND ][ u+SECOND ] += ff;
      //   cost[ v+SECOND ][ u+SECOND ] += ff;
      // }
      if( u == 1 || u== m  )
        uu = u;
      else
        uu = u+SECOND;

      if( v == m || v == 1 )
        vv = v;
      else
        vv = v+SECOND;
      g[ uu ].push_back( v );
      g[ vv ].push_back( u );
      f[ uu ][ v ] += ff;
      cost[ uu ][ v ] += ff;
      f[ vv ][ u ] += ff;
      cost[ vv ][ u ] += ff;
    }
    flujo();
    cout << arist() << "\n";
  }
  return 0;
}
