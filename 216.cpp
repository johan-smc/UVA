#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;
#define MAX 9
#define BITMAX (1<<MAX)-1
#define INF 2700.0

typedef pair< int , int > ii;

int n,complete;

double dist[ MAX ][ MAX ];
ii points[ MAX ];
double dp[ MAX ][ BITMAX ];
bool visited[ MAX ][ BITMAX ];
ii root[ MAX ][ BITMAX ];


double hipo( const ii& a , const ii& b )
{
  return sqrt( ( (a.first-b.first)*(a.first-b.first) ) + ( (a.second-b.second)*(a.second-b.second) ) );
}

double traveling( int pos , int bitMask )
{
  // cout << pos << " " << bitMask << endl;
  if( bitMask == complete ){
    // cout << "fuenic" << endl;
    return 0.0;
  }
  if( pos == n )
    return INF;
  if( visited[ pos ][ bitMask ] )
    return dp[ pos ][ bitMask ];
  double men = INF,temp;
  // cout << "ini " << pos << " " << bitMask << " " << men << endl;
  for( int i = 0 ; i < n ; ++i )
  {
    if( (!( bitMask & (1<<i) ) && i != pos)  )
    {
      temp =  dist[ pos ][ i ] + traveling( i , bitMask | (1<<i) ) ;
      if( men > temp )
      {
        men = temp;
        root[ pos ][ bitMask ] = ii( i,bitMask|(1<<i) );
      }

    }
    // cout << "qui " << pos << " " << bitMask << " " << men << endl;

  }
  visited[ pos ][ bitMask ] = true ;

  return dp[ pos ][ bitMask ] = men;
}

int main()
{
  int c = 0;
  while ( scanf("%d",&n ) != EOF && n )
  {
    printf("**********************************************************\n");
    printf("Network #%d\n",++c );
    for( int i = 0 ; i < n ; ++i )
      scanf("%d %d",&points[ i ].first , &points[ i ].second );
    for( int i = 0 ; i < n ; ++i ){
      for( int j = 0 ; j < n ; ++j ){
          dist[ i ][ j ] = hipo( points[ i ] , points[ j ] )+16.0;
        // cout << dist[ i ][ j ] << " " ;
      }
      // cout << endl;
    }
    memset( visited , 0 , sizeof visited );
    complete = ( 1 << n )-1;
    double temp,tot = INF;
    ii bit;
    for( int i = 0 ; i < n ; ++i )
    {
      temp = traveling( i , 1<<i );
      // cout << temp << endl;
      if( temp < tot )
      {
        tot = temp;
        bit = ii( i , 1<<i );
      }
    }
    queue< ii > q;
    while( bit.second != complete )
    {
      int a = bit.first;
      bit = root[ bit.first ][ bit.second ];
      int b = bit.first ;
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",points[ a ].first,points[a].second , points[b].first,points[b].second , dist[a][b] );
    }
    printf("Number of feet of cable required is %.2lf.\n",tot );
  }
  return 0;
}
