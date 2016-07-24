#include <iostream>
#include <queue>
#include <vector>

#define foi( i , k , n) for( int i =  k ; i < n ; ++i )
using namespace std;

int main()
{
  int ca;
  scanf("%d",&ca);
  while(ca--)
  {
    int n,t,m,min;
    string dir;
    queue< pair< int , int > > left,right;
    scanf("%d%d%d",&n,&t,&m);
    foi( i , 0 , m )
    {
      scanf("%d",&min);
      cin>>dir;
      if(dir=="left")
      {
        left.push(make_pair(min,i));
      }
      else if( dir =="right")
      {
        right.push(make_pair(min,i));
      }
    }
    int time=0;
    bool pos=true;
    std::vector<int> print(m);
    while( !left.empty() || !right.empty() )
    {

      int c=0;
    // cout<<" -- "<<c<<" "<<pos <<" " <<time<<" " <<left.size() <<" " <<right.size() <<endl;
      if( pos   )
      {
        if( left.empty() )
        {
          if( !right.empty())
          {
            if(  time+t > right.front().first+t)
              time+=t;
            else
              time=right.front().first+t;
          }
          pos=false;
          continue;
        }
        if( left.front().first <= time)
        {
          while( !left.empty() && left.front().first <= time && c < n)
          {
            print[left.front().second]=(time+t);
            left.pop();
            c++;
          }
          time+=t;
        }
        else if( right.empty() || left.front().first <= right.front().first)
        {
          // cout<<"1a"<<endl;
          time=left.front().first;
          pos=false;
        }
        else
        {
          // cout<<"2a "<<right.front().first<<" "<<t<<endl;
          if( time+t < right.front().first+t)
            time=right.front().first+t;
          else
            time+=t;
        }
          pos=!pos;
      }
      else
      {
        if( right.empty() )
        {
          if( !left.empty())
          {
            if(  time+t > left.front().first+t)
              time+=t;
            else
              time=left.front().first+t;
            }
          pos=true;
          continue;
        }
        if(  right.front().first <= time )
        {
          while( !right.empty() && right.front().first <= time && c < n)
          {
            print[right.front().second]=(time+t);
            right.pop();
            c++;
          }
          time+=t;
        }
        else if( left.empty() ||(right.front().first <= left.front().first) )
        {
          // cout<<"1b "<<endl;
          time=right.front().first;
          pos=true;
        }
        else
        {
          // cout<<"2b"<<endl;
          if( time+t < left.front().first+t )
            time=left.front().first+t;
          else
            time+=t;
        }
        pos=!pos;
      }
      // cout<<m<<" "<<print.size() <<endl;
    }
    foi( i , 0 , print.size() )
    printf("%d\n",print[i] );

    if( ca!= 0 )
      printf("\n");
  }

  return 0;
}
