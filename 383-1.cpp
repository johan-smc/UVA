#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>

#define foi( i , n , k ) for( int i = n ; i <  k ; ++i )
#define vi vector<int>
using namespace std;

int bfs(vector< vector<int> > &graph,int ini, int fin )
{
  int llevo=0;
  vector<bool> pas(graph.size(),false);
  queue<pair<int,int> > q;
  q.push(make_pair(ini,0));
  pas[ini]=true;
  while(!q.empty())
  {
    int now=q.front().first;
    int pasos=q.front().second;
    q.pop();
    if( now==fin)
      return pasos;

    foi( i , 0 , graph[now].size() )
    {
      int next=graph[now][i];
      if(!pas[next])
      {
        pas[next]=true;
        q.push(make_pair(next,pasos+1));
      }
    }
  }
    return -1;
}

int main()
{
  printf("SHIPPING ROUTES OUTPUT\n");
  int t,cas=0;
  scanf("%d",&t);
  while(t--)
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    map<string,int> mp;
    vector< vector<int> > graph(a,vector<int>());
    string name;
    int cont=0;
    foi( i , 0 , a )
    {
      cin>>name;
      mp[name]=cont++;
    }
    string nameA,nameB;
    foi( i , 0 , b )
    {
      cin>>nameA>>nameB;
      graph[mp[nameA]].push_back(mp[nameB]);
      graph[mp[nameB]].push_back(mp[nameA]);
    }
    printf("\nDATA SET  %d\n\n",++cas);
    foi( i , 0 , c )
    {
      scanf("%d",&cont);
      cin>>nameA>>nameB;
      int tot=bfs(graph,mp[nameA],mp[nameB]);
      if( tot>=0 )
      {
        printf("$%d\n",cont*100*tot);
      }
      else
      {
        printf("NO SHIPMENT POSSIBLE\n");
      }
    }

  }
  printf("\nEND OF OUTPUT\n");
  return 0;
}
