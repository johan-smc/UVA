#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define FIN 2047
#define INF ( 1<<29 )

int n,x,t,k;
int cost[105];
int favour[12][105];
// int dp[2048][105][105];
int dp[12][105][105];

/*
int buy( int indexP , int index , int f )
{
  cout << indexP << " " << index << " " << f << endl;
  if( index == k )
    return dp[ indexP ][ index ][ f ] = -INF;
  if( indexP == FIN )
    return dp[ indexP ][ index ][ f ] = 0;
  if( dp[ indexP ][ index ][ f ] != -1 )
    return dp[ indexP ][ index ][ f ];
  int firts,second,may=0;
  second = buy(indexP,index + 1,f );
  may = max( second , may );
  for( int i = 0 ; i < n + 1 ; ++i )
  {
    firts += (f-cost[index] >= 0 && !( indexP & (1<<i) ) )?buy(( indexP | (1<<i) ),index + 1,f-cost[ index ])+favour[i][index]:0;
    may = max( firts , may );
  }
  return dp[ indexP ][ index ][ f ] = may;
}*/

int fir( int indexP , int index , int f ,  int pos )
{
  if( ver == FIN )
    return dp[ indexP ][ index ][ f ] = 0;
  if( pos == n+1 )
    return dp[ indexP ][ index ][ f ] = 0;
  if( dp[ indexP ][ index ][ f ] != -1 )
    return dp[ indexP ][ index ][ f ];
  
}
int sec()
{

}

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
    printf("%d\n",buy(0,0,x * (n + 1) ));
  }
  return 0;
}
