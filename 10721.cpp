#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAX 51
typedef long long ll;

int n,k,m;
ll dp[ MAX ][ MAX ][ MAX ];

ll BC( int a , int b , int c )
{
  if( b == 0 )
    if( a == 0 )
      return 1;
    else
      return 0;
  if( a <= 0 )
    return 0;
  if( dp[ a ][ b ][ c ] != -1 )
    return dp[ a ][ b ][ c ];
  ll tot = 0 ;
  for( int i = 1 ; i <= c ; ++i )
    tot += BC( a-i , b-1 , c );
  return dp[ a ][ b ][ c ] = tot;
}

int main()
{
  memset( dp , -1 , sizeof dp );
  while( scanf("%d %d %d",&n,&k,&m ) != EOF )
  {
    printf("%lld\n",BC(n,k,m) );
  }
  return 0;
}
