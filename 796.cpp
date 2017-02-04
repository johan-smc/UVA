#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define UNVISITED -1

typedef pair< int , int > ii;

std::vector< std::vector<int> > graph;
std::vector<int> dfs_num,dfs_low,dfs_parent;
int dfsCont;
std::vector< ii > res;

void points( int u )
{
  dfs_num[ u ] = dfs_low[ u ] = dfsCont++;
  for( int i = 0 ; i < graph[ u ].size() ; ++i )
  {
    int v = graph[ u ][ i ];
    if( dfs_num[ v ] == UNVISITED )
    {
      dfs_parent[ v ] = u;
      //case
      points( v );
      //is vertex is articulation point
      if( dfs_low[ v ] > dfs_num[ u ])
        res.push_back((u<v)?ii(u,v):ii(v,u));
      dfs_low[ u ]= min(dfs_low[u],dfs_low[v]);
    }
    else if( v != dfs_parent[u])
      dfs_low[ u ] = min ( dfs_low[u ] , dfs_num[v]);
  }
}

int main()
{
  int n;
  int a , m,b;
  while( scanf("%d",&n )  != EOF )
  {
    graph.assign( n , std::vector<int>());
    dfs_num.assign( n , -1 );
    dfs_low.assign( n , -1 );
    dfs_parent.assign( n , -1 );
    res.clear();
    dfsCont = 0;
    for( int i = 0 ; i <  n; ++i )
    {
      scanf("%d (%d)",&a,&m );
      for( int j = 0 ; j < m ; ++j )
      {
        scanf("%d",&b );
        // cout << a << b<< endl;
        graph[ a ].push_back(b);
        // graph[ b ].push_back(a);
      }
    }
    for( int i = 0 ; i < n ; ++i )
      if( dfs_num[i] == UNVISITED )
      {
        points( i );
      }
    sort( res.begin(), res.end( ));
    printf("%d critical links\n", (int)res.size() );
    for( int i = 0 ; i < res.size() ; ++i )
      printf("%d - %d\n",res[i].first,res[i].second );
    printf("\n" );
  }
    return 0;
}
