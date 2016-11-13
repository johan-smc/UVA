#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

string word[ 101 ];
map< string , int > mapa;
std::vector< std::vector<int> > graph;
queue< string > imp;
bool pas[ 102 ];
int ini[ 101];
int n,m,now;

void bfs()
{
  int next;
  priority_queue < int , std::vector<int> , greater<int> > q;
  memset( pas , 0 , sizeof pas );
  for( int i = 0 ; i < n ; ++i ){
    sort( graph[i].begin() , graph[i].end() );
    if( !ini[ i ] )
    {
      q.push( i );
      // imp.push( word[i] );
    }
  }
  while( !q.empty() )
  {
    now = q.top(); q.pop();
    imp.push( word[now] );
    // cout << now << endl;
    for( int i = 0 ; i < graph[now].size() ; ++i )
    {
      next = graph[ now ][ i ];
      --ini[ next ];
      if( !pas[ next ] && !ini[ next ])
      {
        pas[ next ] = true;
        q.push( next );
      }
    }
    // cout << now << " " << word[ now ] << endl;
    // for( int i = 0 ; i < n ; ++i )
    //   cout << ini[ i ] << " ";
    // cout << endl;
  }
}

int main()
{
  int c = 0 ;
  char B1[ 60 ],B2[ 60 ];
  string b1,b2;
  while( scanf("%d",&n )!=EOF )
  {
    mapa.clear();
    graph.assign( n , std::vector<int> () );
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%s",B1 );
      b1.assign(B1);
      mapa[ b1 ] = i;
      word[ i ] = b1;
    }
    scanf("%d",&m );
    memset( ini , 0 , sizeof ini );
    for( int i = 0 ; i < m ; ++i )
    {
      scanf("%s %s",B1,B2 );
      b1.assign(B1);
      b2.assign(B2);
      // cout << b1 << " " << b2 << endl;
      // cout << "imprimir" << endl;
      int aa,bb;
      aa = mapa[ b1 ];
      bb = mapa[ b2 ];
      // cout << aa << " " << bb << endl;
      graph[ aa ].push_back(bb) ;
      ++ini[ bb ] ;
      // cout << "vu" << endl;
    }
    while( !imp.empty() ) imp.pop();
    bfs();
    printf("Case #%d: Dilbert should drink beverages in this order:",++c );
    while( !imp.empty() )
    {
      printf(" %s", imp.front().c_str() );
      imp.pop();
    }
    printf(".\n\n" );
  }
  return 0;
}
