#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int i  = n ; i <k ; ++i )

using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n)!=EOF)
  {
    vector<int> book(n);
    foi( i , 0 , n )
    {
      scanf("%d",&book[i]);
    }
    sort( book.begin() , book.end() );
    int p;
    scanf("%d",&p);
    pair<int,int> may(0,9999999);
    foi( i , 0 , n )
    {
      if( p>book[i] && binary_search(book.begin()+i,book.end(),p-book[i]) )
      {
        may=((may.second-may.first)<((p-book[i])-book[i]))?may:make_pair(book[i],(p-book[i]));
      }
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n",may.first,may.second);
  }
  return 0;
}
