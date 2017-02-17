#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <map>

using namespace std;
#define MAX 26
#define UNVISITED -1

int dfsNum,oNum;
int dfs_low[ MAX ], dfs_num[ MAX ];
int otherGraph[ MAX ];

bitset< MAX > visited;
std::vector<int> S;
string names[ MAX ];
std::vector< std::vector<int> > graph;
 std::vector< std::vector<int>  >  res;

void tarjanSCC( int u )
{
  dfs_low[ u ]  = dfs_num[ u ] = dfsNum++;
  S.push_back( u );
  visited[ u ] = 1;
  for( int i = 0 ; i < graph[ u ].size() ; ++i )
  {
    int v = graph[ u ][ i ];
    if( dfs_num[ v ] == UNVISITED )
      tarjanSCC( v );
    if( visited[ v ] )
      dfs_low[ u ] = min( dfs_low[ u ], dfs_low[ v ] );
  }
  if( dfs_low[ u ] == dfs_num[ u ] )
  {
    res.push_back(std::vector<int>());
    while( 1 )
    {
      int v = S.back(); S.pop_back();
      cout << v << " " ;
      res[ oNum ].push_back( v );
      otherGraph[ v ] = oNum;
      visited[ v ] = 0 ;
      if( u == v ) break;
    }
    cout << endl;
    ++oNum;
  }
}

int main()
{
  int n,m,c;
  c = 0;
  while( cin >> n >> m , (n||m) )
  {
    if( c != 0 )
      cout << "\n";
    int num ;
    map< string , int > mp;
    graph.assign( n , std::vector<int>());
    visited.reset();
    res.clear();
    S.clear();
    memset( dfs_low , -1 , sizeof dfs_low );
    memset( dfs_num , -1 , sizeof dfs_num );
    memset( otherGraph , -1 , sizeof otherGraph );
      num = oNum = dfsNum = 0;
      string a,b;
      for( int i = 0 ; i < m ; ++i )
      {
        cin >> a >> b;
        if( mp.find( a ) == mp.end() )
        {
          names[ num ] = a;
          mp[ a ] = num++;
        }
        if( mp.find( b ) == mp.end() )
        {

          names[ num ] = b;
          mp[ b ] = num++;
        }
        graph[ mp[ a ] ].push_back( mp[ b ] );
      }
      // cout << num << endl;
      for( int i = 0 ; i < n ; ++i )
        if( !visited[ i ] )
          tarjanSCC( i );
      // for( int i = 0 ; i < S.size() ; ++i )
      //     cout << S[ i ] << " ";
      // cout << endl;
      std::vector<int> temp(1);

      for( int i = 0; i < n ; ++i )
        if( otherGraph[ i ] == -1 )
        {
          temp[0] = i;
          res.push_back( temp );
          otherGraph[ i ] = oNum++;
        }

          // cout << "hi\n";
      for( int i = 0 ; i <  n; ++i )
        cout << otherGraph[ i ] << " ";
      cout << "Calling circles for data set " << ++c << ":\n";
      int nn;
      for( int i = 0 ; i <  n ; ++i )
      {
          if( otherGraph[ i ] != -1 )
          {
            int now = otherGraph[ i ];
            // cout << now << " " << res[ now ].size() << endl;
            for( int j = 0 ; j < res[ now ].size() ; ++j )
            {
              nn = res[ now ][ j ];
              otherGraph[ nn ] = -1;
              if( j != 0 )
                cout << ", ";
              cout << names[ nn ] ;
            }
            cout << "\n";

          }
      }


  }
  return 0;
}
