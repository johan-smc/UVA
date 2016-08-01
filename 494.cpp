#include <iostream>
#include <cstdio>

#define foi( i , n , k ) for( int i = n  ; i < k ; ++i )

using namespace std;

int main()
{
  string line;
  while( getline(cin,line ) )
  {
    int p=0;
    bool otro=true;
    foi( i , 0 , line.size() )
    {
      if( (line[i]>='a' && line[i]<='z' )||(line[i]>='A'&& line[i]<='Z'))
      {  if(otro)
        {
          // cout<<line[i]<<" "<<i<<endl;
          p++;
          otro=false;
        }}
      else
        otro=true;
    }
    printf("%d\n",p);
  }
  return 0;
}
