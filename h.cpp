#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define INF 1<<25
typedef pair < int , int > ii;

struct st{
  std::vector<ii> tree,lazyTree;
  int tam;
  void st( vector < int > &arr )
  {
    tam = arr.size();
    tree.assign( 4 * arr.size() , ii(0,0));
    lazyTree.assign( 4 * arr.size() , ii(0,0) );
    build(0 , tam - 1 , 0 , arr);
  }

  void build( int low , int high , int pos , vector < int > &arr )
  {
    if( low == high )
    {
      tree[pos] = ii( arr[low] , arr[low] );
      return;
    }
    int mid = ( low + high ) >> 1;
    int left = ( pos << 1 ) | 1;
    int right = left + 1;
    build( low , mid , left , arr );
    build( mid + 1 , high , right , arr );
    tree[pos].first = max( tree[left].first , tree[right].first );
    tree[pos].second = min( tree[left].second , tree[right].second );
  }

  ii query_lazy( int low , int high , int &qlow , int &qhigh , int pos )
  {

    int mid = ( low + high ) >> 1;
    int left = ( pos << 1 ) | 1;
    int right = left + 1;
    if( lazyTree[ pos ] != 0 )
    {
            if( low == high )
              tree[ pos ].second = (tree[ pos ].first += lazyTree[ pos ]);
            else
            {
              tree[ pos ].first += lazyTree[ pos ];
              tree[ pos ].second += lazyTree[ pos ];
              lazyTree[ left ] += lazyTree[ pos ];
              lazyTree[ right ] += lazyTree[ pos ];
            }
            lazyTree[ pos ] = 0;
    }
    if( high < qlow || qhigh < low  )
      return ii(-INF,INF);
    if( low >= qlow && high <= qhigh )
      return tree[ pos ];

    query_lazy( low , mid , qlow , qhigh , left );
    query_lazy( mid +1  , high , qlow , qhigh , right );
    tree[pos].first = max( tree[left].first , tree[right].first );
    tree[pos].second = min( tree[left].second , tree[right].second );
    return tree[ pos ];
  }

  void update_lazy( int low , int high , int &qlow , int &qhigh , int pos ,  const int& can )
  {
    int mid = ( low + high ) >> 1;
    int left = ( pos << 1 ) | 1;
    int right = left + 1;
    if( lazyTree[ pos ] != 0 )
    {
            if( low == high )
              tree[ pos ].second = (tree[ pos ].first += lazyTree[ pos ]);
            else
            {
              tree[ pos ].first += lazyTree[ pos ];
              tree[ pos ].second += lazyTree[ pos ];
              lazyTree[ left ] += lazyTree[ pos ];
              lazyTree[ right ] += lazyTree[ pos ];
            }
            lazyTree[ pos ] = 0;
    }
    if( high < qlow || qhigh < low  )
      return ;
    if( low >= qlow && high <= qhigh ) {
       tree[ pos ] += can;
      lazyTree[ left ] += lazyTree[ pos ];
      lazyTree[ right ] += lazyTree[ pos ];
      lazyTree[ pos ] = 0;
    }

    update_lazy( low , mid , qlow , qhigh , left , can );
    update_lazy( mid +1  , high , qlow , qhigh , right ,can);
    tree[pos].first = max( tree[left].first , tree[right].first );
    tree[pos].second = min( tree[left].second , tree[right].second );
  }
  ii query( int a , int b )
  {
    return query_lazy(0,tam-1,a,b,0);
  }
  void update( int a, int b , int c)
  {
    update_lazy( 0 , tam-1 , a , b , 0 , c);
  }
};

int main()
{
  int n,l,q;
  cin >> n >> l >> q;
  std::vector<int> v(n);
  st segment(v);
  string comand;
  int a,b,c;
  ii res;
  while( q-- )
  {
    cin >> comand;
    if( comand == "state" )
    {
      cin >> a;
      cout << st.query_lazy(a,a).first;
    }
    else if( comand == "groupchange" )
    {

      cin >> a >> b >> c ;
      res = st.query(a,b);
      if( c < 0 )
      {
        if( res.second + c > 0 )
        {
          st.update(a,b,c);
          c = abs(c);
          cout << c;
        }
        else
        {
          cout << res.second;
          st.update( a , b , -res.second );
        }
      }
      else
      {
        if( res.first + c > l )
          c = l-res.first;
        cout << c;
        st.update( a , b , c );
      }

    }
    else if( comand == "change" )
    {
      res = st.query(a,b);
      cin >> a >> c;
      if( res.first + c > l )
        c = l-res.first;
      cout << c;
      st.update( a , a , c );
    }
    cout << "\n";
  }
  return 0;
}
