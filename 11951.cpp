#include <iostream>
#include <cstdio>
#include <vector>

#define ll long long
#define vll vector<ll>
#define foi( i , n , k ) for( int  i = n ; i < k ; ++i )
#define LIM -9999999999999999L
using namespace std;

pair<ll,ll> sum(vector< vll > &mat,int lim)
{
  pair<ll,ll> ret;
  ret.first=LIM;
  ret.second=-LIM;
  foi( i , 0 , mat.size() )
  {
    vll sums(mat[i].size(),0);
    foi( j , i , mat.size() )
    {
      foi( k , 0 , mat[j].size() )
      {
        sums[k]+=mat[j][k];
      }
      ll may=LIM;
      ll ss=0;
      int tam=0;
      int mayT=0;
      foi( k , 0 , sums.size() )
      {
        ss+=sums[k];
        ++tam;
        if(ss>lim)
        {
          ss=sums[k];
          tam=1;
        }
        if( ss <= lim && mayT< tam)
        {
              may=ss;

          mayT=tam;
        }
        else if(ss <= lim && mayT== tam && may>ss)
        {
          may=ss;
        }
        if( ss < 0 )
        {
          ss=0;
          tam=0;
        }
      }
      tam=mayT*(j-i+1);
      cout<<may<<" "<<tam<<endl;
      if( ret.first < tam  )
      {
        ret.first=tam;
        ret.second=may;
      }
      else if(ret.first == tam && ret.second > may )
      {
        ret.second=may;
      }

    }
  }
  return ret;
}

int main()
{
  int t;
  scanf("%d",&t);
  foi( m , 0  , t)
  {
    int x,y;
    ll lim;
    scanf("%d%d%lld",&x,&y,&lim);
    vector< vll > mat(x,vll(y,0));
    foi( i , 0 , x )
    {
      foi( j , 0 , y )
      {
        scanf("%lld",&mat[i][j]);
      }
    }
    pair<ll,ll> res=sum(mat,lim);
    if(res.first==LIM || res.first==LIM)
      res=make_pair(0,0);
    printf("Case #%d: %lld %lld\n",m+1,res.first,res.second);
  }
  return 0;
}
