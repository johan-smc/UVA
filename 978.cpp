#include <iostream>
#include <queue>

#define foi( i , n , k) for( int i = n ; i < k ; ++i )

using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  while( n-- )
  {
    int b,sg,sb,c;
    scanf("%d%d%d",&b,&sg,&sb);
    priority_queue<int> blue,green;
    foi( i , 0 , sg )
    {
      scanf("%d",&c);
      green.push(c);
    }
    foi( i , 0 , sb )
    {
      scanf("%d",&c);
      blue.push(c);
    }
    while( !green.empty() && !blue.empty() )
    {
      // cout<<green.size() <<" "<<blue.size() <<endl;
      queue<int> tb,tg;
      for( int i = 0 ; i < b && !green.empty() && !blue.empty() ;++i  )
      {
        int g,b;
        g=green.top();
        green.pop();
        b=blue.top();
        blue.pop();
        if( b-g > 0 )
        {
          tb.push(b-g);
        }
        else if( g-b > 0)
        {
          tg.push( g-b );
        }
      }
      while( !tb.empty() )
      {
        blue.push(tb.front());
        tb.pop();
      }
      while( !tg.empty() )
      {
        green.push(tg.front());
        tg.pop();
      }
    }
    if( green.empty() && blue.empty() )
    {
      printf("green and blue died\n");
    }
    else if( !green.empty() && blue.empty() )
    {
      printf("green wins\n");
      while( !green.empty() )
      {
        printf("%d\n",green.top());
        green.pop();
      }
    }
    else if( !blue.empty() && green.empty() )
    {
      printf("blue wins\n");
      while( !blue.empty() )
      {
        printf("%d\n",blue.top());
        blue.pop();
      }
    }
    if( n != 0 )
      printf("\n" );
  }
  return 0;
}
