#include <iostream>
#include <vector>
#include <queue>

#define foi( i , n , k) for( int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  int x,y;
  while( scanf("%d%d",&x,&y) != EOF )
  {
    vector< vector <int> > mat(x,vector<int>(y,0));
    int r,c;
    foi( i , 0 , x)
    {
      scanf("%d",&r);
      queue<int> pos,dat;
      foi( j , 0 , r)
      {
        scanf("%d",&c);
        pos.push(c-1);
      }
      foi( j , 0 , r)
      {
        scanf("%d",&c);
        dat.push(c);
      }
      while(!pos.empty())
      {
        int p,d;
        p=pos.front();
        d=dat.front();
        pos.pop();
        dat.pop();
        mat[i][p]=d;
      }
    }
    printf("%d %d\n",y,x );
    foi( i , 0 , y)
    {
      queue<int> pos,dat;
      foi( j , 0 , x)
      {
        if( mat[j][i] )
        {
          pos.push(j);
          dat.push(mat[j][i]);
        }
      }
      printf("%d",(int)pos.size());
      if(pos.empty())
        printf("\n\n");
      else
      {
        while(!pos.empty()){
          printf(" %d",pos.front()+1);
          pos.pop();
        }
        printf("\n");
        while(!dat.empty()){
          printf("%d",dat.front());
          dat.pop();
          if(!dat.empty())
            printf(" " );
        }
        printf("\n");
      }
    }
  }
  return 0;
}
