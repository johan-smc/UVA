#include <iostream>
#include <cstdio>
#include <vector>

#define foi( i , n , k ) for( int i =  n ; i < k ; ++i )
using namespace std;

void dfs( vector< vector<int> > &graph,vector<int>&res,vector<bool> &pas,int node)
{
  if( pas[node] )
    return;
  pas[node]=true;
  foi( i , 0 , graph[node].size() )
  {
    dfs(graph,res,pas,graph[node][i]);
  }
  res.push_back(node);
}

int main()
{
  int n,v;
  while( scanf("%d%d",&n,&v)!=EOF && (n||v) )
  {
    vector< vector<int> > graph(n,vector<int>());
    vector< bool > pas(n,false);
    foi( i , 0,  v )
    {
      int a,b;
      scanf("%d%d",&a,&b);
      --a;
      --b;
      graph[a].push_back(b);

    }
    vector<int> res;
    foi( i , 0 , n )
      dfs(graph,res,pas,i);
    for( int  i = res.size()-1 ; i >= 0 ; --i  )
    {
      if( i!= res.size()-1)
        printf(" ");
      printf("%d",res[i]+1);
    }
    printf("\n");
  }
  return 0;
}
