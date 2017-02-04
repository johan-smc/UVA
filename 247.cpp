#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;
#define MAX 30
#define UNVISITED -1

std::vector< std::vector<int> > graph;
std::vector<int> S;
int dfs_num[ MAX ] , dfs_low[ MAX ], dfsCont;
bitset< MAX > visited;
queue< stack < int > > res;

void tarjanSCC( int u )
{
  dfs_num[ u ] = dfs_low[ u ] = dfsCont++;
  visited[ u ] = 1;
  S.push_back( u );
  for( int i = 0 ; i < graph[ u ].size( ) ; ++i )
  {
    int v = graph[ u ][ i ];
    // cout << "jajaj "<< u << " " << v << endl;
    if( dfs_num[ v ] == UNVISITED )
      tarjanSCC( v );
      // cout << "jaj" << endl;
    if( visited[v] )
      dfs_low[ u ]  = min( dfs_low[ u ] , dfs_low[ v ] );
  }
  if( dfs_low[ u ] == dfs_num[ u ] )
  {
    stack s;
    while( 1 )
    {
      int v = S.back();
      S.pop_back();
      s.push(v);
      if( u == v) break;
    }
    res.puhs(s);
  }
}

int main()
{
  int n,m,c=0;
  while( cin >> n >> m  , (n||m) )
  {
    set< pair< string, string > > rep;
    visited.reset();
    res.clear();
    int cont = dfsCont = 0 ;
    graph.assign( n , std::vector<int>() );
    S.clear();
    memset( dfs_num , UNVISITED , sizeof dfs_num );
    memset( dfs_low , 0 , sizeof dfs_low );
    map< string , int > mp;
    std::vector< string > names;
    string a,b;
    for( int i = 0 ; i < m ; ++i  )
    {
      cin >> a >> b;
      if( rep.find( make_pair( a,b ) ) != rep.end() )
        continue;
      if( mp.find(a) == mp.end() )
      {
        mp[ a ] = cont++;
        names.push_back( a );
      }
      if( mp.find(b) == mp.end() )
      {
        mp[ b ] = cont++;
        names.push_back( b );
      }
      graph[ mp[a] ].push_back( mp[b] );
    }
    // cout << " fsda----------" << endl;
    for( int i = 0 ; i < n ; ++i )
      if( dfs_num[ i ] == UNVISITED )
        tarjanSCC( i );
    // cout << " fsda f" << endl;
    // for( int i = 0 ; i < n ; ++i )
    // {
    //   cout << names[ i ] << " "<< dfs_num[ i ] << " " << dfs_low[ i ] << endl;
    // }
    while( !res.empty() )
    {
      stack< int > s = res.front();
      res.pop();
      while( !s.empty() )
      {
        int t = s.top();
        s.pop();
	cout << t;
	if( !s.empty() )
		cout << " , ";
      }
	cout << endl;
    }

    cout << "Calling circles for data set " << ++c << ":" << endl;

    cout << "\n\n" ;
  }
  return 0;
}
