#include <iostream>
#include <vector>

#define TAM 1000005

using namespace std;


bool funcion(vector< pair<int,int> > &v,int a,int b)
{
  for( int i = 0 ; i < v.size() ; ++i )
  {
    if( (a < v[i].first && b > v[i].second ) || ( v[i].first < a && v[i].second > b ) )
      return false;
  }
  v.push_back(make_pair(a,b));
  return true;
}

bool funcion(vector< pair<int,int> > &v,int a,int b,int r)
{
  while( a < TAM && b < TAM )
  {
    if(!funcion(v,a,b))
      return false;
    a+=r;
    b+=r;
  }
  return true;
}

int main()
{
  int n,m;
  while( scanf("%d%d",&n,&m)!=EOF && (n!=0||m!=0) )
  {
    bool s=true;
    int a,b,r;
    vector< pair<int,int> > v;
    for( int i = 0 ; i <  n ; ++i )
    {
      scanf("%d%d",&a,&b);
      if(s)
        s=funcion(v,a,b);
    }
    for( int i = 0 ; i < m ; ++i  )
    {
      scanf("%d%d%d",&a,&b,&r);
      if( s )
        s=funcion(v,a,b,r);
    }
    if(s)
      printf("NO CONFLICT\n");
    else
      printf("CONFLICT\n");
  }
  return 0;
}
