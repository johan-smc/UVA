#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  string n;
  while(cin>>n && n!="#")
  {
    if(next_permutation(n.begin(),n.end()))
      cout<<n<<endl;
    else
      printf("No Successor\n" );
  }
  return 0;
}
