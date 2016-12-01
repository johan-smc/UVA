#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAX 10005
#define INF 1<<30
typedef pair< int , int > ii;

int gol,n;
int cash[ 105 ];
ii dp[ MAX ][ 105 ];
bool visited[ MAX ][ 105 ];

ii buy( int money , int pos )
{
  // cout << "money " << money << endl;
  if( money <= 0 )
    return ii( abs( money ) , 0 );
  if( pos == n )
    return ii( INF , INF );
  if( visited[ money ][ pos ]  )
    return dp[ money ][ pos ];
  ii temp=ii( INF , INF ) ;
  ii aux,aux2;
  // for( int i = 0 ; i < n ; ++i )
  // {

      aux = buy( money - cash[pos] , pos + 1 );
      ++aux.second;
      aux2 = buy( money , pos + 1 );

      temp = min( aux , aux2 );
      // cout << "exa " << temp.first << " " << temp.second << " " << money << " " << money-cash[ i ] << endl;

  // }
  visited[ money ][ pos ] = true;
  return dp[ money ][ pos ] = temp;
}

int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d %d",&gol,&n);
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d", &cash[ i ] );
    }
    memset( visited , 0 , sizeof visited );
    ii res = buy( gol , 0 );
    // cout << res.first << " " << res.second <<endl;
    printf("%d %d\n", gol + res.first,res.second );
  }
  return 0;
}
