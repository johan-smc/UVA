#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF )
  {
    int ma;
    ma=-9999999;
    int t=(1<<n);
    // cout<<t<<endl;
    vector<int> vec(t);
    vector< int  > vv;
    for( int i = 0 ; i < t ; ++i )
    {
      scanf("%d",&vec[i]);
    }
    for( int i = 0 ; i < t ; ++i )
    {
      int temp=0;
      for( int j = 0 ; j < n ; ++j )
      {
        int p=i^(1<<j);
        temp+=vec[p];
        // cout<<i<<" "<<vec[p]<<" "<<p<<endl;
      }
      vv.push_back(temp);
    }
    vector<bool> pas(t,false);
    for( int i =0 ; i < t;++i)
    {
      int temp=vv[i];
      pas[i]=true;
      for( int j = 0 ; j < n ; ++j )
      {
        int p=i^(1<<j);
        if(!pas[p]){
          int tt=temp+vv[p];
          // cout<<i<<" "<<vec[p]<<" "<<p<<endl;
          if(ma<tt)
          {
            ma=tt;
          }
        }
      }
    }
    printf("%d\n",ma);
  }
  return 0;
}
