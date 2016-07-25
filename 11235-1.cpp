#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>


#define foi( i , n , k ) for(int i = n; i < k; i++)
using namespace std;

class SegmentTree
{
  private:
    vector<int> st,A;
    int n;
    int left( int p ){ return p << 1;}
    int right( int p){ return (p<<1)+1; }

    void build( int p , int L, int R)
    {
      if( L == R )
      {
        st[p]=L;
      }
      else
      {
        build(left(p),L,(L+R)/2);
        build(right(p),((L+R)/2)+1,R);
        int p1=st[left(p)],p2=st[right(p)];
        st[p]=(A[p1] >= A[p2])?p1:p2;
      }
    }
    int rmq( int p, int L , int R  , int i , int j)
    {
      if( i > R || j < L )
        return -1;
      if( L >= i && R <= j)
      {
        return st[p];
      }
      int p1=rmq(left(p),L,(L+R)/2,i,j);
      int p2=rmq(right(p),(L+R)/2+1,R,i,j);
      if(p1==-1)
        return p2;
      if( p2 == -1)
        return p1;
      return (A[p1]>= A[p2])?p1:p2;
    }


    public:

      SegmentTree( const vector<int>& _A)
      {
        A=_A ;
        n=(int)A.size();
        st.assign(4*n,0);
        build(1,0,n-1);
      }
      int rmq( int i,int j)
      {
        return A[rmq(1,0,n-1,i,j)];
      }

};

int funcion(int i , int j , SegmentTree&st,vector<int>&ini,vector<int>&fin)
{
  vector<int>::iterator it;
  // cout<<i<<" "<<j<<endl;
  it=lower_bound(fin.begin(),fin.end(),i);
  int may=-9999999;
  if( i <= *it && j <= *it ){
    // cout<<" - - "<<*it<<endl;
    return (j-i)+1;
  }
  if( i <= *it )
  {
    may=max(may,((*it)-i)+1);
    i=(*it)+1;
  }
  // cout<<" nn " <<may<<endl;
  it=lower_bound(ini.begin(),ini.end(),j);
  if( it == ini.end() )
  {
    may=max(may,(j-ini[ini.size()-1])+1);
    j=ini[ini.size()-1]-1;
  }
  else if( *it == j )
  {
    may=max(may,1);
    j--;
  }
  else
  {
    it--;
    may=max(may,(j-(*it))+1);
    j=(*it)-1;
  }
  // cout<<" df "<<may<<endl;
  // cout<<i<<" "<<j<<" "<<st.rmq(i,j)<<endl;
  return max(may,st.rmq(i,j));
}

int main()
{
  int n,q;
  while( scanf("%d",&n)!=EOF && n!=0)
  {
    scanf("%d",&q);
    vector<int> real(n,0),fre(n,0),ini,fin;

    foi( i , 0 , n )
    {
      scanf("%d",&real[i]);
    }
    int o,c=0 ;
    queue<int> qq;
    foi( i , 0 , n )
    {
      if( i == 0 || o!=real[i])
      {
        ini.push_back(i);
        if( i!= 0)
          fin.push_back(i-1);
        while(!qq.empty())
        {
          fre[qq.front()]=c;
          qq.pop();
        }
        qq.push(i);
        o=real[i];
        c=1;
      }
      else
      {
        c++;
        qq.push(i);
      }
    }
    fin.push_back(n-1);
    while( !qq.empty() )
    {
      fre[qq.front()]=c;
      qq.pop();
    }
    /*
    foi( i , 0 , fin.size() )
      cout<<fin[i]<<" ";
    cout<<endl;
    foi( i , 0 , ini.size() )
      cout<<ini[i]<<" ";
    cout<<endl;
    foi( i , 0 , fre.size() )
      cout<<fre[i]<<" ";
    cout<<endl;
    */
    SegmentTree st(fre);
    foi( i , 0 , q )
    {
      int a,b;
      scanf("%d%d",&a,&b);
      printf( "%d\n",funcion(a-1,b-1,st,ini,fin));
    }
  }
  return 0;
}
