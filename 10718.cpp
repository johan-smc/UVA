#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned int uint;

uint n,down,up;

uint BIN( uint num )
{
  uint temp = 1;
  return temp<<(num);
}

int ML( uint num )
{
  int pos = -1;
  // cout << pos << endl;
  while( num != 0 )
    if( num & BIN(++pos) )
      num ^= BIN(pos);
  return pos;
}

uint bitMask( uint &n , uint &down , uint &up )
{
  int pos = ML( up );
  uint sum = down;
  uint num ;
  uint m=0 ;
  if( pos == -1 )
    return 0;
  // cout << pos << endl;
  for( ; pos >= 0 ; --pos )
  {
    num = ( n & BIN(pos) );
    // cout << pos << " " << num << " " << (m | BIN(pos)) << " " << up << " " << sum << endl;
    if( num )
    {
      // cout << "first" << endl;
      if( sum >= num )
      {
        // cout << "first-1" << endl;
        if( sum != 0 && BIN(pos) > sum )
          sum = 0 ;
        else if(sum != 0 )
          sum -= BIN(pos);
        m |= BIN(pos);
      }
    }
    else if( (m | BIN(pos)) <= up )
    {
      // cout << "second" << endl;
      if( sum != 0 && BIN(pos) > sum )
        sum = 0 ;
      else if(sum != 0 )
        sum -= BIN(pos);

      m |= BIN(pos);
    }
  }
  return m;
}

int main()
{
  while( scanf("%u %u %u",&n,&down,&up ) != EOF )
  {
    // cout << n << " " << down << " " << up << endl;
    printf("%u\n", bitMask(  n , down , up ) );
  }
  return 0;
}
