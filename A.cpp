#include <cstdio>
#include <iostream>
#include <vector>

#define foi(i, n, k) for (int i = n; i < k; ++i)
#define vi std::vector<int>
using namespace std;

class UnionFind {
  private:
  public:
    vi p,rank;
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
  }
  int findSet(int i) {
    if(i==-1)
      return -1;
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if(i==-1||j==-1)
      return ;
    if (!isSameSet(  i,  j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x]=y;
      if (rank[x] == rank[y])
        rank[y]++;
      }
    }
  }
};

int main()
{
  int n,q;
  scanf("%d%d",&n,&q );
  UnionFind fri(n);
  vi ene(n,-1);
  while( q-- )
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c );
    if( a==1 )
    {
      int x=fri.findSet(b);
      int y=fri.findSet(c);
      if( fri.findSet(ene[x])==y )
      {
        printf("-1\n" );
      }
      else{
        // cout<<"--- "<<b<<" "<<c<<endl;
        fri.unionSet(b,c);
        fri.unionSet(ene[b],ene[c]);
        int papafin=fri.findSet(b);
        int papaene=-1;
        if(ene[b]!=-1)
         papaene=fri.findSet(b);
        else if(ene[c]!=-1)
          papaene=fri.findSet(c);
        ene[papafin]=papaene;
        if(papaene!=-1)
          ene[papaene]=papafin;
      }

    }
    else if( a==2 )
    {
      if(fri.isSameSet(b,c))
        printf("-1\n" );
      else
      {
        int x=fri.findSet(b);
        int y=fri.findSet(c);
        if(ene[x]!=-1)
          fri.unionSet(ene[x],y);
        if(ene[y]!=-1)
          fri.unionSet(ene[y],x);

        x=fri.findSet(b);
        y=fri.findSet(c);
        ene[x]=y;
        ene[y]=x;
      }
    }
    else if( a==3 )
    {
      printf("%d\n",fri.isSameSet(b,c) );
    }
    else if( a==4 )
    {
      int x=fri.findSet(b);
      int y=fri.findSet(c);
      // cout<<"-- "<<x<<" "<<y<<endl;
      // cout<<fri.findSet(ene[x])<<" "<<y<<endl;
      int e=-1;
      if(x!=-1)
        e=ene[x];
      if(fri.isSameSet(x,y))
        printf("0\n");
      else
        printf("%d\n",fri.findSet(e)==y );

    }
    /*
    foi( i , 0 , n )
    {
      cout<<fri.findSet(i)<<" ";
    }
    cout<<endl;
    foi( i , 0 , n )
    {
      cout<<ene[i]<<" ";
    }
    cout<<endl;
    */

  }
  return 0;
}
