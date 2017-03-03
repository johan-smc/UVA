#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
#define MAX 100001
#define UNVISITED -1

int n,m;
// queue< int > cicle;
vector< vector< int > > graph,graph2;
int dfs_num[ MAX ], dfs_low[ MAX ],dfsNum,numSCC;
bitset< MAX > visited,vv;
vector< int > S;
bitset< MAX > topo;
int otherGraph[ MAX ];

void bfs( int u )
{
  queue< int > q;
  q.push( u );
  vv[ u ] = 1;
  int now,next;
  while( !q.empty() )
  {
    now = q.front(); q.pop();
    for( int i = 0; i < graph2[ now ].size() ; ++i )
    {
      next = graph2[ now ][ i ];
      if( !vv[ next ] )
      {
        vv[ next ] = 1;
        q.push( next );
      }
    }
  }
}

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
  if( dfs_num[ u ] == dfs_low[ u ] )
  {
    // int cont = 0;
    while ( 1 ) {
      // ++cont;
      int v = S.back() ; S.pop_back();
      otherGraph[ v ] = numSCC;
      visited[ v ] = 0;
      if( u == v ) break;
    }
    // if( cont > 1 )
    //   cicle.push( numSCC );
    ++numSCC;
  }
}

int main()
{
  int t;
  int a,b;
  scanf("%d\n",&t );
  while( t-- )
  {
    scanf("%d %d",&n,&m);
    graph.assign( n , vector< int >() );
    S.clear();
    visited.reset();
    memset( dfs_num , UNVISITED , sizeof dfs_num );
    memset( dfs_low , 0 , sizeof dfs_low );
    memset( otherGraph , -1 , sizeof otherGraph );
    dfsNum = numSCC = 0;
    topo.reset();
    vv.reset();
    for( int i = 0; i < m ;++i )
    {
      scanf("%d %d",&a,&b);
      --a;
      --b;
      graph[ a ].push_back( b );
    }
    for( int i = 0; i < n ; ++i )
      if( dfs_num[ i ] == UNVISITED )
        tarjanSCC( i );
    graph2.assign( numSCC , vector< int > () );
    for( int i = 0; i < n ; ++i )
    {
      a = otherGraph[ i ];
      for( int j = 0 ; j < graph[ i ].size() ; ++j )
      {
        b = otherGraph[ graph[i][j] ];
        if( a != b )
        {
          graph2[ a ].push_back( b );
          topo[ b ] = 1;
        }
      }
    }
    int top = 0;
    for( int i = 0 ; i < numSCC ; ++i )
      if( !topo[ i ] )
      {
        ++top;
        bfs( i );
      }
    // while ( !cicle.empty() ) {
    //   if( !vv[ cicle.front() ] )
    //   {
    //
    //    bfs( cicle.front() );
    //    ++top;
    //  }
    //   cicle.pop();
    // }
    // for( int i = 0 ; i < numSCC ; ++i )
    //   if( !vv[ i ] )
    //     ++top;

    printf("%d\n",  top );
  }
  return 0;
}
