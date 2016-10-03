#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Ping
{
  pair< int , int > a,b;
};

int bfs( std::vector<std::vector<char> > &v,Ping &ping,pair< int , int > &llegada)
{
  map< pair< int , int > , pair< int , int > > pas;
  

}

int main()
{
  int x,y;
  while( scanf("%d%d",&x,&y) != EOF )
  {
    Ping ping;
    pair< int , int > llegada;
    scanf("%d%d%d%d%d%d",&llegada.first,&llegada.second,&ping.b.first,&ping.b.second,&ping.a.first,&ping.a.second );
    std::vector< std::vector< char  > > v(x,std::vector<char> (y));
    for( int i = 0 ; i < x ; ++i )
    {
      for( int j = 0 ; j < y ; ++j )
      {
        scanf(" %c",&v[i][j] );
      }
    }

  }

  return 0;
}
