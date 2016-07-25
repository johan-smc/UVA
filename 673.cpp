#include <iostream>
#include <cstdio>
#include <stack>

#define foi( i , n , k ) for( int i = n ; i <  k ; ++i )

using namespace std;

void print(stack<char> s)
{
  while(!s.empty())
  {
    cout<<s.top();
    s.pop();
  }
  cout<<endl;
}

int main()
{
  int n;
  scanf("%d",&n);
  cin.ignore();
  while(n--)
  {
    string line;
    getline(cin,line);
    stack<char> q;
    bool pos=true;
    // cout<<line<<endl;
    foi( i , 0 , (int)line.size() )
    {
      // print(q);
      if( line[i]=='[' || line[i]=='(' )
      {
        q.push(line[i]);
      }
      else if( line[i]==']' || line[i]==')')
      {
        if(q.empty())
        {
          // cout<<"here"<<endl;
          pos=false;
          break;
        }
        if(line[i]==']'&&q.top()!='[')
        {
          pos=false;
          break;
        }
        else if( line[i]==']'&&q.top()=='[')
          q.pop();
        else if( line[i]==')'&& q.top()!='(' )
        {
          pos=false;
          break;
        }
        else
          q.pop();
      }
    }
    if(!q.empty())
      pos=false;
    if( pos )
    {
      printf("Yes\n");
    }
    else
      printf("No\n");
  }
  return 0;
}
