#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>

#define foi( i , k , n ) for( int i = k ;  i <  n ; ++i )
using namespace std;

void print(vector< queue<int> > a)
{
  foi( i , 0 , a.size() )
  {
    cout<<i<<" -- ";
    while( !a[i].empty() )
    {
      cout<<a[i].front()<<" ";
      a[i].pop();
    }
    cout<<endl;
  }
}

void print( stack<int> q)
{
  while( !q.empty() )
  {
    cout<<q.top()<<" ";
    q.pop();
  }
  cout<<endl;
}
int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int n,c,m;
    scanf("%d%d%d",&n,&c,&m);
    int q,cc,time=0;
    std::vector< queue<int> > v(n,queue<int>());
    bitset<105> ps;
    foi( i , 0 , n )
    {
      scanf("%d",&q);
      foi( j , 0 , q)
      {
        ps[i]=true;
        scanf("%d",&cc);
        v[i].push(cc-1);
      }
    }
    int pos=0;
    stack<int> mov;
    while( ps.any() || !mov.empty())
    {
      // cout<<"---------------------------"<<endl;
      // cout<<ps<<endl;
      // print(v);
      // cout<<".. "<< pos << " ...";
      // print(mov);
      // cout<<"t "<<time<<endl;
      while( !mov.empty()  && v[pos].size() < m)
      {
        if( mov.top() == pos )
          mov.pop();
        else
        {
            v[pos].push(mov.top());
            mov.pop();
        }
        ++time;
      }
      while( !mov.empty() && mov.top() == pos )
      {
        mov.pop();
        ++time;
      }
      while( mov.size()  <  c && !v[pos].empty() )
      {
        mov.push(v[pos].front());
        v[pos].pop();
        ++time;
      }
      if( v[pos].empty() )
        ps[pos]=false;
      pos++;
      pos%=n;
      time+=2;
      // cout<<"t "<<time<<endl;
      // cout<<".. "<< pos << " ...";
      // print(mov);
      // print(v);
      // cout<<ps<<endl;
      // cout<<"---------------------------"<<endl;
    }
    printf("%d\n",time-2 );
  }
  return 0;
}
