#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
#define FIN 2047
#define INF ( 1<<29 )

int n,x,t,k;
int cost[105];
int favour[12][105];
int dp[ 12 ][ 105 ][ 105 ];
// int dp[12][105][105];

//cuatro
int buy( int indexP  , int index , int f  , int fun )
{
  // cout << indexP << " " << index << " " << f << " " << fun << endl;
  if( fun == (1<<(n+1))-1 ){
    // cout << "llegue " << endl;
    return dp[ indexP ][ index ][ f ] = 0;
  }
  if( index == k )
    return dp[ indexP ][ index ][ f ] = -INF;
  // if( indexP == n+1 )

  if( dp[ indexP ][ index ][ f ] != -1 )
    return dp[ indexP ][ index ][ f ];
  int firts,second,third,fourth;
  // cout << (f-cost[index] >= 0 && !( fun & (1<<indexP) ) ) << " firts " << indexP << " " <<  (fun | (1<<indexP)) <<endl;
  firts = buy( indexP + 1  , index  , f , fun  );
  second = ( indexP == n )?buy( 0  , index + 1  , f , fun  ):-INF;
  third = (f-cost[index] >= 0 && !( fun & (1<<indexP) ) )?buy( indexP + 1 , index ,f-cost[ index ] , ( fun | (1<<indexP) ))+favour[indexP][index]:-INF;
  fourth = (f-cost[index] >= 0 && !( fun & (1<<indexP) ) && indexP == n )?buy( 0  , index + 1 ,f-cost[ index ] , ( fun | (1<<indexP) ))+favour[indexP][index]:-INF;
  /*second = buy(indexP,index + 1,f );
  may = max( second , may );
  for( int i = 0 ; i < n + 1 ; ++i )
  {
    firts += (f-cost[index] >= 0 && !( indexP & (1<<i) ) )?buy(( indexP | (1<<i) ),index + 1,f-cost[ index ])+favour[i][index]:0;
    may = max( firts , may );
  }*/
  return dp[ indexP ][ index ][ f ] = max( max( firts , second ) , max( third , fourth) );
}

// int fir( int indexP , int index , int f ,  int pos )
// {
//   if( ver == FIN )
//     return dp[ indexP ][ index ][ f ] = 0;
//   if( pos == n+1 )
//     return dp[ indexP ][ index ][ f ] = 0;
//   if( dp[ indexP ][ index ][ f ] != -1 )
//     return dp[ indexP ][ index ][ f ];
//
// }
// int sec()
// {
//
// }

double formula( double tot ){ return ceil((tot+( ( n + 1 )*t ))*1.1);}

int main()
{
  while( scanf("%d %d %d %d",&n,&x,&t,&k) != EOF  && (n!=0 || x != 0 || t != 0 || k != 0) )
  {
    for( int i = 0 ; i < k ; ++i )
    {
      scanf("%d",&cost[i] );
      for( int j = 0 ; j < n+1 ; ++j )
      {
        scanf("%d",&favour[j][i]);
      }

    }
    memset( dp , -1 , sizeof dp );
    printf("%.2lf\n",formula( buy(0,0,x * (n + 1), 0 ) )/((double)n+1));
  }
  return 0;
}
