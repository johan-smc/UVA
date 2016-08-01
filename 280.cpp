#include <iostream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <queue>


#define foi( i , n , k ) for( int i = n ; i <k ; ++i)
using namespace std;

void bfs(vector< vector<int> > &gra,bitset<105> &pas,int ini)
{
  queue<int> q;
  q.push(ini-1);
  int c=0;
  while(!q.empty())
  {
    if(c++!=0)
      pas[q.front()]=true;
    int x=q.front();
    q.pop();
    foi( i , 0 , gra[x].size() )
    {
      if( !pas[gra[x][i]] )
      {
        q.push(gra[x][i]);
      }
    }
  }
}

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF && n!=0)
  {
    vector< vector<int> > gra(n,vector<int>());
    int in;
    while(scanf("%d",&in)!=EOF && in!=0)
    {
      int des;
      while( scanf("%d",&des)!=EOF && des!=0)
      {
        gra[in-1].push_back(des-1);
      }
    }
    // cout<<"llegue"<<endl;
    int k;
    scanf("%d",&k);
    foi( j , 0 , k )
    {
      scanf("%d",&in);
      bitset<105> pas;
      bfs(gra,pas,in);
      printf("%d",n-(int)pas.count());
      foi( i , 0 , n)
      {
        if( !pas[i])
        {
          printf(" %d",i+1);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
