#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Disjoint
{
private:
  vector< int  > root,rank;
public:
  Disjoint( int n )
  {
    root.resize( n );
    rank.resize( n );
    for( int i = 0 ; i < n ; ++i )
    {
      root[ i ] =  i;
    }
  }
  void union( int a , int b );

};

int main()
{
  int t;
  int n,r;
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d %d",&n ,&r);
    graph.assign( n , vector< int >());
    for( int  i = 0 ; i < r  ; ++i )
    {
      scanf("%d %d",&a,&b);
      graph[ a ].push_back( b );
      graph[ b ].push_back( a );
    }
  }
  return 0;
}
