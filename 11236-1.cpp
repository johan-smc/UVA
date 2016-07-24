#include <iostream>
#include <cstdio>

#define CONST 10e5
using namespace std;

int main()
{
  for( int i   =1 ; i <= 2000 ; ++i )
  {
    for( int j = i ; j <= 2000-i ; ++j )
    {
      for( int k = j ; k <= 2000-i-j ; ++k )
      {
        // int i,j,k;
        // scanf("%d%d%d",&i,&j,&k );
        if(i*j*k!=CONST)
        {
          double d=(CONST*(i+j+k))/((i*j*k)-CONST);
          int test=(int)d;
          // int o=CONST;
          // printf("%d %lf %d %d\n",i*j*k,d,test ,o);
          if(d==test&&d >= k && d+i+j+k <= 2000)
            printf("%.2lf %.2lf %.2lf %.2lf\n",((double)i)/100,((double)j)/100,((double)k)/100,d/100);
        }
      }
    }
  }
  return 0;
}
