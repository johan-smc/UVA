#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <set>
#include <cstdio>
#include <queue>

#define foi( i , n , k ) for(  int  i = n ; i < k ; ++i)
using namespace std;

int funcion(  map< int , vector<int> > &mp,set<int> &st,int n)
{
  bool cam=true;
  int c=0;
  map< int , vector<int> >::iterator it;
  queue<int> q;
  while( cam && st.size() < n)
  {
    c++;
    // cout<<c<<endl;
    cam=false;
    for( it=mp.begin() ; it!=mp.end() ; ++it)
    {
      if( st.find(it->first)==st.end() )
      {
        int t=0;
        foi( i , 0 , it->second.size() )
        {
          if( st.find(it->second[i])!=st.end() )
            t++;
        }
        if( t>2 )
        {
          cam=true;
          q.push(it->first);
        }
      }
    }
    while(!q.empty())
    {
      st.insert(q.front());
      q.pop();
    }
  }
  if( st.size()>= n)
  {
    return c;
  }
  return -1;
}

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF)
  {
    int c;
    char a,b;
    scanf("%d",&c);
    set<int> st;
    // cout<<n<<" "<<c<<endl;
    foi( i , 0 , 3 )
    {
      scanf(" %c",&a);
      st.insert(a-'A');
      // cout<<a<<endl;
    }
    map< int , vector<int> > mp;
    foi( i , 0 , c )
    {
      scanf(" %c%c",&a,&b);
      // cout<<a<<" "<<b<<" "<<a-'A'<<" "<<b-'A'<<endl;
      int aa,bb;
      aa=a-'A';
      bb=b-'A';
      if( mp.find(aa)==mp.end() )
      {
        mp.insert(make_pair(aa,vector<int>()));
      }
      if( mp.find(bb)==mp.end() )
      {
        mp.insert(make_pair(bb,vector<int>()));
      }
      mp[aa].push_back(bb);
      mp[bb].push_back(aa);
    }
    int tot=-1;
    // cout<<mp.size() << " " << st.size() << " " << n << endl;
    if( mp.size() == n || st.size() == n )
      tot=funcion(mp,st,n);
    if( tot < 0 )
    {
      printf("THIS BRAIN NEVER WAKES UP\n");
    }
    else
    {
      printf("WAKE UP IN, %d, YEARS\n",tot);
    }
  }
  return 0;
}
