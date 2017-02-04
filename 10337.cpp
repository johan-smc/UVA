ls
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define LIM 1001
#define INF 1<<25

int cost[ 10 ][ LIM ];
int dp[ 10 ][ LIM ];
int t,x;

int flying( int xx , int yy )
{
/*  if( yy == x )
    if( xx < 8 )
      return INF;
    else if ( xx == 8 )
      return 20 + cost[ xx ][ yy ];
    else
      return 30 + cost[ xx ][ yy ];
*/
  if( xx < 0 || xx > 9 )
    return INF;
  if( yy == x )
  {

    if( xx == 9 )
      return 0;
    else
      return INF;
  }
  if( dp[ xx ][ yy ] != -1 )
    return dp[ xx ][ yy ];
  int men = INF;
  men = min( men , flying( xx+1 , yy+1 ) + 20 - cost[ xx ][ yy ] );
  men = min( men , flying( xx , yy+1 ) + 30 - cost[ xx ][ yy ] );
  men = min( men , flying( xx-1 , yy+1 ) + 60 - cost[ xx ][ yy ] );
  return dp[ xx ][ yy ] = men;
}

int main()
{
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d",&x);
    x /= 100;
    for( int i = 0 ; i < 10 ; ++i )
      for( int j = 0 ; j < x ; ++j )
        scanf("%d",&cost[ i ][ j ]);
    memset( dp , -1 , sizeof dp );
    printf("%d\n\n",flying(9,0));
  }
  return 0;
}
