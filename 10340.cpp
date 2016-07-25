#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  string a,b;
  while( cin>>a>>b )
  {
      int pos=0;
    for( int  i=0; i<  b.size() ;++i )
    {
      if(a[pos]==b[i])
      {
        pos++;
        if(pos==a.size() )
          break;
      }
    }
    if(pos==a.size())
      printf("Yes\n" );
    else
      printf("No\n");
  }
  return 0;
}
