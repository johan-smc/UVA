#include <iostream>
#include <queue>
#include <stack>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )

using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF )
  {
    int c,nn;
    bool s,q,pq;
    s=q=pq=true;
    queue<int> rq;
    priority_queue<int> rpq;
    stack<int> rs;
    foi( i , 0 , n )
    {
      scanf("%d%d",&c,&nn);
      if( c == 1 )
      {
        rq.push(nn);
        rpq.push(nn);
        rs.push(nn);
      }
      else if( c == 2 )
      {
        if( !rq.empty())
        {
          if( rq.front() != nn )
            q=false;


            rq.pop();
        }
        else
          q=false;

        if(!rpq.empty())
        {
          if( rpq.top() != nn )
            pq=false;

            rpq.pop();
        }
        else
          pq=false;

        if(!rs.empty())
        {
          if( rs.top() != nn )
            s=false;

            rs.pop();
        }
        else
          s=false;

      }
    }
    if( q && !pq && !s)
    {
      printf("queue\n");
    }
    else if( !q && pq && !s)
    {
      printf("priority queue\n");
    }
    else if( !q && !pq && s)
    {
      printf("stack\n");
    }
    else if( !q && !pq && !s )
    {
      printf("impossible\n");
    }
    else
    {
      printf("not sure\n");
    }
  }
  return 0;
}
