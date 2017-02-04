#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 10001

int main()
{
  int b,s;
  int c = 0;
  int bach[ MAX ];
  int spin[ MAX ];
  while( scanf("%d %d",&b,&s ) , ( b || s ) )
  {
    for( int i = 0 ; i < b ; ++i )
      scanf("%d",&bach[ i ] );
    for( int i = 0 ; i < s ; ++i )
      scanf("%d",&spin[ i ] );
    if( b <= s )
    {
      printf("Case %d: 0\n",++c );
      continue;
    }
    sort( bach , bach + b );
    printf("Case %d: %d %d\n",++c,b-s, bach[ 0 ] );
  }
  return 0;
}
