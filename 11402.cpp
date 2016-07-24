#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

//segundo componente
int LSOne(int n)
{
  return (n&(-n));
}
class FenwickTree{
private:
  std::vector<int> v;
public:
  FenwickTree(int n)
  {
    v.assign(n+1,0);
  }
  int rsq( int n)
  {
    int tot=0;
    for( ; n ; n -= LSOne(n) )
      tot+=v[n];
    return tot;
  }
  int rsqRange(int a,int b)
  {
    return rsq(b)-(a==1?0:rsq(a-1));
  }
  void adjust(int pos,int val)
  {
    for( ; pos<v.size(); pos+=LSOne(pos) )
      v[pos]+=val;
        // cout<<(v[pos]+=val) <<" "<<pos<<" "<<v.size()<<endl;;
  }
  void print()
  {
    for( int i = 0 ; i < v.size() ; ++i )
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;
  }
};
int main()
{
  int t;
  scanf("%d",&t );
  for( int i = 0 ; i < t ; ++i)
  {
    printf("Case %d:\n",i+1 );
    int n,r,a,b;
    char fun;
    scanf("%d",&n );
    string temp;
    string by="";
    for( int j = 0 ; j < n ; ++j )
    {
      scanf("%d ", &r);
      cin>>temp;
      while( r-- )
        by+=temp;
    }
    FenwickTree ft(by.size());
    // cout<<"nn"<<endl;
    for( int j = 1 ; j < by.size()+1 ; ++j )
    {
      ft.adjust(j,by[j-1]-'0');
    }
    // cout<<"n"<<endl;
    scanf("%d", &n);
    r=0;
    // cout<<"hi"<<endl;
    for( int j = 0 ; j < n  ; ++j)
    {

      cin>>fun;
      scanf("%d%d",&a,&b );
      // ft.print();
      // cout<<by<<" " << ft.rsq(a+1) <<" " <<ft.rsq(b+1)<<" "<<ft.rsq(a)<<endl;
      //  cout<<fun<<" "<<a<<" "<<b<<endl;
      if( fun=='F' )
      {
        for( ; a <= b ; ++a)
        {
          if( by[a]=='0')
          {
            by[a]='1';
            ft.adjust(a+1,1);
          }
        }
      }
      else if( fun=='E' )
      {
        for( ; a <= b ; ++a)
        {
          if( by[a]=='1')
          {
            by[a]='0';
            ft.adjust(a+1,-1);
          }
        }
      }
      else if( fun=='I' )
      {
        for( ; a <= b ; ++a)
        {
          if( by[a]=='1')
          {
            by[a]='0';
            ft.adjust(a+1,-1);
          }
          else if( by[a]=='0')
          {
            by[a]='1';
            ft.adjust(a+1,1);
          }
        }
      }
      else if(fun=='S'){

        printf("Q%d: %d\n",++r,ft.rsqRange(a+1,b+1) );
      }

    }
  }
  return 0;
}
