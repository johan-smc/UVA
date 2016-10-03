#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

void LLIS(std::vector< int > &v,std::vector< int > &l, int pos )
{
  if(v.size() == 0 )
    return ;
    int may=-1;
    for( int i  = v.size()-1 ; i > pos ; --i )
    {
      if( l[i] == -1 )
      {
        LLIS(v,l,i);
      }
      if( v[i] > v[pos] )
      {
        may=max(may,l[i]);
      }
    }
    if( may == -1 )
      l[pos] = 1;
    else
      l[pos] = may + 1;

}


int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int tam;
    scanf("%d",&tam);
    vector< int > v(tam);
    vector< int > vI(tam);
    vector< int > lis(tam,-1);
    vector< int > lisI(tam,-1);
    foi( i , 0 , tam )
    {
      scanf("%d",&v[i]);
      vI[i]=-v[i];
    }
    LLIS(v,lis,0);
    LLIS(vI,lisI,0);
    /*foi( i , 0 , tam )
    {
      cout<<" "<<lis[i];
    }
    cout<<endl;
    foi( i , 0 , tam )
    {
      cout<<" "<<lisI[i];
    }
    cout<<endl;*/
    int may=0;
    foi( i , 0 , tam )
    {
      may=max(may,lisI[i]+lis[i]-1);
    }
    printf("%d\n",may);
  }
  return 0;
}
