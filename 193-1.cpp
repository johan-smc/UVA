#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k) for( int i = n ; i < k ; ++i)
using namespace std;

bool es(int node,vector< vector < int > > &v,vector <bool>&mark  )
{
  foi( i , 0 , (int)v[node].size() )
  {
    if( !mark[v[node][i]])
      return false;
  }
  return true;
}

void back( int node,vector< vector < int > > &v,vector <bool>&mark,vector<int>&res,int &max,int temp,vector<int>gtemp )
{
  if( node == (int)v.size() )
  {
    if( max <= temp )
    {
      max=temp;
      res=gtemp;
    }
  }
  else
  {
    if( es(node,v,mark) )
    {
      mark[node]=false;
      gtemp[temp]=node;
      temp++;
      back(node+1,v,mark,res,max,temp,gtemp);
      temp--;
      mark[node]=true;
    }
    back(node+1,v,mark,res,max,temp,gtemp);
  }
}

int main()
{
  int m;
  scanf("%d",&m);
  while(m--)
  {
    int n,k,max=0;
    scanf("%d%d",&n,&k);
    vector< vector < int > > v(n,vector<int>());
    vector<int> res(n);
    vector< bool > mark(n,true);
    foi( i , 0 ,k )
    {
      int a,b;
      scanf("%d%d",&a,&b);
      a--;
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    /*foi( i , 0 , n )
    {
      cout<<i<<" - ";
      foi( j  , 0 , v[i].size() )
        cout<<v[i][j]<<" ";
      cout<<endl;
    }*/
    back(0,v,mark,res,max,0,vector<int>(n));
    printf("%d\n",max);
    foi( i , 0 , max)
    {
      if( i != 0 )
        printf(" ");
      printf("%d",res[i]+1);
    }
    printf("\n");
  }

  return 0;
}
