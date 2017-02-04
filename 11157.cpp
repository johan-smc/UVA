#include <iostream>
#include <cstdio>
#include <cstring>
<<<<<<< HEAD

using namespace std;

int func( int d , std::vector<int> &v )
{
  int may = 0;
  for( int i = 0 ; i < v.size() ; ++i )
=======
#include <vector>

using namespace std;

int fun( std::vector< std::vector<int> > &v, std::vector<int> &vv)
{
  int may = 0;
  for( int i = 0 ; i < v.size() ; ++i )
  {
    int ant = vv[ i ];
    for( int j = 0 ; j < v[ i ].size( ) ; j+=2 )
    {
      may = max( may , v[ i ][ j ] - ant  );
      ant = v[ i ][ j ];
    }

    may = max( may , vv[ i+1 ] - ant  );
    ant = vv[ i ];
    for( int j = 1 ; j < v[ i ].size() ; j+=2 )
    {
        may = max( may ,  v[ i ][ j ]  - ant );
        ant = v[ i ][ j ];
    }
    may = max( may , vv[ i+1 ] - ant  );
  }
  return may;
>>>>>>> 7423170675695faa729d31679031a5d130954cc0
}

int main()
{
<<<<<<< HEAD
  int n,d;
  int t;
  int m;
  char s,non;
  scanf("%d",&t);
  for( int k = 0 ; k < t ; ++k )
  {
    std::vector<int> big;
    scanf("%d %d",&n,&d);
    big.push_back(0);
    for( int i = 0  ;i < n ; ++i )
    {
      scanf(" %c%c%d ", &s,&non,&m );
      if( s == 'B' )
        big.push_back(m);
    }
    big.push_back(d);
    printf("Case %d: %d\n", k+1 , func(d,big) );
=======
  int t;
  scanf("%d",&t );
  for( int k = 0 ; k < t ; ++k )
  {
    int n,d,m,last;
    char s,tr;
    std::vector< std::vector<int> > v(1,std::vector<int> ());
    std::vector<int> vv;
    vv.push_back(  0 );
    scanf("%d %d",&n , &d  );
    for( int i = 0 ; i < n ; ++i )
    {
      scanf(" %c%c%d",&s,&tr,&m );
      last =v.size() - 1;
      if( s == 'B' )
      {
        v.push_back( std::vector<int> ());
        vv.push_back( m );
      }
      else
        v[  last ].push_back( m );
    }
    vv.push_back( d );
    printf("Case %d: %d\n", k+1 , fun( v , vv ) );
>>>>>>> 7423170675695faa729d31679031a5d130954cc0
  }
  return 0;
}
