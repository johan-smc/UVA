#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

int xx[4]={-1,0,0,1};
int yy[4]={0,-1,1,0};
map<char,int> mp;


pair<int,int> sim(vector< vector<char> > &mat,vector< vector<int> > &pas,int x, int y,int llevo )
{
  // cout<<x<<" "<<y<<" "<<mat[x][y]<<" "<<mp[mat[x][y]]<<endl;
  if( pas[x][y]!=-1)
  {
    return make_pair(llevo,pas[x][y]);
  }
  pas[x][y]=llevo;
  int in=mp[mat[x][y]];
  int nextx=x+xx[in];
  int nexty=y+yy[in];
  if( nextx>= 0 && nextx < mat.size() && nexty >= 0 && nexty < mat[x].size() )
    return sim(mat,pas,nextx,nexty,llevo+1);

    return make_pair(llevo,-1);
}

int main()
{
  mp['N']=0;
  mp['S']=3;
  mp['W']=1;
  mp['E']=2;
  int x,y,ini;
  while( scanf("%d%d%d",&x,&y,&ini)!=EOF && (x||y||ini))
  {
    vector< vector<char> > mat(x,vector< char >(y) );
    vector< vector<int> > pas(x,vector< int >(y,-1) );
    foi( i , 0 , x )
    {
      foi( j , 0 , y )
      {
        scanf(" %c",&mat[i][j]);
      }
    }
    pair<int,int> res=sim(mat,pas,0,ini-1,1);
    if(res.second==-1){
      printf("%d step(s) to exit\n",res.first );
    }
    else
    {
      printf("%d step(s) before a loop of %d step(s)\n", res.second-1,res.first-res.second);

    }
  }
  return 0;
}
