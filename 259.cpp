#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
#define INF 1e9
#define MAX 110
#define INI 1
#define FIN 98
#define FIRST 2
#define SECOND 30

vector< vector< int > > g;
int p[ MAX ];
int f[ MAX ][ MAX ];
int tot ;

bool bfs( int u )
{
  memset( p , -1 , sizeof p );
  queue< int > q;
  q.push( u );
  p[ u ] = -2;
  int v;
  while( !q.empty() )
  {
    u = q.front(); q.pop();
    if( u == FIN )
      return true;
    for( int i = 0 ; i < g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      if( p[ v ] == -1 && f[ u ][ v ] > 0 )
      {
        p[ v ] = u;
        q.push( v );
      }
    }
  }
  return false;
}


int flujo()
{
  int flow = 0;
  while( bfs(INI) )
  {
    int men = INF;

    for(int now = FIN , father = p[ now ] ; p[now] != -2 ; now = p[ now ] , father = p[ now ] )
    {
      // cout << father << " " <<  now << " " << f[ father ][ now ] << "\n";
      men = min( men , f[ father ][ now ] );
    }
    for(int now = FIN , father = p[ now ] ; p[now] != -2 ; now = p[ now ] , father = p[ now ] )
    {
      f[ father ][ now ] -= men;
      f[ now ][ father ] += men;
    }
    // cout << men << " ---\n";
    flow += men;
  }
  // cout << flow << "\n";
  return flow;
}

void process( string& line )
{
  stringstream ss( line );
  char tipe ;
  int in;
  ss >> tipe >> in;
  tot += in;
  int pos = (tipe -'A')+FIRST;
  // cout << tipe <<" "<< in << " pos " << pos  << "\n";
  g[ INI ].push_back(  pos );
  g[ pos ].push_back( INI  );
  f[ INI ][ pos  ] = in;
  while( ss >> tipe && tipe != ';' )
  {
    in = tipe - '0';
    // cout << in << "\n";
    g[ pos ].push_back( in + SECOND );
    g[ in + SECOND ].push_back( pos );
    f[ pos ][ in + SECOND ] = 1;
  }

}

string pp()
{
  char arr[ 11 ];
  memset( arr , 0 , sizeof arr );
  int v,u;
  for( int i = 0  ; i < 26 ; ++i )
  {
    u = i+FIRST;
    for( int j = 0 ; j < g[ i + FIRST ].size() ; ++j )
    {
      v = g[ i+FIRST ] [ j ];
      if( f[ u ][ v ] == 0 && f[ v ][ u ] != 0 )
        arr[ v-SECOND ] = i+'A';
    }
  }
  for( int i = 0 ; i < 10 ; ++i )
    if( arr[ i ] == 0 )
      arr[ i ] = '_';
  arr[ 10 ] = '\0';
  // cout << arr << "\n";
  return string(arr);
}

int main()
{
  ios::sync_with_stdio( false );
  cin.tie( NULL );
  string line;
  while( getline( cin , line )  )
  {
    g.assign( MAX , vector< int >() );
    memset( f , 0 , sizeof f );
    tot = 0;
    process( line );
    while( getline( cin , line ) && line != "" )
    {
      process( line );
    }
    for( int i = 0 ; i < 10 ; ++i )
    {
      g[ i + SECOND ].push_back(FIN);
      g[ FIN  ].push_back( i+SECOND );
      f[ i + SECOND ][FIN] = 1;
    }
    if( flujo() != tot )
      cout << "!\n";
    else
      cout << pp() << "\n";
  }
  return 0;
}
