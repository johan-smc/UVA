#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite( std::vector< std::vector<int> > &graph , int* visited )
{
  queue< int > q;
  int now,next;
  for( int i = 0 ; i < graph.size() ; ++i )
  {
    if( visited[i] == -1)
    {
      q.push(i);
      visited[ i ] = 0;
      while( !q.empty( ) )
      {
        now = q.front();
        // cout << now << " " <<  visited[ now ] << endl;
        q.pop();
        for( int j = 0 ; j < graph[ now ].size() ; ++j )
        {
          next = graph[ now ][ j ];
          if( visited[next] == -1 )
          {
            visited[ next ] = (visited[now])?0:1;
            q.push( next );
          }
          else if( visited[ next ] == visited[ now ] )
            return false;
        }
      }
    }
  }
  return true;
}

int main()
{
  int v;
  int a,b;
  int visited[ 301 ];
  while( scanf("%d",&v ) , v )
  {
      memset( visited , -1 , sizeof visited );
      std::vector< std::vector< int > > graph(v,std::vector<int>());
      while( scanf("%d %d",&a,&b ) , (a||b) )
      {
        graph[ a -1  ].push_back( b - 1 );
        graph[ b - 1 ].push_back( a - 1 );
      }
      if( isBipartite( graph , visited ) )
        printf("YES\n");
      else
        printf("NO\n");
  }
  return 0;
}
