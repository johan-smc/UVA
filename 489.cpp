#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>

#define foi( i , n , k) for( int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  int round;
  while( scanf("%d",&round)!=EOF && round!=-1)
  {
    string a,b;
    queue<char> q;
    set<char> st,ju;
    cin>>a>>b;
    int fails=0;
    foi( i , 0 , b.size() )
    {
      bool s=false;
      if( ju.find(b[i])!=ju.end() )
        continue;
      foi( j , 0 , a.size() )
      {
        if(b[i]==a[j])
        {
          ju.insert(a[j]);
          q.push(a[j]);
          s=true;
        }
      }
      if(a.size() <= q.size() )
        break;
      if(!s && st.find(b[i])==st.end()){
        st.insert(b[i]);
        fails++;}
    }
    printf("Round %d\n",round );
    if( fails >= 7)
      printf("You lose.\n");
    else if( q.size() >= a.size() )
      printf("You win.\n");
    else
      printf("You chickened out.\n");
  }
  return 0;
}
