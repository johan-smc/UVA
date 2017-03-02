#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <vector>
#include <queue>


using namespace std;

vector< vector< int > > graph;
int now,nex;

bool bfs( int n )
{
  queue< int > q;
  bitset< 2003 > pas;
  pas[ n ] = 1 ;
  q.push( n );
  while( !q.empty() )
  {
    now = q.front();q.pop();
    for( int i = 0 ; i < graph[ now ].size() ; ++i )
    {
      nex = graph[ now ][ i ];
      if( !pas[ nex ] ){
        pas[ nex ] = 1;
        q.push( nex );
      }
    }
  }
  for( int i = 0 ; i < n ; ++i )
    if( !pas[i] )
      return false;
  return true;

}

int main()
{
  int n,m,v,w,p;
  while( scanf("%d %d",&n,&m) , (n||m) )
  {
    graph.assign(n,vector< int >());
    for( int i = 0 ; i < m ; ++i )
    {
      scanf("%d %d %d",&v,&w,&p );
      --v;
      --w;
      --p;
      graph[ v ].push_back( w );
      if( p )
        graph[ w ].push_back( v );
    }
    bool is=1;
    for( int i = 0 ; i < n && is ; is = bfs( i ) , ++i );
    printf("%d\n",(int)is );
  }
  return  0;
}
