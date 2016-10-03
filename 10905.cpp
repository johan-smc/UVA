#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define foi(i , n , k) for( int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF && n )
  {
    string str;
    vector<string> v;
    foi( i , 0 , n )
    {
      cin>>str;
      v.push_back(str);
    }
    sort(v.begin(),v.end());
    foi( i , 0 , v.size() )
      cout<<v[i];
    cout<<endl;
  }
  return 0;
}
