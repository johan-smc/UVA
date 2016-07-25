#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  while( n-- )
  {
    int m;
    scanf("%d",&m);
    vector<int> v(m);
    for( int i = 0 ; i < m ; ++i )
    {
      scanf("%d",&v[i]);
    }
    int pos=0,swap=0;
    while( !is_sorted(v.begin(),v.end()) )
    {
      if( pos+1 < m)
      {
        if( v[pos]>v[pos+1])
        {  int x=v[pos];
          v[pos]=v[pos+1];
          v[pos+1]=x;
          swap++;
        }
        }
        pos++;
        pos%=m;
    }
    printf("Optimal train swapping takes %d swaps.\n",swap);
  }
  return 0;
}
