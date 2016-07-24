#include <iostream>
#include <set>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF && n!= 0 )
  {
    int k,c;
    multiset<int> mset;
    multiset<int>::iterator iti,itf;
    long long tot=0;
    foi( i , 0 , n )
    {
      scanf("%d",&k);
      foi( j , 0 , k )
      {
        scanf("%d",&c);
        mset.insert(c);
      }
      iti=mset.begin();
      itf=mset.end();
      itf--;
      tot+=((*itf)-(*iti));
      mset.erase(iti);
      mset.erase(itf);
    }
    printf("%lld\n",tot ); 
  }
  return 0;
}
