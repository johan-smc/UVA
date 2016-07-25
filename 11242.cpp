#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define foi( i , n , k ) for( int i  = n ; i <  k ; ++i )
using namespace std;

int main()
{
  int f,r;
  while( scanf("%d",&f)!=EOF &&  f != 0)
  {
    scanf("%d",&r);
    vector<double> ff(f),rr(r),fr;
    foi( i , 0 , f)
    {
      scanf("%lf",&ff[i]);
    }
    foi( i , 0 , r )
    {
      scanf("%lf",&rr[i]);
    }
    foi( i , 0 , r )
    {
      foi( j , 0 , f)
      {
        fr.push_back(rr[i]/ff[j]);
      }
    }
    sort( fr.begin() , fr.end() );
    double db;
    foi( i , 0 , (int)fr.size() -1 )
    {
      if( i == 0 )
      {
        db=fr[i+1]/fr[i];
      }
      else  if(fr[i+1]/fr[i] > db)
      {
        db=fr[i+1]/fr[i];
      }

    }
    printf("%.2lf\n",db);
  }
  return 0;
}
