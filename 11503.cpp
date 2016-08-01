#include <iostream>
#include <cstdio>
#include <map>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

class UnionFind
{
  private:
    map< string , string > p;
    map< string , int > rank;
    map< string , int > nn;
  public:
    string findSet( string i )
    {
      return ((p[i]==i) ? i :(p[i]= findSet(p[i]) ));
    }
    void insert( string i )
    {
      p.insert(make_pair(i,i));
      rank.insert(make_pair(i,0));
      nn.insert(make_pair(i,1));
    }

    bool isSame( string i , string j )
    {
      return findSet(i)==findSet(j);
    }



    int max( string i )
    {
      return nn[findSet(i)];
    }

    void unionSet ( string i, string j )
    {
      if( p.find(i) == p.end() )
        insert(i);
      if( p.find(j) == p.end() )
        insert(j);
      if(!isSame(i,j))
      {
        string x,y;
        x=findSet(i);
        y=findSet(j);
        int tot=nn[x]+nn[y];
        if( rank[x] > rank[y] )
        {
          p[y]=x;
        }
        else
        {
          p[x]=y;
          if( rank[x]==rank[y] )
            rank[y]++;
        }
        nn[findSet(x)]=tot;
      }
    }
};

int main()
{
  int t;
  scanf("%d",&t );
  while( t-- )
  {
    int c;
    UnionFind uf;
    string a,b;
    scanf("%d",&c );
    foi( i , 0 , c )
    {
      cin>>a>>b;
      uf.unionSet(a,b);
      uf.unionSet(b,a);
      printf("%d\n",uf.max(a));
    }
  }
  return 0;
}
