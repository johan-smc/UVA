#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define foi( i , n ,k ) for( int i = n ; i < k; ++i )
using namespace std;



int main()
{
  int n;
  vector< int > v;
  while(scanf("%d",&n)!=EOF)
  {
    v.push_back(n);
  }
  vector<int> q;
  q=funcion(v,q);
  printf("%d\n-\n",(int)q.size());
  foi( i , 0 , q.size() )
  {
    printf("%d\n",q[i]);
  }
  return 0;
}
