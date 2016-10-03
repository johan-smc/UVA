#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

vector < pair < ll , ll > > p;

void sieve(ll N)
{
    bitset < 10000000 > bs;
    bs.set();
    ll multi = 1;
    int cont = 1;
    p.push_back( make_pair( 1,0 ) );
    for(ll i = 2 ; multi <= N ; i++ )
    {
        if( bs[ i ] )
        {
            multi *= i;
            p.push_back( make_pair( multi, cont ) );
            cont++;
            for( ll j = i*i ; j <= 1e6  ; j+=i )
            {
                bs[ j ] = false;
            }
        }
    }

}

bool cmp( const pair < ll , ll > &p, const pair < ll , ll > &q )
{
    return p.first < q.first;
}

int main() {
    int q;
    sieve( 1e18 );
    scanf("%d",&q);
    // for( int i = 0 ; i < 100 ; ++i )
    //   printf("%llu %llu\n",p[i].first,p[i].second );
    while( q-- )
    {
        ll query;
        scanf("%llu",&query);
        int resultado = lower_bound( p.begin(),p.end(),make_pair( query,-1 ),cmp) - p.begin();
        // cout<<resultado<<" --- "<<endl;
        if( p[ resultado ].first == query )
            printf("%llu\n",p[ resultado ].second);
        else
            printf("%llu\n",p[ resultado-1 ].second);
    }
    return 0;
}
