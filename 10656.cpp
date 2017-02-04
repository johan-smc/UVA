#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
/*
struct Data
{
  int tot;
  int lon;
  int pos;
  queue< int > q;
  bool operator<( const Data &o )const
  {
    if( this->tot == o.tot )
    {
      if( this->lon == o.lon )
        return this->pos < o.pos;

      return this->lon < o.lon;

    }
    return this->tot < o.tot;
  }
};

int main()
{
  int n,k;
  while (scanf("%d",&n ) , n )
  {
    std::vector< Data > v;
    Data dt;
    dt.pos = dt.lon = dt.tot = 0;
    dt.q = queue< int > ();
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", &k );
      if( k == 0 )
      {
        v.push_back(dt);
        ++dt.pos ;
        dt.lon = dt.tot = 0;
        dt.q = queue< int > ();
      }
      else
      {
        dt.tot -= k;
        ++dt.lon;
        dt.q.push(k);
      }
    }
    v.push_back(dt);
    sort( v.begin() , v.end() );
    for( int i = 0 ; i < v[0].lon ; ++i )
    {
        if( i != 0 )
          printf(" ");
        printf("%d", v[0].q.front() );
        v[0].q.pop();
    }
    printf("\n");
  }
  return 0;
}
*/
int main()
{
  int n,k;
  while( scanf("%d", &n ) , n )
  {
    std::vector<int> v;
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", &k );
      if( k != 0 )
        v.push_back(k);

    }
    // while( (int)v.size() > 0 && v[ v.size() -1 ] == 0 )v.pop_back();
    for( int i = 0 ; i < v.size() ; ++i )
    {
      if( i != 0 )
        printf(" ");
      printf("%d",v[ i ] );
    }
    if( v.size() == 0 )
      printf("0" );
    printf("\n" );
  }
  return 0;
}
