#include <bits/stdc++.h>
using namespace std;
#define foi( i , k , n ) for( int i = k ; i < n ; i++ )

void funcion(vector< vector< char > > &pri,vector< vector< char > > &sec,vector< vector< char > > &res,queue< pair< int , int > > &first,queue< pair< int , int > > & second,char op )
{
  while( !first.empty() )
  {
    int x,y;
    pair<int,int> a,b;
    a=first.front();
    b=second.front();
    first.pop();
    second.pop();
    x=b.first-a.first;
    y=b.second-a.second;
    // cout<<" a "<<x<<" "<<y<<" "<<endl;
    x+=b.first;
    y+=b.second;
    // cout<<x<<" "<<y<<endl;
    if( x >= 0 && x < res.size() && y >= 0 && y < res[x].size() )
      res[x][y]=op;
  }
  foi( i , 0 , res.size() )
  {
    foi( j , 0 , res[i].size() )
    {
      if( res[i][j] == ' ')
      {
        if( pri[i][j] == op )
          res[i][j]=sec[i][j];
        else
          res[i][j]=pri[i][j];
      }
    }
  }
}
int main()
{
  int n,m;
  char op;
  char a,b;
  int c=0;
  while( scanf("%d%d %c%c%c",&n,&m,&a,&op,&b) != EOF && (n!=0||m!=0||op!=' '))
  {

    //cout<<op<<endl;
    vector< vector< char > > pri,sec,res;
    pri=sec=res=vector< vector<char> >(n,vector< char >(m,' '));
    queue< pair<int,int> > first,second;
    foi( i, 0 , n)
      foi( j , 0 , m )
      {
        cin>>pri[i][j];
        // cout<<pri[i][j];
        if( pri[i][j]==op)
          first.push(make_pair(i,j));
      }
    foi( i, 0 , n)
      foi( j , 0 , m )
      {
        cin>>sec[i][j];
        if( sec[i][j]==op)
          second.push(make_pair(i,j));
      }
    funcion( pri,sec,res,first,second,op);
    foi( i, 0 , n)
    {
     foi( j , 0 , m )
      {
        printf("%c",res[i][j]);
      }
      printf("\n");
    }
    printf("\n" );
  }
  return 0;
}
