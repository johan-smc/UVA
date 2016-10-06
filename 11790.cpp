#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define LIM 100000

int reconstruct( int end, int* P , int* A , int* PESOS)
{
  int pos = end;
  int sum = 0;
  while( pos != -1 )
  {
    // cout << pos << " " ;
    sum+=PESOS[pos];
    pos=P[pos];
  }
  // cout << "-- " << sum << endl;
  return sum;
}

int lis( int pos , int * LIS, int *A, int* PESOS )
{
  if( LIS[pos] != -1 )
    return LIS[pos];
  int may = 0;
  for (int i = pos -1 ; i >= 0 ; --i )
  {
    if( A[i] < A[pos] )
      may = max( lis(i,LIS,A,PESOS) , may );

  }
  return  LIS[pos] = may+PESOS[pos];
}

int main()
{
  int t,c=0;
  scanf("%d",&t);
  int A[LIM],A_I[LIM];
  int PESOS[LIM],LIS[LIM];
//  int L[LIM],L_id[LIM],P[LIM];
  while( t-- )
  {
    // memset( L , 0 , sizeof L );
    // memset( L , 0 , sizeof L_id );
    // memset( L , 0 , sizeof P );
    int n;
    scanf("%d",&n );
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d",&A[i] );
      A_I[i]=-A[i];
    }
    for( int i = 0 ; i < n ; ++i )
    {
      scanf("%d",&PESOS[i] );
    }
    /*
    int lis = 0;
    int lis_end = 0;*/
    int may=0,mayI=0;
    memset( LIS , -1 , sizeof LIS );
    LIS[0]=PESOS[0];
    for( int i = n - 1  ; i >= 0 ; --i )
      lis(i,LIS,A,PESOS);
      for( int i = 0 ; i < n ; ++i )
      {
        may=max(may,LIS[i]);
        // cout << LIS[i] << " ";
      }
      // cout << endl;
    /*for( int i = 0 ; i < n ; ++i )
    {
      cout << LIS[i] << " ";
    }
    cout << endl;*/
    memset( LIS , -1 , sizeof LIS );
    LIS[0]=PESOS[0];

    for( int i = n - 1  ; i >= 0 ; --i )
    lis(i,LIS,A_I,PESOS);
    for( int i = 0 ; i < n ; ++i )
    {
      mayI=max(mayI,LIS[i]);
    // cout << LIS[i] << " ";
  }
  // cout << endl;
    /*for( int i = 0 ; i < n ; ++i )
    {
      int pos = lower_bound(L,L+lis,A[i])-L;
      L[pos] = A[i];
      L_id[pos] = i;
      P[i] = pos ? L_id[pos-1] : -1 ;
      if( pos + 1 > lis )
      {
        lis = pos + 1;
        lis_end=i;
      }
      may=max(may,reconstruct(i,P,A,PESOS));
    }
    // memset( L , 0 , sizeof L );
    // memset( L , 0 , sizeof L_id );
    // memset( L , 0 , sizeof P );
    for( int i = 0 ; i < n ; ++i )
    {
      int pos = lower_bound(L,L+lis,A_I[i])-L;
      L[pos] = A_I[i];
      L_id[pos] = i;
      P[i] = pos ? L_id[pos-1] : -1 ;
      if( pos + 1 > lis )
      {
        lis = pos + 1;
        lis_end=i;
      }
      mayI=max(mayI,reconstruct(i,P,A_I,PESOS));
    }*/
    if( may >= mayI )
    {
      printf("Case %d. Increasing (%d). Decreasing (%d).\n",++c,may,mayI );

    }
    else
    {
      printf("Case %d. Decreasing (%d). Increasing (%d).\n",++c,mayI,may );

    }
  }
  return 0;
}
