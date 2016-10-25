#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[12][1200];
int tea[12][105];
int cost[105];
int n,x,t,k;

double formula( double tot ){ return round(( tot + ( ( n + 1 )*t ))*1.1);}

int buy( int pos , int f )
{
  if( pos == n+1 ){
    // cout << "llegue " << endl;
    return  0;
  }
  if( dp[ pos ][ f ] != -1 )
    return dp[ pos ][ f ];
  int may = 0 ;
  for( int i = 0 ; i < k ; ++i )
  {
    may = max ( may , (f - cost[i] >= 0 ) ? buy( pos +1 , f - cost[i] ) + tea[pos][i] : -1  );
  }
  return dp[pos][f] =  may;
}

int main()
{
  while( scanf("%d %d %d %d",&n,&x,&t,&k) , (n || x  || t  || k ) )
  {
    for( int i = 0 ; i < k ; ++i )
    {
      scanf("%d", &cost[i] );
      for( int j  = 0 ; j < n+1 ; ++j )
        scanf("%d", &tea[j][i] );
    }
    memset( dp , -1 , sizeof dp );
    printf("%.2lf\n", formula( (double)buy(0, x * (n+1) ) )/(double)(n+1) );
  }
  return 0;
}
