#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define MAX 200
#define INF 1e9


vector< vector< int > > g;
int p[ MAX ];
int f[ MAX ][ MAX ];
int SOURCE , SINK;

bool bfs()
{
  memset( p , -1 , sizeof p );
  queue< int > q;
	q.push( SOURCE );
  p[ SOURCE ] = -2;
	int u , v;
  while( !q.empty() )
  {
    u = q.front() ; q.pop();
//	cout << u << "\n";
    if( u == SINK )
      return true;
    for( int i = 0 ; i < g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
	//cout << "v " << v << "\n";
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
	for( int now = SINK , father = p[ SINK ] ; father != -2 ; now = father , father = p[ now ] )
	{
//		cout << now << " " << father << "\n";
		men = min( men , f[ father ][ now ] );
	}
	for( int now = SINK, father = p[ SINK ] ; father != -2 ; now = father , father = p[ now ] )
	{
		f[ father ][ now ] -= men;
		f[ now ][ father ] += men;
  	}
	flow += men;
//	cout << men << "\n";
  }
	return flow;
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
  int n;
	int c;
	int u , v , ff;
	int cont = 0;
	while( cin >> n && n )
	{
    // if( cont != 0 )
		memset( f , 0 , sizeof f );
		g.assign( MAX , vector< int >() );
		cin >> SOURCE >> SINK >> c;
	//	cout << SOURCE << " " << SINK  << " " << c << "\n" << c << "\n";
		while( c-- )
		{
			cin >> u >> v >> ff;
	//		cout << u << " "  << v << "\n";
			g[ u ].push_back( v );
			g[ v ].push_back( u );
			f[ u ][ v ] += ff;
			f[ v ][ u ] += ff;
		}
		cout << "Network " << ++cont << "\n";
		cout << "The bandwidth is " << flujo() << ".\n";
    cout << "\n";
	}
}
