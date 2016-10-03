#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define foi( i, n , k ) for( int i = n ; i <  k ; ++i)
using  namespace std;

bool bfs( vector< vector<int> > &graph)
{

  vector< bool >pas,color;
  pas=color=vector<bool> (graph.size(),false);
  queue<int> q;
  q.push(0);
  pas[0]=true;
  color[0]=false;
  while( !q.empty() )
  {
    int now=q.front();
    q.pop();
    foi( i , 0 , graph[now].size() )
    {
        int next=graph[now][i];
      if( !pas[next] )
      {
        pas[next]=true;
        color[next]=!color[now];
        q.push(next);
      }
      else  if( color[next]==color[now] )
        return false;
    }
  }
  return true;

}
int main()
{
  int t;
  while( scanf("%d",&t)!=EOF && t )
  {
    int n;
    scanf("%d",&n);
    vector< vector<int> > graph(t,vector<int>());
    foi( i , 0 , n )
    {
      int a,b;
      scanf("%d%d",&a,&b);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    if( bfs(graph) )
      printf("BICOLORABLE.\n" );
    else
      printf("NOT BICOLORABLE.\n" );
  }
  return 0;
};
