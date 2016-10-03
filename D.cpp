#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
#define cout( x ) //cout<<x<<endl;
#define INF 9999999
using namespace std;
int pos[4]={1,-1,-3,3};

int back( bitset<9> &n,bitset<9>&pas , map<int,int> &mp,int ll)
{
  cout(n.to_ulong());
  if( n.to_ulong() == 511 ){
    // cout<<"here"<<endl;
    return ll;}
  if(mp.find(n.to_ulong())!=mp.end())
    return mp[n.to_ulong()];
  int men=INF;
  foi( i , 0 , 9 )
  {

    cout<<i<<" "<<n<<" " <<n.to_ulong()<<" ll "<<ll<<endl;
    if( !pas[i] )
    {
      pas[i]=true;
      n.flip(i);
      foi( j , 0 , 4)
      {
        int next=i+pos[j];
        if( next>=0 && next < 9)
        {
          n.flip(next);
        }
      }
      cout<<"mando "<<n<<" "<<ll<<" "<<endl;
      men=min(men,back(n,pas,mp,ll+1));
      foi( j , 0 , 4)
      {
        int next=i+pos[j];
        if( next>=0 && next < 9)
        {
          n.flip(next);
        }
      }
      n.flip(i);
      pas[i]=false;
    }
  }
  mp[n.to_ulong()]=men;
  // cout<<n<<" "<<n.to_ulong()<<" "<<men<<endl;
  return men;
}

int main()
{
  int t;
  scanf("%d",&t);
  map<int,int> mp;
  mp[511]=0;
  while(t--)
  {
    bitset<9> n,pas;
    char a;
    foi( i , 0 , 9 )
    {
      scanf(" %c",&a);
      if(a=='.')
      {
        n.set(i);
      }
    }
    cout<<"hei "<<n<<" " << n.to_ulong() <<endl;
    printf("%d\n",back(n,pas,mp,0) );
    // cout<<"nn"<<endl;
  }
  return 0;
}
