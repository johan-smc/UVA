#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>

using namespace std;
#define MAX 2005
#define UNVISITED -1

int dfsNum,dfs_low[ MAX ],dfs_num[ MAX ],SCCnum;
vector< vector< int > > graph;
vector< int > S;
bitset< MAX > visited;


void tarjanSCC( int u )
{
  dfs_num[ u ] = dfs_low[ u ] = dfsNum++;
  visited[ u ] = 1;
  S.push_back( u );
  for( int i = 0 ; i < graph[ u ].size() ; ++i )
  {
    int v = graph[ u ][ i ];
    if( dfs_num[ v ] == UNVISITED )
      tarjanSCC( v );
    if( visited[ v ] )
      dfs_low[ u ] = min( dfs_low[ u ] , dfs_low[ v ] );
  }
  if( dfs_low[ u ] == dfs_num[ u ] )
  {
    ++SCCnum;
    while( 1 )
    {
      int v = S.back(); s.pop_back();
      visited[ v ] = 0;
      if( v == u ) break;
    }
  }

}


int main()
{
  int n,m;
  int a,b,o;
  while( scanf("%d %d",&n,&m) , (n || m ) )
  {
    memset( dfs_num , UNVISITED , sizeof dfs_num );
    memset( dfs_low , 0 , sizeof dfs_low );
    visited.reset();
    S.clear();
    dfsNum = SCCnum = 0;
    graph.assing( n , vector< int > () );
    for( int i = 0 ; i < m ;++i )
    {
      scanf("%d %d %d",&a,&b,&o);
      --a;
      --b;
      graph[ a ].push_back( b );
      if( o == 2 )
        graph[ b ].push_back( a );
    }
    for( int i = 0 ; i < n ; ++i )
      if( dfs_num[ i ] == UNVISITED )
        tarjanSCC( i );
    printf("%d\n",(SCCnum==1) );
  }
  return 0;
}
