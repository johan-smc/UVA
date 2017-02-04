#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define MAX 10001

int n,pos;
int nums[ MAX ];

int findMen( std::vector< std::vector< int > > v )
{
  int men = 1<<28 , pos = -1 ;
  for( int i = 0 ; i < v.size() ; ++i )
  {
    if( men > v[ i ].size() )
    {
      men = v[ i ].size();
      pos = i;
    }
  }
  return pos;
}

int main()
{
  int c = 0;
  int may = 0;
  while ( scanf("%d",&n ) , n )
  {
    if( c++ != 0 )
      printf("\n" );
    map< int , int > mp;
    may = 0;
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d",&nums[ i ] );
      may = max ( may , ++mp[ nums[ i ] ] );
      // cout << may << " " << nums[ i ] << endl;

    }
    std::vector< std::vector< int > > v(may,std::vector<int> ());
    map< int , int >::iterator it;
    for( it = mp.begin() ; it != mp.end() ; ++it )
    {
      // cout << it->first << " " << it->second << endl;
      /*
      if( it->second >= v.size() )
      {
        for( int i = 0; i < v.size() ; ++i )
          v[ i ].push_back( it->first );
        for( int i = v.size() ; i < it->second  ; ++i )
        {
          v.push_back( std::vector<int>() );
          v[ i ].push_back( it->first );
        }
      }
      else
      {
      */
        int men = findMen( v );
        for( int i = 0 ; i < it->second ; ++i )
        {
          v[ men++ ].push_back( it->first );
          men %= v.size();
        }
      // }
    }
    printf("%d\n",(int)v.size() );
    for( int i = 0 ; i < v.size() ; ++i )
    {
      for( int j = 0 ; j < v[ i ].size() ; ++j )
      {
        if( j != 0 )
          printf(" ");
        printf("%d",v[ i ][ j ] );
      }
      printf("\n");
    }

  }
  return 0;
}
