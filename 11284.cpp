#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;
#define MAX 52
#define INF 1<<21
#define BIT 1<<12


int END;
int t,n,m,p;
int a,b;
double c;
double matAd[ MAX ][ MAX ];
double dp[ MAX ][ BIT ];
bool vdp[ MAX ][ BIT ];
//double cost[ MAX ];
int ind[ MAX ];

void floyd()
{
  for( int k = 0 ; k < n+1 ; ++k )
    for( int i = 0 ; i < n+1 ; ++i )
      for( int j = 0 ; j < n+1 ; ++j )
        matAd[ i ][ j ] = min( matAd[ i ][ j ] , matAd[ i ][ k ] + matAd[ k ][ j ] );
}

double travel( int pos , int bitMask )
{
  if( bitMask  == END )
    return matAd[ pos ][ 0 ];
  if( vdp[ pos ][ bitMask ]  ){
    // cout << "ya habia pasado " << dp[ pos ][ bitMask ] << endl;
    return dp[ pos ][ bitMask ];
  }
  double men = INF ;
  for( int i  = 1 ; i < n+1 ; ++i )
  {
    if(  (ind[ i ]==-1?0:!(bitMask&(1<<ind[i]))) && i != pos )
    {
      // cout << "vo " << pos << " a " << i << " " << men << endl;
      // cout << "vo " << pos << " a " << i << " " << men << " " << ((ind[ i ] != -1 )?(bitMask|(1<<ind[i])):bitMask) << endl;
      men = min( men , travel( i , ((ind[ i ] != -1 )?(bitMask|(1<<ind[i])):bitMask) ) + matAd[ pos ][ i ] );
    }
  }
  // cout << men << endl;
  vdp[ pos ][ bitMask ] = 1;
  return dp[ pos ][ bitMask ] = men ;

}

int main()
{
  scanf("%d",&t);
  while( t-- )
  {
    memset( vdp , 0 , sizeof vdp );
    memset( ind , -1 , sizeof ind );
  //  memset( cost , 0 , sizeof cost );
    scanf("%d %d",&n,&m );
    for( int i = 0 ; i < n+1 ; ++i )
      for( int j = 0 ; j < n+1 ; ++j )
        if( i == j ) matAd[ i ][ j ] = 0; else matAd[ i ][ j ] = INF;
    for( int i = 0 ; i < m ; ++i )
    {
      scanf("%d %d %lf",&a,&b,&c );
      matAd[ a ][ b ] = min( matAd[ a ][ b ] , c );
      matAd[ b ][ a ] = min( matAd[ b ][ a ] , c );
    }
    double des = 0.0;
    END = 0;
    scanf("%d",&p );
    for( int i = 0 ; i < p ; ++i )
    {
      scanf("%d %lf",&a,&c );
    //  cost[ a ] = c;
      des += c;
      END |= (1<<i);
      ind[ a ] = i;
    }
    floyd();
    // for( int i = 0 ; i < n+1 ; ++i )
    // {
    //   for( int j = 0 ; j < n+1 ; ++j )
    //     cout << matAd[ i ][ j ] << " ";
    //   cout << endl;
    // }
    double res = travel( 0 , 0 );
    cout << res << " " << des << endl;
    if( des - res < 0 )
      printf("Don’t leave the house\n");
    else
      printf("Daniel can save $%.2lf\n", des - res );
  }
  return 0;
}
