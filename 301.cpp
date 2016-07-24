#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ticket
{
  int begin,end,p;
  bool operator<(const Ticket &o)const
  {
    return (this->begin==o.begin)?this->end<o.end:this->begin<o.begin;
  }
};

bool verificar(Ticket ti,vector<int> q,int limit)
{
  for( int i = ti.begin ; i < ti.end ; ++i)
  {
      if(q[i]+ti.p>limit)
        return false;
  }
  return true;
}
int fun(vector<Ticket> &ti,int x,int val,vector<int> q,int limit)
{
  // cout<<" …… "<<x<<" "<<val<<" "<<limit<<endl;
  if(x>=ti.size())
    return val;
  for( int i = ti[x].begin; i < ti[x].end ; ++i)
  {
      q[i]+=ti[x].p;
  }
  int may=val;
  for( int i = x+1 ; i < ti.size() ; ++i )
  {
    if( verificar(ti[i],q,limit) )
      may=max(may,fun(ti,i,val+(ti[i].p*(ti[i].end-ti[i].begin)),q,limit));
  }
  return may;
}

int main()
{
  int n,b,t;
  while( scanf("%d%d%d",&n,&b,&t)!=EOF&&(n!=0||b!=0||t!=0))
  {
    vector<Ticket> ti(t);
    for( int i = 0 ; i < t ; ++i )
    {
      scanf("%d%d%d",&ti[i].begin,&ti[i].end,&ti[i].p);
    }
    sort(ti.begin(),ti.end());
    int may=0;
    std::vector<int> q(b+1,0);
    for( int i = 0 ; i < t ; ++i )
    {
      if(verificar(ti[i],q,n))
        may=max(fun(ti,i,(ti[i].p*(ti[i].end-ti[i].begin)),q,n),may);
    }
    printf("%d\n",may );
  }
  return 0;
}
