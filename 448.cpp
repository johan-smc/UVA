#include <iostream>
#include <cstdio>

#define foi( i , n , k ) for( int i = n ; i < k ;++i )

using namespace std;

void imp( int n )
{
  foi( i , 1 , n+1 )
  {
    foi( j , 0 , i )
    {
      printf("%d",i);
    }
    printf("\n");
  }
  for( int i = n-1 ; i > 0 ; i-- )
  {
    foi( j , 0 , i )
    {
      printf("%d",i);
    }
    printf("\n");

  }
}

int main()
{
  int t;
  scanf("%d",&t);
  foi( k , 0 , t )
  {
    if(k!=0)
      printf("\n");
    int a,f;
    scanf("%d%d",&a,&f);
    foi( i , 0 , f )
    {
      if(i!=0)
        printf("\n");
      imp(a);
    }
  }
  return 0;
}
