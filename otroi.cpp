#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define foi( i , n , k ) for( long long i = n ; i < k ; ++i )

using namespace std;

long long log2( long long a )
{
  return a == 0 ? a : floor( log10(a) / log10(2.0) );
}

long long solve( long long m , long long n )
{
  if( m == n )  return m + n + 1;
  if( m < n ) swap( m , n );
  long long inicial = log2( m + 1 ) + 1;
  long long dif = ( 1LL << inicial ) - 1;
  long long sumatoria = inicial;
  foi( i , 1 , n + 1 )
  {
    sumatoria += ( inicial - log2( i ) - 1 );
    --dif;
    if( dif >= 0 && dif <= m )  ++sumatoria;
  }
  return sumatoria;
}

int main()
{
  long long casos , m , n ;
  scanf("%lld", &casos );
  while( casos-- )
  {
    scanf("%lld %lld", &m , &n );
    printf("%lld\n", solve( m , n ) );
  }
  return 0;
}
