#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
#include <queue>

#define foi( i , n , k )for(int i =  n ; i <  k ; ++i)
using namespace std;


void back(set< deque<int> >&sq,deque<int>q,vector<int>&v,int sum,int pos,int t)
{
  if(sum>t)
    return;
  if( sum == t)
  {
    if(sq.find(q)==sq.end())
    {
      sq.insert(q);
      while(!q.empty())
      {
        printf("%d",q.front());
        q.pop_front();
        if(!q.empty())
          printf("+");
      }
      printf("\n");
    }
    return;
  }
  foi( i , pos , (int)v.size() )
  {
    q.push_back(v[i]);
    back(sq,q,v,sum+v[i],i+1,t);
    q.pop_back();
  }
}

int main()
{
  int t,n;
  while( scanf("%d%d",&t,&n)!=EOF && n!=0)
  {
    vector<int> v(n);
    foi( i , 0  , n )
    {
      scanf("%d",&v[i]);
    }
    printf("Sums of %d:\n",t);
    set< deque< int > > sq;
    deque<int> q;
    back(sq,q,v,0,0,t);
    if(sq.empty())
      printf("NONE\n" );
  }
  return 0;
}
