#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
  int n,m,k;
  scanf("%d %d %d",&n,&m,&k );
  int tot = m/n;
  int may = tot;
  if( k < m%n )
    may = max(may,tot+1);
  if( n-k < m%n )
    may = max(may,tot+1);
  printf("%d\n",may );
  return 0;
}
