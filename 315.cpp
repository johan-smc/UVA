#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
#define MAX 101
#define UNVISITED -1
#define YES 1

int dfs_low[ MAX ],dfs_num[ MAX ];
int dfs_parent[ MAX ];
bool isVertexArticulation[ MAX ];
int dfsCont,dfsRoot,children;
std::vector< std::vector<int> > graph;

void points( int u ){
  dfs_low[ u ] = dfs_num[ u ] = dfsCont++;
  for( int i = 0 ; i < (int)graph[ u ].size() ; ++i )
  {
    int v = graph[ u ][ i ];
    if( dfs_num[ v ] == UNVISITED )
    {
      dfs_parent[ u ] = v;
      if( u == dfsRoot )
        ++children;

      points( v );

      if( dfs_low[ v ] >= dfs_num[ u ] )
        isVertexArticulation[ u ] = YES;
      //bridge
      dfs_low[ u ] = min( dfs_low[ u ], dfs_low[ v ] );
    }
    else if( v != dfs_parent[ u ] )
      dfs_low[ u ] = min( dfs_low[ u ] , dfs_num[ v ] );
  }
}

int main()
{
  int n;
  int a,b;
  while ( cin >> n , n )
  {
    graph.assign(n , std::vector<int>());
    memset( dfs_low , -1 ,sizeof dfs_low );
    memset( dfs_num , -1 ,sizeof dfs_num );
    memset( dfs_parent , -1 , sizeof dfs_parent );
    memset( isVertexArticulation , 0 , sizeof isVertexArticulation );
    dfsCont = 0;
    string line ;
    cin.ignore();
    while( getline( cin , line )  && line != "0" )
    {
      stringstream ss(line);
      ss >> a;
      --a;
      while( ss >> b )
      {
        --b;
        // cout << a << " " << b << endl;
        graph[ a ].push_back( b );
        graph[ b ].push_back( a );
      }

    }
    int cont = 0 ;
    for( int i = 0;  i< n ; ++i )
      if( dfs_num[ i ] == UNVISITED )
      {
        // cout << i << " n n " << endl;
        dfsRoot = i ; children = 0;
        points( i );
        isVertexArticulation[ i ] = ( children > 1 );
      }
    for( int i = 0;  i< n ; ++i )
      if( isVertexArticulation[i] )
        ++cont;
    cout << cont << '\n';
  }
    return 0;
}
