#include <cstdio>
#include <iostream>
#include <vector>

#define LIM 2*1e7
using namespace std;

vector< pair<int,int> > pp;
vector<bool> isPrime(LIM+3,true);

void criba()
{
  isPrime[0]=isPrime[1]=0;
  long long  ant=-1;
  for( long long  i = 2 ; i < LIM ; ++i )
  {
    if(isPrime[i])
    {
      // cout<<i<<" "<<ant<<endl;
      if( i != 2 && i-ant == 2 )
      {
        pp.push_back(make_pair(ant,i));
      }
      ant = i;
      for(long long j = i*i ; j < LIM ; j+=i )
      {
        // cout<<"-- j "<<j<<endl;
        isPrime[j]=false;
      }
    }
  }
}

int main()
{
  criba();
  // cout<<"hola "<<pp.size()<<endl;
  int n;
  while( scanf("%d",&n)!=EOF)
  {
    n--;
    printf("(%d, %d)\n",pp[n].first,pp[n].second);
  }
  return 0;
}
