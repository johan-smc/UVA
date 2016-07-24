#include <iostream>
#include <map>
#include <set>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i)
using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF && n != 0 )
  {
    map< set<int> , int > mp;
    int may=0;
    int c;
    foi( i , 0 , n )
    {
      set<int> ss;
      foi( j , 0 , 5 )
      {
        scanf("%d",&c);
        ss.insert(c);
      }
      mp[ss]++;
      if( may < mp[ss] )
        may=mp[ss];
    }
    int tot=0;
    map< set<int> , int >::iterator it=mp.begin();
    for( it=mp.begin() ; it != mp.end() ; ++it )
    {
        if(it->second==may)
          tot++;
    }
    printf("%d\n",may*tot);

  }
  return 0;
}
