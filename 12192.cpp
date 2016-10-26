#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int i =  n ; i < k ; ++i )
using namespace std;

int funcion(std::vector< std::vector<int> > &mat,int a,int b)
{
  int may=0;
  foi( i , 0 , mat.size() )
  {
    int e=lower_bound(mat[i].begin(),mat[i].end(),a)-mat[i].begin();
    int r=i,temp=0;
    while( r<mat.size() && e<mat[r].size() && mat[r][e]<= b)
    {
      ++temp;
      ++r;
      ++e;
    }
    may=max(may,temp);
  }
  return may;
}

int main()
{
  int x,y;
  while( scanf("%d%d",&x,&y )!=EOF && (x!=0||y!=0))
  {
      std::vector< std::vector<int> > mat(x,std::vector<int> (y,0));
      foi( i ,  0 , x )
        foi( j , 0 , y )
          scanf("%d",&mat[i][j] );
      int a,b;
      int t;
      scanf("%d",&t );
      while( t-- )
      {
        scanf("%d%d",&a,&b );
        printf("%d\n",funcion(mat,a,b) );
      }
      printf("-\n" );
  }

  return 0;
}
