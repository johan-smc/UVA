#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct ST
{
  private:
  int n ;
  vector< int > S,A;
  public:
  ST( vector< int > _A )
  {
    n = _A.size() ;
    A = _A;
    S.assign( A.size() * 4 , -1 );
  }
}

int main()
{
  int n,q;
  vector< int > seq;
  while( scanf("%d",&n) != EOF )
  {
    seq.rezise( n );
    for( int i = 0 ; i < n ; ++i )
      scanf("%d",&seq[i]);
    scanf("%d",&q);
    while( q-- )
    {

    }
  }
}
