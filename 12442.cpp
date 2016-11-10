#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

bitset< 50005 > visited,complete;
vector< vector < int > > graph;
int n;

void bfs( int n )
{
  visited.reset();
  queue< int > q;
  q.push( n );
  visited[ n ] = 1;
  int now,next;
  while( !q.empty() )
  {
    now = q.front(); q.pop();
    for( int i = 0 ; i < graph[ now ].size() ; ++i )
    {
      next = graph[ now ][ i ];
      if( !visited[ next ] )
      {
        q.push( next );
        visited[ next ] = true;
      }
    }
  }
}

bool isTotalVisited()
{
  for( int i = 0 ;i < n ; ++i )
    if( !visited[ i ] )
      return false;
  return true;
}

int main()
{
  int t,a,b;
  scanf("%d",&t);
  for( int c = 0 ; c < t ; ++c )
  {
    scanf("%d",&n);
    graph.assign( n , std::vector<int>() );
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d%d",&a,&b );
      --a;
      --b;
      graph[ a ].push_back( b );
    }
    complete.reset();
    int count = 0,may = 0 , index = 0;
    for( int i = 0 ; i < n ; ++i )
    {
      if( !complete[i] )
      {
        bfs( i );
        count = visited.count();
        if( may < count ){
          may = count ;
          index = i;
        }

        complete |= visited;
      }
      /*for( int j = 0 ; j < n ; ++j )
        cout << complete[j] ;
      cout << endl << " nn " << endl;
      for( int j = 0 ; j < n ; ++j )
        cout << visited[j] ;
      cout << endl;*/
    }
    printf("Case %d: %d\n",c+1,index+1 );
  }
  return 0;
}
