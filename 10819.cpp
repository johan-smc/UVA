#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define INF int(1 << 30)

int cost[105],fav[105];
int res[105][10505];

int dp( int m , int n , int pos , int cc )
{
  if( pos == n )
  {
    // cout << cc << " " << m << " " << ( ( cc-m > 0 && cc > 2000 ) || ( cc <= m ) ? 0 : -INF )<< endl;
    return res[ pos ][ cc ] = ( cc-m > 0 && cc > 2000 ) || ( cc <= m ) ? 0 : -INF  ;
  }
  if( res[ pos ][ cc ] != -1  )
    return res[ pos ][ cc ];
  int a,b;
  int sum = cc + cost[pos];
  if(  sum <= m+200 )
    a = dp( m , n , pos + 1 , sum ) + fav[pos];
  else
    a = -INF;
  b=dp( m , n , pos + 1, cc  );
  // cout << "pos " << pos << " a " << a << " b " << b << endl;
  return res[ pos ][ cc ] = max( a , b );
}

int main()
{
  int n,m;
  while( scanf("%d %d",&m,&n ) != EOF )
  {
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d %d",&cost[i],&fav[i] );
    }
    memset( res , -1 , sizeof res );
    printf("%d\n", dp( m , n , 0 , 0 ) );
  }
  return 0;
}
