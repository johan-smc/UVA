#include <iostream>
#include <cstdio>
#include <vector>

#define foi( i ,  n , k ) for( int i = n ;  i < k ; ++i)
using namespace std;

int xx[8]={ 1,1,1,0,0,-1,-1,-1};
int yy[8]={-1,0,1,-1,1,-1,0,1};

void dfs(vector< vector< char > > &mat,int x, int y )
{
  mat[x][y]='.';
  foi( i , 0  , 8 )
  {
      int nextx=x+xx[i];
      int nexty=y+yy[i];
      if( nextx>= 0 && nextx < mat.size() && nexty>=0&& nexty< mat[x].size() && mat[nextx][nexty]=='@')
        dfs(mat,nextx,nexty);
  }
}


int main()
{
  int x,y;
  while( scanf("%d%d",&x,&y)!=EOF &&  (x||y) )
  {
    vector< vector< char > > mat(x,vector< char >(y));
    foi( i , 0 , x )
    {
      foi( j , 0 , y )
      {
        scanf(" %c",&mat[i][j]);
      }
    }
    int n=0;
    foi( i , 0 , x )
    {
      foi( j , 0 , y )
      {
        if(  mat[i][j]=='@' )
        {
         dfs(mat,i,j);
         ++n;
        }
      }
    }
    printf("%d\n",n);
  }
  return 0;
}
