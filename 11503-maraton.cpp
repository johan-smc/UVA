#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define foi( i , n , k ) for( int i = n ; i <k ; ++i )
#define vi vector<int>
using namespace std;

class UnionFind{
  private:
    vi p,k,tam;
  public:
    void insert( int n )
    {
      p.push_back(n);
      k.push_back(0);
      tam.push_back(1);
    }
    UnionFind( int n )
    {
      p.assign(0,n);
      k.assign(0,n);
      foi( i , 0 , n )
        p[i]=i;
    }
    int root( int n )
    {
      return (n==p[n])?n:root(p[n]);
    }
    bool isUnion( int a , int b)
    {
      return root(a)==root(b);
    }
    void unir( int a, int b)
    {
      int x=root(a);
      int y=root(b);
      if(x==y)
        return;
      if(k[x]<k[y])
      {
        p[x]=y;
        tam[y]+=tam[x];
      }
      else
      {
        p[y]=x;
        tam[x]+=tam[y];
        if( k[x]==k[y])
          ++k[y];
      }
    }
    int tama( int n )
    {
      return tam[root(n)];
    }
    void print()
    {
      foi( i , 0 , p.size() )
        cout<<p[i]<<" ";
      cout<<endl;
      foi( i , 0 , p.size() )
        cout<<k[i]<<" ";
      cout<<endl;
      foi( i , 0 , p.size() )
        cout<<tam[i]<<" ";
      cout<<endl;
    }
};

int main()
{
  int t;
  scanf("%d",&t );
  while( t-- )
  {
    int q;
    scanf("%d",&q );
    int in=0;
    map<string,int> mp;
    UnionFind uf(0);
    foi( i , 0 , q )
    {
      string a,b;
      cin>>a>>b;
      if( mp.find(a)==mp.end() )
      {
        mp.insert(make_pair(a,in++));
        uf.insert(mp[a]);
      }
      if( mp.find(b)==mp.end() )
      {
        mp.insert(make_pair(b,in++));
        uf.insert(mp[b]);
      }
      uf.unir(mp[a],mp[b]);
      uf.unir(mp[b],mp[a]);
      // uf.print();
      printf("%d\n",uf.tama(mp[a]));
    }

  }
  return 0;
}
