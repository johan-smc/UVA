#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair< int , int > ii;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int N;
    int t = 0;
    cin >> t;
    while( t-- )
    {
        cin >> N ;
        priority_queue< ii , vector<ii> , greater< ii > > pq;
        for( int i= 2 ; i*i < N ; ++i )
        {
            if( N % i  == 0)
            {
                pq.push( ii( i , N/i ) );
                pq.push( ii( N/i , i ) );
            }
        }
        ii temp;
        bool is = false;
        while( !pq.empty()  )
        {
            temp = pq.top();
            pq.pop();
            if( !(temp.first & 1) )
                continue;
            if( temp.second - (temp.first>>1) >= 0 )
            {
                is = true;
                break;
            }
        }
        int l = 1;
        int nt = N;
        bool is2 = false;
        while( nt > 1 )
        {
            if( nt % 2 == 1 )
            {
                l <<= 1;
                is2 = true;
                break;
            }
            nt >>= 1;
            l <<= 1;
        }
       // cout << nt <<  " " << l << "\n";
        if( is || is2 )
        {
            int sum  = 0;
                cout << N << " =";
            if( (is2 && is && l > temp.first) && is )
            {
                for( int i= temp.second - ( temp.first >> 1 ) , sum = i ;  sum <= N ; ++i , sum += i )
                {
                    if( i == 0 )
                        continue;
                    if( sum != i )
                        cout << " +";
                   cout << " " << i ;
                }

            }
            else if( is2 )
            {
                int np = (N / l) - ((l-1)>>1);
               // cout << np << " " << l << " -- \n";
                for( int i =np  ; sum <  N ; ++i )
                {

                    if( i != np )
                        cout << " +";
                    cout <<" " << i;
                    sum += i;
                }

            }

        }
        else
            cout << "IMPOSSIBLE";
        cout << "\n";
    }

    return 0;
}
