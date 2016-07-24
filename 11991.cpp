#include <iostream>
#include <unordered_map>
#include <vector>

#define foi( i , n ,k ) for( int i = n ; i < k ; ++i)
using namespace std;

int main()
{
  int n,m;
  while( scanf("%d%d",&n,&m)!=EOF )
  {
    int c,k,v;
    unordered_map< int , vector<int> > ump;
    foi( i , 0 , n )
    {
      scanf("%d",&c);
      if( ump.find(c)==ump.end() )
      {
        ump.insert(make_pair(c,vector<int>()));
      }
      ump[c].push_back(i);
    }
    foi( i , 0 , m )
    {
      scanf("%d%d",&k,&v);
      if( ump.find(v)!=ump.end() && ump[v].size() >= k )
      {
        printf("%d\n",ump[v][k-1]+1);
      }
      else
        printf("0\n");
    }
  }
  return 0;
}
