#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <set>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )

using namespace std;

void back(int r,set <vector<int> >&s, int pos ,vector<bool> &row,vector<bool> &col,vector<bool> &ab,vector<bool> &ar ,vector<int>res)
{
  if(pos==8)
  {
    s.insert(res);

  }
  else
  {
    if(row[r])
      r++;
      foi( j , 0 , 8)
      {
        if(!row[r]&&!col[j]&&!ab[7+(j-r)]&&!ar[j+r])
        {
          // cout<<r<<" "<<j<<endl;
          row[r]=true;
          col[j]=true;
          ab[7+(j-r)]=true;
          ar[j+r]=true;
          res[j]=r;
          back(r+1,s,pos+1,row,col,ab,ar,res);
          res[j]=-1;
          row[r]=false;
          col[j]=false;
          ab[7+(j-r)]=false;
          ar[j+r]=false;
        }
      }

  }
}
int main()
{
  int n;
  scanf("%d",&n);
  while( n-- )
  {
    int x,y;
    vector<bool> row(8,false),col(8,false),ab(16,false),ar(16,false);
    vector<int> res(8);

    scanf("%d%d",&x,&y);
    x--;
    y--;
    res[y]=x;
    row[x]=true;
    col[y]=true;
    ab[7+(y-x)]=true;
    ar[y+x]=true;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    set< vector<int> > s;
    back(0,s,1,row,col,ab,ar,res);
    int c=0;
    set< vector<int> >::iterator it;
    for( it = s.begin() ; it!=s.end() ; ++it)
    {
      if(c < 9 )
        printf(" " );
      printf("%d     ",++c );

      foi( i , 0 , 8)
      {
        printf(" %d",(*it)[i]+1 );
      }
      printf("\n" );
    }
    if(n!=0)
    printf("\n");
  }
  return 0;
}
