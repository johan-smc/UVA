#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>


using namespace std;
#define MAX 205

int v,e,ff,tt;
std::vector< std::vector<int> > graph;
bitset< MAX > visited;
bitset< MAX > color;


int bfs( int n )
{
  int now,next;
  queue< int > q;
  q.push( n );
  visited[ n ] = true;
  color[ n ] = false;
  ff = tt = 0;
  ++ff;
  while( !q.empty() )
  {
    now = q.front() ; q.pop();
    // cout << "entre " << now << endl;
    // cout << color << endl;
    for( int i = 0; i < graph[ now ].size() ; ++i )
    {
      next = graph[ now ][ i ];
      if( now == next )
        continue;
      if( !visited[ next ] )
      {
        // cout << "cambie " << now << " " << next << endl;
        q.push( next );
        visited[ next ] = 1;
        color[ next ] = ~color[ now ];
        if( !color[next] )
          ++ff;
        else
          ++tt;
      }
      else if( color[ now ] == color[ next ] ){
        // cout << now << " " << next << " " << color[ now ] << " " << color[ next ] << endl;
        return -1;
      }
    }
  }
  if( !tt )
    return ff;
  return min( ff , tt );
}


int main()
{
  int t,a,b;
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d %d",&v,&e);
    graph.assign( v , std::vector< int > () );
    for( int i = 0 ; i < e ; ++i )
    {
      scanf("%d  %d",&a,&b );
      graph[ a ].push_back( b );
      graph[ b ].push_back( a );
    }
    int res = 0,temp = 0;
    visited.reset();
    for( int i = 0 ; i < v && res != -1 ; ++i )
    {
      if( !visited[ i ] )
      {
        temp = bfs( i );
        res = temp == -1 ? -1 : res + temp;
      }
    }
    printf("%d\n", res );
  }
  return 0;
}
