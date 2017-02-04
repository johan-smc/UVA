#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 10001
#define UNVISITED -1

typedef pair< int , int >  ii ;

int dfs_low[ MAX ],dfs_num[ MAX ],dfs_parent[ MAX ];
std::vector< ii >  isPoint;
int dfsCont,dfsRoot,rootChildren;
std::vector< std::vector<int> > graph;

void point( int u )
{
  // cout << "hello "<< u << endl;
  dfs_low[ u ] = dfs_num[ u ] = dfsCont++;
  for( int i = 0 ; i < graph[ u ].size() ; ++i )
  {
    int v = graph[ u ][ i ];
    // cout << v << " -- " << endl;
    if( dfs_num[ v ] == UNVISITED )
    {
      // cout << "1"<< endl;
      dfs_parent[ v ] = u;
      if( dfsRoot == u )
        ++rootChildren;
      point( v );
      if( dfs_low[ v ] >= dfs_num[ u ] )
      {
        // cout << "entre " << isPoint[ u ].first << " ";
        ++isPoint[ u ].first;
        // cout << isPoint[ u ].first << endl;
      }
      // if( dfs_low[ v ] > dfs_num[ u ] )
      // {
      //   cout <<"wed "<< u << " " <<v << "   " << endl;
      //   ++isPoint[ v ].first;
      //   ++isPoint[ u ].first;
      //
      // }
      dfs_low[ u ] = min( dfs_low[ u ]  , dfs_low[ v ] );
    }
    else if( v != dfs_parent[u] )
    {

      // cout << "2"<< endl;
      dfs_low[ u ] = min( dfs_low[ u ] , dfs_num[ v ]);
    }
  }
}


int main()
{
  int n,m;
  while( scanf("%d %d",&n,&m ) , (n||m) )
  {
    dfsCont = 0;

    graph.assign(n,std::vector<int>());
    isPoint.assign(n,ii(0,0));
    memset( dfs_num , UNVISITED , sizeof dfs_num );
    memset( dfs_low , 0 , sizeof dfs_low );
    memset( dfs_parent , 0 , sizeof dfs_parent );
    int a,b;
    while( scanf("%d %d",&a,&b ) , ( a != -1 && b != -1 ) )
    {
      // cout << a << " " << b << " fds " << endl;
      graph[ a ].push_back( b );
      graph[ b ].push_back( a );
    }
    for( int i = 0 ; i< n ; ++i )
    {
      if( dfs_num[i] == UNVISITED )
      {
        dfsRoot = i;
        rootChildren = 0;
        point( i );
        // if( !(rootChildren > 1) )
          --isPoint[ i ].first;
      }
      isPoint[ i ].second = -i ;
    }
    // for( int i = 0 ; i < n ; ++i )
    // {
    //   cout << isPoint[ i ].first << " ";
    // }
    // cout << endl;
    sort( isPoint.begin() , isPoint.end() , greater<ii>() );
    for( int i = 0 ; i < m ; ++i )
    {
      printf("%d %d\n", -isPoint[i].second , isPoint[ i ].first+1);
    }
    printf("\n");
  }
  return 0;
}
