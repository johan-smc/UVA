#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAX 104

int n;
char field[ MAX ];

int fun()
{
  int p,e,tot ;
  tot = p = e = 0;
  for( int i = 0 ; i < n ; ++i )
  {
    if(( field[ i ] == '#' && p % 3 != 0 ) || ( field[ i ]=='.'))
      p++;

  }
  // cout << p << " " << field << endl;
  return p/3 + ((p%3 != 0 )?1:0);
}

int main()
{
  int t;
  scanf("%d",&t );
  for( int k = 0 ; k < t ; ++k )
  {
    scanf("%d",&n );
    scanf(" %s " , field );
    printf("Case %d: %d\n",k+1,fun() );
  }
  return 0;
}
