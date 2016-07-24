#include <iostream>
#include <queue>

#define foi( i , n , k ) for(int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  int c;
  scanf("%d",&c);
  while(c--)
  {
    int l,m,lon;
    string dir;
    scanf("%d%d",&l,&m);
    l*=100;
    queue<int> left,right;
    foi( i , 0 , m )
    {
      scanf("%d",&lon);
      cin>>dir;
      if(dir=="left")
        left.push(lon);
      else
        right.push(lon);
    }
    bool pos=true;
    int tot=0;
    while( !left.empty() || !right.empty() )
    {
      int lm=0;
      if( pos  )
      {
        
        while( !left.empty() && lm+left.front() <= l )
        {
          lm+=left.front();
          left.pop();
        }
        pos=!pos;
      }
      else
      {
        while( !right.empty() && lm+right.front()  <= l )
        {
          lm+=right.front();
          right.pop();
        }
        pos=!pos;
      }
      tot++;
    }
    printf("%d\n",tot);
  }
  return 0;
}
