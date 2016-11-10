#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

typedef pair< int , int > ii;
int R,C,M,N,W,par,impar;
int visited[ 101 ][ 101 ];
int water[ 101 ][ 101 ];
int xx[8],yy[8];

bool isPos( int x , int y )
{
  if( x < 0 || x >= R || y < 0 || y >= C || water[ x ][ y ])
    return false;
  return true;
}

void print()
{
  for( int i = 0  ; i < R ; ++i ){
    for( int j = 0 ; j < C ; ++j )
      cout << visited[ i ][ j ] << " ";
      cout << endl;
    }
}

void dfs( int x , int y)
{
  visited[ x ][ y ] = 1;
  int cont = 0;
  set< ii > pp;
  for( int i = 0; i < 8 ; ++i )
  {
    int nextx = x + xx[i];
    int nexty = y + yy[i];
    if( isPos( nextx , nexty ) && pp.find( ii( nextx , nexty ) ) == pp.end() )
    {
      pp.insert( ii( nextx , nexty ) );
      if( !visited[ nextx ][ nexty ] )
        dfs( nextx , nexty );
      ++cont;
    }
  }
  if( cont&1 )
    ++impar;
  else
    ++par;
  // int mm;
  // cin >> mm;
  // print();
}


int main()
{
  int t,c = 0,xi,yi;
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d %d %d %d %d",&R,&C,&M,&N,&W);
    memset( visited , 0 , sizeof visited );
    memset( water , 0 , sizeof water );
    for( int i = 0; i < W ; ++i )
    {
      scanf("%d %d",&xi,&yi);
      water[ xi ][ yi ] = 1;
    }
    xx[0]=M; yy[0]=N;
    xx[1]=-M; yy[1]=-N;
    xx[2]=-N; yy[2]=-M;
    xx[3]=N; yy[3]=M;
    xx[4]=M; yy[4]=-N;
    xx[5]=-N; yy[5]=M;
    xx[6]=-M; yy[6]=N;
    xx[7]=N; yy[7]=-M;
    par = 0; impar = 0;
    dfs( 0 , 0 );
    printf("Case %d: %d %d\n", ++c , par , impar );
  }
  return 0;
}
