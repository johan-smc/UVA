#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int i  = n ; i < k  ; ++i )
#define INF -99999999999999999LL
using namespace std;

long long sum( vector< vector< vector<long long> > > &cube,long long i,long long j,long long k,long long m,long long n)
{
  long long tot=0;
  foi( ii , i , j+1 )
  {
    foi( jj , k , m+1 )
    {
      tot+=cube[ii][jj][n];
    }
  }
  return tot;
}

long long mayor( vector< vector< vector<long long> > > &cube,long long x,long long y,long long z)
{
  vector<long long> arr(z);
  long long may=0,ss=0;
  long long mayTot=INF;
  foi( i , 0 , x )
  {
    foi( j , i , x )
    {
      foi( k , 0 , y )
      {
        foi( m , k , y )
        {
          may=INF;
          ss=0;
          foi( n , 0 , z )
          {
            arr[n]=sum(cube,i,j,k,m,n);
            ss+=arr[n];
            if(ss>may)
            {
              may=ss;
            }
            if(ss<0)
              ss=0;
          }
          // cout<<may<<" "<<mayTot<<endl;
          if(mayTot<may)
            mayTot=may;

        }
      }
    }
  }
  return mayTot;
}


int main()
{
  long long t;
  scanf("%lld",&t);
  while( t-- )
  {
    long long x,y,z;
    scanf("%lld%lld%lld",&x,&y,&z);
    vector< vector< vector<long long> > > cube(x,vector< vector<long long> >(y,vector<long long>(z)));
    foi( i , 0 , x )
      foi( j , 0 , y )
        foi( k , 0 , z )
        {
          // cout<<"voy a leer el "<<i<<" "<<j<<" "<<k<<endl;
          scanf("%lld",&cube[i][j][k]);
        }
    // cout<<"sali"<<endl;
    printf("%lld\n",mayor(cube,x,y,z));
    if(t!=0)
      printf("\n" );
  }
  return 0;
}
