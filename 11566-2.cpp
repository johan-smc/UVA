#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
#define INF (1<<20)

int n,x,t,k;
int favour[ 105 ] , cost[ 105 ] ;
int dp[ 105 ][ 1205 ];
int lim;

int costTot( int num )
{
  // cout << num << " " << num + t << " "  <<round( (num +  t)*0.1 )<< " " <<  (num +  t) + round((num +  t)*0.1) << endl;
  return (num +  t) + round((num +  t)*0.1);
}



int buy( int pos , int f )
{
  // cout << pos << " " << f << endl;
  if( pos == k )
  {
    // if( f % ( n + 1 ) == 0)
      return 0;
    // return -INF;
  }
  if( dp[ pos ][ f ] != -1  )
      return dp[ pos ][ f ];
  int first , second , third ;
  first = (  f + costTot( (double)cost[pos] ) <= (lim) ) ? buy( pos + 1 , f + costTot( (double)cost[pos] ) ) +  favour[pos]  : 0 ;
  second = (  f + 2 * costTot( (double)cost[pos] ) <= lim ) ? buy( pos + 1 , f + 2 * costTot( (double)cost[pos] ) ) +  favour[pos] : 0 ;
  third = buy( pos + 1 , f );
  return dp[ pos ][ f ] = max( max( first , second ) , third );
}


int main()
{
  while( scanf("%d %d %d %d",&n,&x,&t,&k) , (n || x  || t  || k ) )
  {
    for( int i = 0 ; i < k ; ++i )
    {
      scanf("%d",&cost[ i ] );
      int sum = 0 ;
      int num;
      for( int j = 0 ; j < n + 1 ; ++j  )
      {
        scanf("%d",&num );
        sum += num;
      }
      favour[ i ] = sum;
    }
    memset( dp , -1 , sizeof dp );
    lim = x*(n);
   printf("%.2lf\n", (double)buy( 0 , 0)/(double)4 );
  }

  return 0;
}
