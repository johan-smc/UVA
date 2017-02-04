#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;
#define MAX 1001

int coins[ MAX ];

double pas[ MAX ];
int n;
int pos;
int withdraw( int X )
{
  if( X == 0 ) return 0;
  while( coins[ pos ] > X )pos--;
  int Y = pos;
  // cout << X << " " << Y << " " << coins[ Y ] <<  endl;
  int sum =((pas[ Y ])?!(pas[ Y ]=0):0) ;
  return   withdraw( X - coins[ Y ] ) + sum ;
  // return   withdraw( X - coins[ Y ] ) + 1 ;
}

int n;

int main()
{
  int t;
  int  ant , sum , sum2  ;
  scanf("%d",&t);
  while( t-- )
  {
    sum2 =  sum  = ant = 0 ;
    scanf("%d",&n);

    for( int i = 0; i < n ; ++i )
    {
      scanf("%d",&coins[ i ]);
      // if( coins[ i ] > sum2 )
      //   sum2 += coins[ i ];
    }
    /*ant = sum = coins[ n - 1 ] - 1 ;
    ++sum;
    for( int i = n - 2 ; i >=  0 ; --i )
    {
      if( ant - coins[ i ] >= 0  )
      {
        // ant = coins[ i ];
        sum += coins [ i ];
        ant -= coins[ i ];
        // ant = min( ant - coins[ i ] , coins[ i ] -1 );
      }
    }
    memset( pas , 1 , sizeof pas );
    pos = n-1;
    int aux =withdraw( sum );
    */
    for( int i = 0 ; i < n-1 ; ++i )
    {
      if( sum + coins[ i ] < coins[ i + 1 ] )
        sum += coins[ i ];
    }
    sum += coins[ n-1 ];
    memset( pas , 1 , sizeof pas );
    pos = n-1;
    // printf("sum = %d sum2 = %d \n",sum,sum2 );
    printf("%d\n", withdraw( sum )  );

  }
  return 0;
}
