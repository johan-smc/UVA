#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define foi( i , n , k) for(int i = n ; i < k ; ++i )

using namespace std;

int back(vector< vector<int> >&v,int pos,vector<int>fin,vector<bool>col,vector<bool>row,vector<bool>d1,vector<bool>d2)
{
  // cout<<pos<<" -- "<<endl;
  if( pos==8 )
  {
    v.push_back(fin);
  }
  else
  {
    int mn=9999;
    foi( i , 0 ,8 )
    {

      if( !col[i]&&!row[pos] && !d1[pos+i] && !d2[pos-i+7] )
      {
        row[pos]=true;
        col[i]=true;
        d1[pos+i]=true;
        d2[pos-i+7]=true;
        fin[i]=pos;
        back(v,pos+1,fin,col,row,d1,d2);
        // cout<<mn<<" "<<temp<<endl;

        fin[i]=-1;
        col[i]=false;
        row[pos]=false;
        d1[pos+i]=false;
        d2[pos-i+7]=false;
      }
    }
    return mn;
  }

}

int funcion(vector< vector<int> >&v,vector<int>&in)
{
  int me=9999;
  foi( i , 0 , (int)v.size() )
  {
    int sum=0;
    foi( j , 0 ,(int)v[i].size() )
    {
      // cout<<v[i][j]<<" "<<in[j]<<endl;
      if(v[i][j]!=in[j])
        sum++;
    }
    // cout<<sum<<endl;
    me=min(me,sum);
  }
  return me;
}

int main()
{
  int n,t=0;
  vector<int> in(8),fin(8);
  vector< vector<int> > v;
  vector<bool> row(8,false),col(8,false),d1(15,false),d2(15,false);
  back(v,0,fin,col,row,d1,d2);
  while(scanf("%d",&n)!=EOF)
  {
    in[0]=n-1;
    foi( i , 0 , 7){
      scanf("%d",&in[i+1]);
      in[i+1]--;
    }
    printf("Case %d: %d\n",++t,funcion(v,in));
  }
  return 0;
}
