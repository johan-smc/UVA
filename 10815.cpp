#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
  char c;
  string str;
  set<string> s;
  while( scanf("%c",&c)!=EOF )
  {
    if(( c<='z' && c>='a' )||( c<='Z'&&c>='A'))
    {
      if(c<='Z'&&c>='A')
        c+=32;
      str+=c;
    }
    else
    {
      if(str!="")
      s.insert(str);
      str="";
    }
  }
  for( set<string>::iterator it=s.begin() ; it!=s.end() ; ++it ){
    cout<<*it<<endl;;
  }
  return 0;
}
