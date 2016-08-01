#include <iostream>
#include <cstdio>
#include <queue>

#define EPS 1e-9
#define foi( i , n , k ) for(int i = n ; i < k ; ++i)
using namespace std;
int gcd( int a, int b ){ return b== 0 ? a : gcd(b,a%b);}

pair<int,int> fun( int a, int b)
{
  int en,ab;
  en=b-a;
  ab=a*b;
  int nn=gcd(en,ab);
  // cout<<en<<" "<<ab<<" "<<nn<<endl;
  return make_pair(en/(nn),ab/(nn));
}

int main()
{
  int n;
  while( scanf("%d",&n) != EOF )
  {
    queue< pair<int,int> > s;
    pair<int,int> temp;
    foi( i , n+1, 2*n+1)
    {
      temp=fun(n,i);
      // cout<<temp.first<<" "<<temp.second<<" "<<((double)1/n)<<" "<<endl;
          if( temp.first==1   )
          {
            s.push(make_pair(temp.second,i));
          }

    }
    printf("%d\n",(int)s.size());
    while( !s.empty() )
    {
      printf("1/%d = 1/%d + 1/%d\n",n,s.front().first,s.front().second);
      s.pop();
    }
  }
  return 0;
}
