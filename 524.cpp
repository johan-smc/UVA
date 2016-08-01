#include <iostream>
#include <vector>
#include <cstdio>

#define TAM 50
#define foi( i ,  n , k )for(int i = n ; i <k ; ++i)
using namespace std;

vector<bool> pri;

void criba()
{
  pri.assign(TAM,true);
  pri[0]=pri[1]=false;
  foi( i , 2 , TAM )
  {
    if( pri[i])
    {
      for( int j =  i*i ; j < TAM ; j+=i )
      {
        pri[j]=false;
      }
    }
  }
}

void back( vector<int> res,vector<bool> bb,int pos ,int n)
{
  if( pos == n )
  {
    foi( i , 0 , (int)res.size() )
    {
      if(i!=0)
        printf(" ");
      printf("%d",res[i]);
    }
    printf("\n");
  }
  else
  {
    foi( i , 1 , (int)bb.size() )
    {
      if( bb[i] && pri[res[pos-1]+i+1] && ((pos==n-1)?pri[i+1+res[0]]:true))
      {
        bb[i]=false;
        res[pos]=i+1;
        back(res,bb,pos+1,n);
        res[pos]=-1;
        bb[i]=true;
      }
    }
  }
}

int main()
{
  criba();
  int n,c=0;
  while(scanf("%d",&n)!=EOF)
  {
    if(c!=0)
      printf("\n");
    printf("Case %d:\n",++c);
    if(n!=0){
      vector<int> res(n);
      res[0]=1;
      vector<bool> bb(n,true);
      bb[0]=false;
      back(res,bb,1,n);
    }
  }
  return 0;
}
