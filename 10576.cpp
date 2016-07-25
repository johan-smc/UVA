#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k)for(int i =  n ; i < k ; ++i)
using namespace std;

void back(vector<int>temp,int &out,int x,int s,int d)
{
  if(x<12)
  {
    temp[x]=s;
    back(temp,out,x+1,s,d);
    temp[x]=-d;
    back(temp,out,x+1,s,d);
  }
  else
  {
    int m=0;
    int ntemp=0;
    foi( i, 0 ,5 )
    {
      // cout<<i<<" ";
      if(ntemp<0)
      return;
      ntemp+=temp[i];

      m+=temp[i];
    }
    // cout<<endl;
    // cout<<" ntemp "<<ntemp<<endl;
    if(ntemp>0)
      return;
    foi( i , 0 , 7 )
    {
      // cout<<i+5<<" ";
      ntemp-=temp[i];
      ntemp+=temp[i+5];
      // cout<<ntemp<<" ntemp"<<endl;
      if(ntemp>0)
        return;


      m+=temp[i];
      // cout<<"m "<< m<<endl;
    }
    // cout<<endl;
    // cout<<"final"<<endl;
    if(m>out)
    {
      // cout<<"cambie "<<m<<" "<<out<<endl;
     foi( i , 0 ,12)
      // cout<<temp[i]<<" ";
      // cout<<endl;

      out=m;
    }
  }
}
int main()
{
  int s,d;
  vector<int> v(12);
  while(scanf("%d%d",&s,&d)!=EOF)
  {
    int out=-1;
    back(v,out,0,s,d);
    if(out<=0){
      printf("Deficit\n");
    }
    else
      printf("%d\n",out);
  }
  return 0;
}
