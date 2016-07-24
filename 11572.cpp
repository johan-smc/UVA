#include <iostream>
#include <map>
#include <vector>

#define foi( i , n , k) for( int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int n,c;
    map<int,int> mp;
    scanf("%d",&n);
    vector<int> v(n);
    foi( i , 0 , n )
    {
      scanf("%d",&v[i]);
    }
    int a,b,may;
    a=b=may=0;
    if( n != 0 )
    {
      mp[v[0]]++;
    }
    else
      may-=1;
    while(a< n && b < n )
    {
      //  cout<<a<<" "<<b<<endl;
      if( b+1 < n && mp[v[b+1]]==0 )
      {
        b++;
        mp[v[b]]++;
        if( b-a > may)
          may=b-a;
      }
      else
      {
        mp[v[a]]--;
        a++;
      }
    }
    printf("%d\n",may+1);
  }
  return 0;
}
