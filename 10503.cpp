#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i ,  n , k )for( int i = n ; i < k ; ++i)
using namespace std;

bool back(int pos,vector< pair<int,int> > &v,vector<bool>vp,pair<int,int> ini,pair<int,int>fin,int n)
{
  if(pos==n)
    return true;
  if(pos==n-1)
  {
    // cout<<"entre -fin"<<endl;
    foi( i , 0 , (int)v.size() )
    {
      if(vp[i])
      {
        vp[i]=false;
        if(v[i].first==ini.second && (v[i].second==fin.first))
          return true;
        if(v[i].second==ini.second && (v[i].first==fin.first))
          return true;
        vp[i]=true;
      }
    }
    return false;
  }
  else
  {
    // cout<<"entre "<<pos<<endl;
    foi( i , 0 , (int)v.size() )
    {
      if( vp[i] && (v[i].first==ini.second||v[i].second==ini.second) )
      {
        vp[i]=false;
        if(v[i].first==ini.second && back(pos+1,v,vp,v[i],fin,n))
          return true;
        if(v[i].second==ini.second && back(pos+1,v,vp,make_pair(v[i].second,v[i].first),fin,n) )
          return true;
        vp[i]=true;
      }
    }
  }
  return false;
}


int main()
{
  int n,m;
  while( scanf("%d",&n) != EOF && n!=0)
  {
    scanf("%d",&m);
    pair<int,int> ini,fin;
    scanf("%d%d%d%d",&ini.first,&ini.second,&fin.first,&fin.second);
    vector< pair<int,int> > v(m);
    vector<bool> vp(m,true);
    foi(   i , 0 , m )
    {
      scanf("%d%d",&v[i].first,&v[i].second);
    }
    if(back(0,v,vp,ini,fin,n))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
