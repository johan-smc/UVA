#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;
int res[205][20105][11] ;

int dp( int* arr , const int& n , int d  , int pos , int sum , int lm )
{
  if( pos == n )
    return res[ pos ][ sum ][ lm ] = 0;
  if( res[ pos ][ sum ][ lm ] != -1  )
    return res[ pos ][ sum ][ lm ];
  if( lm == 0 )
  {
    return res[ pos ][ sum ][ lm ] = ( sum % d == 0 )? 1 : 0 ;
  }
  int s=0;
  s += dp( arr , n , d , pos+1 , sum+arr[pos] , lm-1  );
  s += dp( arr , n , d , pos+1 , sum , lm );
  return res[ pos ][ sum ][ lm ] = s ;
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
      printf("QUERY %d: %d\n", i+1 , dp(arr,n,d,0,0,m) );
    }
  }
  return 0;
}
