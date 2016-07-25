#include <cstdio>
#include <iostream>

using namespace std;

int fun(int n )
{
  int c=0;
  while( n!=1)
  {
    if( n%2==1)
      n=3*n+1;
    else
      n/=2;
      c++;
  }
  return c+1;
}

int main()
{
  int a,b;
  while(scanf("%d%d",&a,&b)!=EOF)
  {
    int may=-9999;
    int ini=a,fin=b;
    if( a > b )
      {ini=b;
        fin=a;
      }

    for( int i = ini ; i <= fin ; ++i )
    {
      may=max(may,fun(i));
    }
    printf("%d %d %d\n",a,b,may);
  }

  return 0;
}
