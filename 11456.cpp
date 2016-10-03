#include <iostream>
#include <algorithm>
#include <cstdio>

#define foi( i , n , k ) for( int i = n  ; i < k ; ++i )
#define LIM 2005
using namespace std;

int LIS( int A[],int tam,int posI)
{
  foi()
}

int main()
{
  int t;
  int A[LIM],AD[LIM];
  scanf( "%d" , &t );
  while( t-- )
  {
    int n;
    scanf( "%d" , &n );
    foi( i , 0 , n )
    {
      scanf("%d",&A[n-i-1]);
      AD[i]=-A[i];
    }

    int may=0;
    foi( i , 0 , n )
    {
      int tam=LIS(A,n,i)+LDS(AD,n,i)-1;
      may=max(may,tam);
    }
    printf("%d\n",may );
  }
  return 0;
}
