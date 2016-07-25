#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define foi( i , n , k ) for(int i = n ; i < k ; ++i )
using namespace std;

class SegmentTree
{
  private:
    vector<int> A, st,posf,posi;
    int n;
    int left( int p ){ return p << 1;}
    int right( int p ){ return ( p << 1 )+1;}

    void build(int p, int L ,int R)
    {
      if( L == R )
      {
        st[p]=L;
      }
      else
      {
        build( left(p),L,(L+R)/2);
        build( right(p) , ((L+R)/2)+1,R);
        int p1=st[left(p)],p2=st[right(p)];

        st[p]=(A[p1]>=A[p2])?p1:p2;
      }
    }
    int rmq( int p , int L ,int R, int i ,int j)
    {
      // cout<<"rmq "<<p<<" "<<L<<" "<<R<<" "<<i<<" "<<j<<endl;
      if( i > R || j < L)
        return -1;
      if( L>= i && R <= j)
        return st[p];
      int p1=rmq(left(p),L,(L+R)/2,i,j);
      int p2=rmq(right(p),(L+R)/2+1,R,i,j);
      if( p1 == -1)
        return p2;
      if( p2 == -1)
        return p1;

      return (A[p1]>=A[p2])?p1:p2;

    }
    void fre(const vector<int>&_A)
    {
      char a=' ';
      int c=0;
      queue<int> q;
      foi( i , 0 , _A.size() )
      {
        if( a != _A[i] )
        {
          if( i != 0)
          {
            while( !q.empty() )
            {
              A[q.front()]=c;
              //  cout<<c<<" ";
              q.pop();
            }
            // cout<<i-1<<" ";
            posf.push_back(i-1);
          }
          posi.push_back(i);
          a=_A[i];
          c=1;
          q.push(i);
        }
        else
        {
          c++;
          q.push(i);
        }
      }
      while( !q.empty() )
      {
        A[q.front()]=c;
        q.pop();
        //  cout<<c<<" ";
      }
      posf.push_back(_A.size()-1);
        // cout<<endl;
  }
  public:
    SegmentTree(const vector<int>&_A)
    {
      n=(int)_A.size();
      A.assign(n,0);
      fre(_A);
      st.assign(4*n,0);
      build(1,0,n-1);
    }
    int rmq(int i,int j)
    {
      // cout<<i<<" "<<j<<endl;
      vector<int>::iterator it;
      it=lower_bound(posf.begin(),posf.end(),i);
      int may=-999999;
      if( *it >= i )
      {
        if( *it >= j )
          return (j-i)+1;
        may=max(may,((*it)-i)+1);
        //  printf(" it %d ma %d ot %d\n",*it, may , ((*it)-i)+1 );
        i=*it+1;
        // cout<<" it- "<<*it<<endl;
      }
      it=lower_bound(posi.begin(),posi.end(),j);
      //  printf("%d otro it i %d j %d\n",*it,i,j );
      if(it==posi.end())
     {
       may=max(may,(j-posi[posi.size()-1])+1);
       j=posi[posi.size()-1]-1;
     }
     else if( *it <= j)
      {
          may=max(may,(j-(*it))+1);
          j=(*it)-1;

      }
      else if( *it > j )
      {
        it--;
        may=max(may,(j-(*it))+1);
        j=(*it)-1;
      }
      int pp=rmq(1,0,n-1,i,j);
      if( pp != -1)
        may=max(may,A[pp]);
      //  printf("%d %d\n",pp,may );
        // cout<<i<<" "<<j<<" pp "<<pp<<" "<<((pp!=-1)?A[pp]:' ')<<endl;
      return may;
    }
};

int main()
{
  int n,q;
  while( scanf("%d",&n )!=EOF && n!=0)
  {
    scanf("%d",&q );
    vector<int> A(n,0);
    int a,b;
    foi( i , 0 , n )
      scanf("%d",&A[i] );
    SegmentTree st(A);
    foi( i , 0 , q )
    {
      scanf("%d%d",&a,&b );
      printf("%d\n", st.rmq(a-1,b-1) );
    }
    //  cout<<"------------"<<endl;
  }
  return 0;
}
