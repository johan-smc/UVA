#include <iostream>
#include <cstring>

using namespace std;
#define MAX 5005
// #define MAX2 1005
typedef long long ll;
ll MOD =  1000000007;
// A(n,m) = (n-m)A(n-1,m-1) + (m+1)A(n-1,m)
int eulerian[MAX][MAX];
int memo[MAX][MAX];

ll go( ll n , ll m )
{
  if( n == 1 || m == 0 || m == n-1 )
    return 1;
  if( ~eulerian[ n ][ m ] )
    return eulerian[ n ][ m ];
    return eulerian[ n ][ m ] = ((((n-m+MOD)%MOD)*go(n-1,m-1))%MOD + ((m+1)*go(n-1,m))%MOD)%MOD;
  // return eulerian[ n ][ m ] = (n-m)*go(n-1,m-1) + (m+1)*go(n-1,m);
}
ll go2( ll n , ll m )
{
  if( m == 0 )
    return 1;
  if( ~memo[ n ][ m ] ) return memo[ n ][ m ];
  return memo[ n ][ m ] = (go2(n,m-1)+go(n,m))%MOD;
}

int main()
{
  ios::sync_with_stdio(false);cin.tie(NULL);
  memset( eulerian , -1 , sizeof eulerian );
  memset( memo , -1 , sizeof memo );
  int n , q;
  int u ;
  while( cin >> n >> q )
  {
    while( q-- )
    {
      cin >> u;
      cout << go2( n , min(u-1,n-1) );
      if( q )
        cout << " ";
    }
    cout << "\n";
  }

  return 0;
}
