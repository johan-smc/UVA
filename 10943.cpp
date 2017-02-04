#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAX 101
#define MOD (int)1e6

int N,K;
int dp[ MAX ][ MAX ];

int how( int n , int k )
{
  // cout << n << " " << k << endl;
  if( n < 0 )
    return 0;
  if( k == 0 )
    if( n == 0 )
      return 1;
    else
      return 0;
  if( dp[ n ][ k ] != -1 )
    return dp[ n ][ k ];
  int tot = 0 ;
  for( int i = 0 ; i <= n ; ++i )
  {
    tot  = ( ( tot % MOD ) + (how( n - i , k-1 ) % MOD )) % MOD;
  }
  return dp[ n ][ k ] = tot;
}

int main()
{
  memset( dp , -1 , sizeof dp );
  while( scanf("%d %d",&N,&K ) , ( N || K) )
    printf("%d\n", how( N , K ) );
  return 0;
}
