#include <iostream>
#include <cstdio>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

int main()
{
  string line;
  while( getline(cin,line) )
  {
    foi( i ,0 , line.size() )
      printf("%c",line[i]-7);
    printf("\n");
  }
}
