#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define foi( i , n , k ) for( int i = n ; i <  k ; ++i )
#define vi vector<int>
using namespace std;

class DisjointSet
{
  private:
  vi p,k;
  public:
  DisjointSet(int n )
  {
    p.assign(n,0);
    k.assign(n,0);
    foi( i , 0 , n )
    {
      p[i]=i;
    }
  }
  int root( int a)
  {
    return a==p[a]?a:root(p[a]);
  }
  bool isUnion(int a, int b)
  {
    return root(a)==root(b);
  }
  void setUnion( int a, int b)
  {
    int x=root(a);
    int y=root(b);
    if( !isUnion (x,y) )
    {
      if(k[x]>k[y])
      {
        p[y]=x;
      }
      else
      {
        p[x]=y;
        if(k[x]==k[y])
          k[y]++;
      }
    }
  }

};

int main()
{
  printf("SHIPPING ROUTES OUTPUT\n");
  int t,cas=0;
  scanf("%d",&t);
  while(t--)
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    map<string,int> mp;
    string name;
    int cont=0;
    DisjointSet ds(a);
    foi( i , 0 , a )
    {
      cin>>name;
      mp[name]=cont++;
    }
    string nameA,nameB;
    foi( i , 0 , b )
    {
      cin>>nameA>>nameB;
      ds.setUnion(mp[nameA],mp[nameB]);
      ds.setUnion(mp[nameB],mp[nameA]);
    }
    printf("\nDATA SET %d\n\n",++cas);
    foi( i , 0 , c )
    {
      scanf("%d",&cont);
      cin>>nameA>>nameB;
      if(ds.isUnion(mp[nameA],mp[nameB]))
      {
        printf("$%d\n",cont*100);
      }
      else
      {
        printf("NO SHIPMENT POSSIBLE\n");
      }
    }

  }
  printf("\nEND OF OUTPUT\n");
  return 0;
}
