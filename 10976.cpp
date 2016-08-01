#include <iostream>
#include <cstdio>
#include <queue>

#define EPS 1e-9
using namespace std;
int gcd( int a, int b ){ return b== 0 ? a : gcd(b,a%b);}

pair<int,int> fun( int a, int b)
{
  int en,ab;
  en=a+b;
  ab=a*b;
  int nn=gcd(en,ab);
  return make_pair(en/(nn),ab/(nn));
}

int main()
{
  int n;
  while( scanf("%d",&n) != EOF )
  {
    queue< pair<int,int> > s;
    int a=n+1,b=n+1;
    pair<int,int> temp;
    temp=fun(a,b);
    while(  (double)temp.first/(double)temp.second>=((double)1/n) )
    {
      while(  (double)temp.first/(double)temp.second>=((double)1/n))
      {
        // cout<<a<<" "<<b<<" "<<temp.first<<" "<<temp.second<<" "<<((double)1/n)<<" "<<endl;
          if( temp.first==1 && temp.second==n  )
          {
            s.push(make_pair(b,a));
          }
          b++;
          temp=fun(a,b);
      }
      a++;
      b=a;
      temp=fun(a,b);
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
