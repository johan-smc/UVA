#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair< int , int > ii;

#define MAX 15
#define BIT (1<<MAX)-1
#define INF 1<<20

int n,x,y,t,complete;
ii points[ MAX ];
int cost[ MAX ][ MAX ];
int dp[ MAX ][ BIT ];

int travel( int pos , int bitMask )
{
  // cout << pos << " " << bitMask << endl;
  if( bitMask == complete )
    return cost[ pos ][ 0 ];
  if( pos == n+1 )
    return INF;
  if( dp[ pos ][ bitMask ] != -1 )
    return dp[ pos ][ bitMask ];
  int men = INF;

  for( int i = 1 ; i <= n ; ++i )
  {
    if( !(bitMask & (1<<i)) && i != pos )
      men = min ( men , travel( i , bitMask | (1<<i) )+cost[ pos ][ i ] );
    // cout << pos << " " << bitMask << " " <<  i << " " << men << endl;
  }
  return dp[ pos ][ bitMask ] = men;
}


int main()
{
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d %d %d %d",&x,&y,&points[ 0 ].first,&points[ 0 ].second);
    scanf("%d",&n );
    for( int i = 1 ; i <= n ; ++i )
      scanf("%d %d",&points[ i ].first ,&points[ i ].second  );
    for( int i = 0 ; i < n+1 ; ++i )
    {
      for( int j = 0 ; j < n+1 ; ++j )
      {
        cost[ i ][ j ] = abs (  points[ i ].first - points[ j ].first ) + abs ( points[ i ].second - points[ j ].second );
        // cout << cost[ i ][ j ] << " " << points[ i ].first << " - " << points[ j ].first << "  " << points[ i ].second << " - " << points[ j ].second << endl;
      }
      // cout << endl;
    }
    memset( dp , -1 , sizeof dp );
    complete = ( 1<<(n+1) )-1;
    int tot = travel ( 0 , 1 );
    printf("The shortest path has length %d\n",tot );
  }
  return 0;
}
