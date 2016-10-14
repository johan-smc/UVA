#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>


using namespace std;
#define ll long long
#define CC 20
ll res[205][43][11] ;
typedef pair< int , int > ii ;

ll dp( int* arr , const int& n , int d  , ll pos , ll sum , ll lm )
{
  if( lm == 0 )
     return res[ pos ][ sum + CC ][ lm ] = ( sum % d == 0 )? 1 : 0 ;
  if( pos == n )
    return res[ pos ][ sum + CC ][ lm ] = 0;
  if( res[ pos ][ sum + CC ][ lm ] != -1  )
    return res[ pos ][ sum + CC ][ lm ];
  ll s=0;
  s += dp( arr , n , d , pos + 1 ,  ( ( sum % d )  + ( arr[pos] % d ) ) % d , lm - 1  );
  s += dp( arr , n , d , pos + 1 , sum , lm  );
  return res[ pos ][ sum + CC ][ lm ] = s ;
}

int main()
{
  int n , q , c = 0;
  int d , m;
  int arr[205] = { 0 };
  while( scanf("%d %d",&n,&q) != EOF && n != 0 && q != 0 )
  {
    for( int i = 0 ; i <  n ; ++i )
    {
      scanf("%d", &arr[i] );
    }
    printf("SET %d:\n", ++c );
    for( int i = 0 ; i < q ; ++i )
    {
      scanf("%d %d", &d , &m );
      memset( res , -1 , sizeof res );
      // map<  ii , int > res;
      printf("QUERY %d: %lld\n", i+1 , dp( arr , n , d , 0 , 0 , m  ) );
    }
  }
  return 0;
}
