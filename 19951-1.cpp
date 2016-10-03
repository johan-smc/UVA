#include <iostream>
#include <cstdio>
#include <vector>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
#define LIM 9999999999999999L
#define ll long long
#define vll vector< ll >
using namespace std;

void matDP ( vector< vll >& mat)
{
  foi( i , 0 , mat.size() )
  {
    foi( j , 0 , mat[i].size() )
    {
        mat[i][j]=mat[i][j];
        if( i-1 >= 0)
        {
          mat[i][j]+=mat[i-1][j];
        }
        if( j-1 >= 0)
        {
          mat[i][j]+=mat[i][j-1];
        }
        if( i-1 >= 0 && j-1 >= 0)
        {
          mat[i][j]-=mat[i-1][j-1];
        }
        // cout<<mat[⁄i][j]<<" ";
    }
    // cout<<endl;
  }
}
pair<ll,ll> sumMax(vector< vll >& mat,ll lim)
{
  pair<ll,ll> res(0,0);
  foi( i , 0 , mat.size() )
    foi( j , 0 , mat[i].size() )
      foi( k , i , mat.size() )
        foi( l , j , mat[i].size() )
        {
          ll temp=mat[k][l],tamTemp=((k-i)+1)*((l-j)+1);

          if( i > 0 )
            temp-=mat[i-1][l];
          if( j > 0 )
            temp-=mat[k][j-1];
          if( i > 0 && j > 0 )
            temp+=mat[i-1][j-1];
          // cout<<i<<" "<<k<<" "<<j<<" "<<l<<" "<<tamTemp<<" "<<temp<<" "<<lim<<endl;
          if(temp<=lim && temp >= 0){
            if(res.first<tamTemp)
            {
              res=make_pair(tamTemp,temp);
            }
            else if(res.first==tamTemp)
            {
              res.second=min(temp,res.second);
            }

          }
        }
  return res;
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
    vector< vll > mat;
    mat=mat=vector< vll >(x,vll(y,0));
    foi( i , 0 , x )
    {
      foi( j , 0 , y )
      {
        scanf("%lld",&mat[i][j]);
      }
    }
    matDP(mat);
    pair<ll,ll> res=sumMax(mat,lim);
    printf("Case #%d: %lld %lld\n",m+1,res.first,res.second);
  }
  return 0;
}
