#include <iostream>
#include <queue>
#include <stack>

using namespace std;
#define foi( i , k , n ) for( int i = k ; i <  n ; ++i)

bool funcion(queue<int> &in,queue<int> &num)
{
  stack<int> res;
  while( !in.empty() )
  {
    int n=in.front();
    in.pop();
    if( res.empty() || res.top() < n )
    {
      // cout<<"yes "<<n<<" "<<num.front()<<endl;
      while( n != num.front() && !num.empty() )
      {
        res.push(num.front());
        num.pop();
      }
      if( num.empty() )
        return false;
      num.pop();
    }
    else
    {
      // cout<<n<<" "<<res.top()<<endl;
      if( n != res.top() )
        return false;
      res.pop();
    }
  }
  return true;
}

int main()
{
  int t,c=0;
  while( scanf("%d",&t)!=EOF && t!= 0)
  {

    c++;
    int n;
    while( true ){
      scanf("%d",&n);
      if(n==0)
        break;
      queue<int> in,num;
      in.push(n);
      num.push(1);
      foi( i , 1 , t)
      {
        scanf("%d",&n);
        in.push(n);
        num.push(i+1);
        // cout<<i+1<<endl;
      }
      if( funcion(in,num) )
        printf("Yes\n");
      else
        printf("No\n");
    }
    printf("\n");
  }
  return 0;
}
