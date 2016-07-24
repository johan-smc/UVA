#include <iostream>
#include <bitset>
#include <vector>

#define TAM 1000001
using namespace std;

int main()
{
  int n,m;
  while( scanf("%d%d",&n,&m) != EOF && (n!=0 || m!=0 ))
  {
    vector<bool> bit(TAM,false);
    int a,b,r;
    bool s=true;
    for( int i  = 0 ; i < n ; ++i )
    {
      scanf("%d%d",&a,&b);
      // if( a+1 < TAM  && b-1 >= 0 && b < TAM && bit[a+1]&& bit[b-1])
      //   s=false;
      // if(a+1==b && bit[a] &&bit[b])
      //   s=false;
      for( int j = a ; j < b  && j< TAM && s; ++j )
      {
        if( bit[j] )
          s=false;
        else
          bit[j]=true;
      }
      //  if( a < TAM )
      //    bit[a]=true;
      //  if( b < TAM )
      //    bit[b] = true;
    }
    for( int i = 0 ; i < m ; ++i )
    {
      scanf("%d%d%d",&a,&b,&r);
      while( a < TAM )
      {
        // if( a+1 < TAM  && b-1 >= 0 && b < TAM && bit[a+1]&& bit[b-1])
        //   s=false;
        // if(a+1 < TAM && a+1==b && bit[a] &&bit[b] )
        //   s=false;
        for( int j = a ; j < b  && j< TAM && s; ++j )
        {
          if( bit[j] )
            s=false;
          else
            bit[j]=true;
        }
        //  if( a < TAM )
        //    bit[a]=true;
        //  if( b < TAM )
        //    bit[b] = true;
        a+=r;
        b+=r;
      }
    }
    if( s )
     printf("NO CONFLICT\n");
    else
      printf("CONFLICT\n");
  }
  return 0;
}
