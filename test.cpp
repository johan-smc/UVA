#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> q(5,0);
  q[0]=1;
  q[1]=3;
  q[2]=6;
  q[3]=7;
  q[4]=12;
  int next,pos;
  scanf("%d",&next );
   pos=lower_bound(q.begin(),q.end(),next)-q.begin();
   printf("%d\n",pos );
  return 0;
}
