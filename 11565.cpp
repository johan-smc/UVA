#include <iostream>
#include <cstdio>

#define foi( i , n , k ) for( int i =  n ; i < k ; i++ )
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    bool isPos=false;
    for( int  x = -99 ; x < 100 &&!isPos; ++x)
    {
      for( int y= x+1;y<100 && x*y < B ; ++y)
      {
        int z=A-x-y;
        if( x*y*z == B && (x*x)+(y*y)+(z*z)==C && x!=y && y != z && z!= x)
        {
          isPos=true;
          printf("%d %d %d\n",x,y,z);
          break;
        }
      }
    }
    if(!isPos)
      printf("No solution.\n");
  }
  return 0;
}
