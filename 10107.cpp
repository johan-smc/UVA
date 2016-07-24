#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  vector<int> v;
  while(scanf("%d",&n)!=EOF)
  {
    v.push_back(n);
    int tot;
    nth_element(v.begin(),v.begin()+(v.size()/2),v.end());
    tot=v[v.size()/2];
    if(!(v.size()%2)){
      nth_element(v.begin(),v.begin()+(v.size()/2)-1,v.end());
      tot+=v[(v.size()/2)-1];
      tot/=2;
      // cout<<tot<<" -- "<<endl;
    }
    printf("%d\n",tot);
  }
  return 0;
}
