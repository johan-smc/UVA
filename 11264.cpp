#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAX 1001

int coins[ MAX ];
int n;

int main()
{
  int t;
  scanf("%d",&t );
  while( t-- )
  {
    int ant = 0, acum = 0 ;
      for( int i = 0 ; i < n ; ++i )
      {
        scanf("%d",&coins[ i ] );
        if( coins[ i ] >= 2 * ant )
        {
          acum += (ant = coins[ i ]) ;
        }
      }
  }
  return 0;
}
