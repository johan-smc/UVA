#include <iostream>
#include <list>

using namespace std;

int main()
{
  string line;
  while(getline(cin,line))
  {
    list<char> fin;
    list<char>::iterator it=fin.begin();
    for( int i = 0 ; i < line.size() ; ++i)
    {
      if( line[i]=='[' )
        it=fin.begin();
      else if( line[i]==']')
        it=fin.end();
      else
        fin.insert(it,line[i]);
    }
    for( it=fin.begin() ; it!=fin.end() ; ++it )
    {
      printf("%c",*it);
    }
    printf("\n");
  }
}
