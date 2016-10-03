#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>

#define LIM 100000
#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;


void reconstruct_print(int lis_end,int* A,int* P)
{
  int x=lis_end;
  stack<int> s;
  while(P[x]>=0){
    s.push(A[x]);
    x=P[x];
  }
  s.push(A[x]);
  while(!s.empty())
  {
    printf("%d\n",s.top() );
    s.pop();
  }
}

int main()
{
  int tam=0;
  int A[LIM];
  while( scanf("%d",&A[tam++] )!=EOF );
  int L[LIM],L_id[LIM],P[LIM];
  int lis=0,lis_end=0;
  foi( i ,0  , tam )
  {
    int pos=lower_bound(L,L+lis,A[i])-L;
    L[pos]=A[i];
    L_id[pos]=i;
    P[i]= pos?L_id[pos-1]:-1;
    if(pos+1>lis)
    {
      lis=pos+1;
      lis_end=i;
      // cout<<lis<<" "<<lis_end<<endl;
    }
  }
  printf("%d\n-\n",lis);
  reconstruct_print(lis_end,A,P);
  return 0;
}
