#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define foi( i , k , n) for( int i = k ; i < n ; ++i )

using namespace std;

int pos[26];
int main()
{
  string line;
  int c=0;
  while( cin>>line && line != "end" )
  {
    memset( pos , -1 , sizeof pos );
    int t=0;
    foi( i , 0  , line.size() )
    {
      if( pos[ line[i]-'A' ]==-1 )
        t++;
      pos[ line[i]-'A' ]=i;
    }
    vector< stack< char > > res;
    vector< stack< char > > rss;
    res.push_back( stack< char >() );
    res[0].push(line[0]);
    rss=res;
    foi( i , 1 , line.size() )
    {
      bool pas=true,pss=true;
      foi( j , 0 , rss.size() )
      {
        if( res[j].top() >= line[i] )
        {
          res[j].push(line[i]);
          pss=false;
          break;
        }
      }
      foi( j , 0 , res.size() )
      {
        if( res[j].top() == line[i] )
        {
          res[j].push(line[i]);
          pas=false;
          break;
        }
      }
      for( int j = 0 ; j < res.size() && pas ; ++j )
      {
        if( res[j].top() > line[i] && pos[res[j].top()-'A'] < i )
        {
          res[j].push(line[i]);
          pas=false;
          break;
        }
      }
      if( pas )
      {
        res.push_back( stack< char >() );
        res[res.size()-1].push(line[i]);
      }
      if( pss )
      {
        rss.push_back( stack< char >() );
        rss[rss.size()-1].push(line[i]);
      }
    }
    int may=min(t,(int)res.size());
    may=min(may,(int)rss.size());
    // cout<<t<<" "<<res.size()<<" "<<rss.size()<<endl;
    printf("Case %d: %d\n",++c,may);
  }

  return 0;
}
