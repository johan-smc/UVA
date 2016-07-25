#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#define foi( i , n , k )for( int i = n ; i <k ; ++i)
using namespace std;

bool back(vector<int>&tam,int sum,int x,int length)
{
  // cout<<" sum "<<sum<<" "<<x<<" "<<length<<endl;
  if(sum==length)
    return true;
  if(sum>length)
    return false;
  foi( i , x , tam.size())
  {
    if(back(tam,sum+tam[i],i+1,length))
      return true;
  }
  return false;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int length,n;
    scanf("%d%d",&length,&n);
    vector<int> tam(n);
    foi( i , 0 , n)
    {
      scanf("%d",&tam[i]);
    }
    sort(tam.begin(),tam.end());
    if( back(tam,0,0,length) )
    {
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
  return 0;
}
