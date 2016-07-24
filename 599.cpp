#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define foi(i,n,k) for( int i = n ; i < k ; ++i )
using namespace std;

int dfs(map< char , vector< char > > &mp,map< char , bool > &pas,char estoy)
{
  int num=1;
  // cout<<estoy<<endl;
  pas[estoy]=true;
  vector<char> next=mp[estoy];
  foi( i , 0 , next.size() )
  {
    if(!pas[next[i]])
    {
      // cout<<"voy "<<next[i]<<" llevo "<<num<<endl;
      num+=dfs(mp,pas,next[i]);
    }
  }
  return num;
}

int main()
{
  int n;
  string line;
  scanf("%d",&n);
  while( n-- )
  {
    map< char , vector< char > > mp;
    map< char , bool > pas;
    while( cin>>line && line[0]!='*')
    {
      if( mp.find(line[1])== mp.end() )
      {
        mp.insert(make_pair(line[1],vector<char>()));
      }
      if( mp.find(line[3])== mp.end() )
      {
        mp.insert(make_pair(line[3],vector<char>()));
      }

      mp[line[3]].push_back(line[1]);
      mp[line[1]].push_back(line[3]);
    }
    cin>>line;
    queue<char> gp;
    for( int i = 0 ; i < line.size() ; i+=2 )
    {
      gp.push(line[i]);
      pas[line[i]]=false;
    }
    int tree,acorns;
    tree=acorns=0;
    while( !gp.empty() )
    {
      char temp=gp.front();
      gp.pop();
      if(!pas[temp])
      {
        int c=dfs(mp,pas,temp);
        if(c==1)
          acorns++;
        else
          tree++;
      }
    }
    printf("There are %d tree(s) and %d acorn(s).\n",tree,acorns);

  }
  return 0;
}
