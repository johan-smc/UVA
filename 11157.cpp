#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int func( int d , std::vector<int> &v )
{
  int may = 0;
  for( int i = 0 ; i < v.size() ; ++i )
}

int main()
{
  int n,d;
  int t;
  int m;
  char s,non;
  scanf("%d",&t);
  for( int k = 0 ; k < t ; ++k )
  {
    std::vector<int> big;
    scanf("%d %d",&n,&d);
    big.push_back(0);
    for( int i = 0  ;i < n ; ++i )
    {
      scanf(" %c%c%d ", &s,&non,&m );
      if( s == 'B' )
        big.push_back(m);
    }
    big.push_back(d);
    printf("Case %d: %d\n", k+1 , func(d,big) );
  }
  return 0;
}
