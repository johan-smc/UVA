#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 20002

//n ->dragon m->knight
int n,m;
int knights[ MAX ];
int dragons[ MAX ];

int main()
{
  while( scanf("%d %d",&n,&m ) , ( n || m ) )
  {
    for( int i = 0 ; i < n ; ++i )
      scanf("%d",&dragons[ i ] );
    for( int i = 0 ; i < m ; ++i )
      scanf("%d",&knights[ i ] );
    if( n > m )
    {
      printf("Loowater is doomed!\n");
      continue;
    }
    sort( dragons , dragons+n );
    sort( knights , knights+m );
    int tot ,pos  ;
    bool s = true;
    tot = pos = 0;
    for( int i = 0 ; i < n && s ; ++i )
    {
      while( pos < m && knights[ pos ] < dragons[ i ] )++pos;
      if( pos >= m )
        s = false;
      else
        tot += knights[ pos ];
      ++pos;
    }
    if( s )
      printf("%d\n",tot );
    else
      printf("Loowater is doomed!\n");

  }
  return 0;
}
