#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <bitset>

#define foi( i , n , k ) for( int i =  n ; i < k ; ++i )
using namespace std;

int main()
{
  int n,m;
  while( scanf("%d%d",&n,&m)!=EOF && (n!=0||m!=0))
  {
    vector< vector < int > > mat(n,vector<int>(m));
    foi( i , 0 , n )
    {
      foi( j , 0 , m)
      {
        scanf("%d",&mat[i][j]);
      }
    }
    int may=max(n,m);
    int q;
    scanf("%d",&q);
    foi ( i , 0 , q)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      // vector< int > vb(may,0);
       int mm=0;
      // vector< int > count(m,0);
      std::vector< pair<int,int>   > v;
      foi( j , 0 , n)
      {
        int posi=lower_bound(mat[j].begin(),mat[j].end(),a)-mat[j].begin();
        int posf=upper_bound(mat[j].begin(),mat[j].end(),b)-mat[j].begin();
        // cout<<posi<<" "<<posf<<endl;
        // cout<<mat[j].end()-mat[j].begin()<<" - -- " <<endl;
      /*  foi( k , posi, posf)
        {
          vb[count[k]]++;
          if( vb[count[k]] >= count[k]+1 )
            mm=max(count[k]+1,mm);
          count[k]++;
        }*/
        v.push_back(make_pair(posi,posf));
      }
      foi( i , 0 , v.size() )
      {
        int num=0;
        foi( j , i+1 , v.size() )
        {
          if( )
        }
      }
      printf("%d\n",mm );
    }
    printf("-\n");
  }
  return 0;
}
