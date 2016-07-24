#include <iostream>
#include <cstdio>
#include <vector>

#define foi( i , n , k ) for( int i = n ;i < k ; ++i )

using namespace std;


bool arr[10][7]=
{
  {1,1,1,1,1,1,0},{0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},{1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},{1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},{1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},{1,1,1,1,0,1,1}
};

int pos(vector<bool> v, int n )
{
  foi( i , 0 , 7 )
  {
    if(v[i] && !arr[n][i] )
      return -1;
  }
  return n;
}

bool funcion(vector< vector<bool> > &v,int row,int nmin,vector<bool> pas)
{
  if(row==-1)
  {
    return true;
  }
  if( nmin==-1)
  {
    foi( i , 0 , 10 )
    {
      int n = pos(v[row],i);
      if( n>=0)
      {
        pas[n]=true;
        if(funcion(v,row-1,n,pas) )
          return true;
        pas[n]=false;
      }
    }
    return false;
  }
  else
  {
    int n = pos(v[row],nmin+1);
    bool p=true;
    if( n!=-1)
    {
      p=pas[n];
      if(!pas[n])
        pas[n]=true;
      }
    if( n>=0  && !p &&funcion(v,row-1,n,pas))
    {

       return true;
    }
    return false;
  }
}


int main()
{
  int n;
  while( scanf("%d",&n)!=EOF && n!=0)
  {
    vector< vector < bool > > v(n,vector<bool>(7,false));
    vector< bool > pas(12,false);
    string pal;
    foi( i , 0 , n )
    {
      cin>>pal;
      foi( j , 0 , pal.size() )
      {
        if(pal[j]=='Y')
          v[i][j]=true;
        else
          v[i][j]=false;
      }
    }
    if(funcion( v, n-1,-1 ,pas ))
      printf("MATCH\n");
    else
      printf("MISMATCH\n");
  }
  return 0;
}
