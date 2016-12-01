#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define NC 5
#define MAX 30002

typedef long long ll;

int coins[ NC ] = { 1 , 5 , 10 , 25 , 50 };
ll dp[ NC ][ MAX ];

ll change( int type , int money )
{
  if( money == 0  )
    return 1;
  if(  type == NC )
    return 0;
  if( dp[ type ][ money ] != -1 )
    return dp[ type ][ money ];
  ll a , b , c;
    a = change( type + 1 , money );
    b = 0;
    // b = ( money - coins[ type ] >= 0 ) ? change( type + 1 , money - coins[ type ] )  : 0;
    c = ( money - coins[ type ] >= 0 ) ? change( type  , money - coins[ type ] )  : 0;
    // cout << type << " " << money << " " << a << " " << b << " " << c << endl;
  return dp[ type ][ money ] = a + b + c ;
}

int main()
{
  int m;
  memset( dp , -1 , sizeof dp );
  while( scanf("%d",&m ) != EOF )
  {
    ll tot = change( 0 , m );
    // if( m == 0 )
    //   tot = 0 ;
    if( tot == 1 )
      printf("There is only 1 way to produce %d cents change.\n", m );
    else
      printf("There are %lld ways to produce %d cents change.\n",tot,m );
  }
  return 0;
}
