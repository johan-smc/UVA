#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

int LSOne( int b)
{
    return b&(-b);
}
class FenwickTree
{
  private:
    vector<int> ftp,ftn,ft0;
    vector<int> rftp,rftn,rft0;
  public:
    FenwickTree( int n )
    {
      ftp.assign(n+1,0);
      ftn.assign(n+1,0);
      ft0.assign(n+1,0);
      rftp.assign(n+1,0);
      rftn.assign(n+1,0);
      rft0.assign(n+1,0);
    }
    int rsqp( int b)
    {
      int sum=0;
      for(;b;b-=LSOne(b))
        sum+=ftp[b];
      return sum;
    }
    int rsqp( int a, int b)
    {
      return rsqp(b)-(a==1?0:rsqp(a-1));
    }
    void adjustp( int k , int v)
    {
      if( rftp[k]==1 && v!=-1)
        return;
      else if( rft0[k]==1 )
      {
        adjust0(k,-1);
      }
      else if( rftn[k]==1)
      {
        adjustn(k,-1);
      }
      rftp[k]+=v;
      for(; k < ( int ) ftp.size() ; k+=LSOne(k))
        ftp[k]+=v;
    }
    int rsqn( int b)
    {
      int sum=0;
      for(;b;b-=LSOne(b))
        sum+=ftn[b];
      return sum;
    }
    int rsqn( int a, int b)
    {
      return rsqn(b)-(a==1?0:rsqn(a-1));
    }
    void adjustn( int k , int v)
    {
      if( rftn[k]==1 && v!=-1)
        return;
      else if( rftp[k]==1 )
      {
        adjustp(k,-1);
      }
      else if( rft0[k]==1)
      {
        adjust0(k,-1);
      }
      rftn[k]+=v;
      for(; k < ( int ) ftn.size() ; k+=LSOne(k))
        ftn[k]+=v;
    }
    int rsq0( int b)
    {
      int sum=0;
      for(;b;b-=LSOne(b))
        sum+=ft0[b];
      return sum;
    }
    int rsq0( int a, int b)
    {
      return rsq0(b)-(a==1?0:rsq0(a-1));
    }
    void adjust0( int k , int v)
    {
      // cout<<".....  "<<k<<" "<<v<<endl;
      if( rft0[k]==1 && v!=-1)
        return;
      else if( rftp[k]==1 )
      {
        adjustp(k,-1);
      }
      else if( rftn[k]==1)
      {
        adjustn(k,-1);
      }
      rft0[k]+=v;
      for(; k < ( int ) ft0.size() ; k+=LSOne(k))
        ft0[k]+=v;
    }
};

void change( int a, int b, FenwickTree &ft)
{
  if( b < 0 )
  {
    ft.adjustn(a,1);
  }
  else if( b == 0)
  {
    ft.adjust0(a,1);
  }
  else
  {
    ft.adjustp(a,1);
  }
}

char imp( int a , int b, FenwickTree &ft)
{
  if(ft.rsq0(a,b)>0)
    return '0';
  if( ft.rsqn(a,b)%2==0)
    return '+';
  else
    return '-';
}

int main()
{
  int n,k;
  while( scanf("%d%d",&n,&k)!=EOF)
  {
    FenwickTree ft(n);
    int c;
    foi( i , 1 , n+1 )
    {
      scanf("%d",&c);
      if(c<0)
        ft.adjustn(i,1);
      else if( c == 0)
        ft.adjust0(i,1);
      else
        ft.adjustp(i,1);
    }
    foi( i , 0 , k )
    {
      char o;
      int a,b;
      scanf( " %c%d%d",&o,&a,&b);
      if(o=='C')
      {
        change(a,b,ft);
      }
      else
      {
        printf("%c",imp(a,b,ft));
      }
    }
    printf("\n");
  }
  return 0;
}
