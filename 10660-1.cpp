#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define foi( i , n , k )for( int i = n ; i < k ; ++i)
using namespace std;


int dis( int a ,int b)
{
  return abs((a%5)-(b%5))+abs((a/5)-(b/5));
}

void sumMin(vector<int>&v,vector<int> &r,vector<int>&temp,int &mm)
{
  int sum=0;
  foi( i , 0 , 25)
  {
    if(v[i]>0)
    {

      int mmin=99999999;
      foi( j, 0 ,5)
      {
        mmin=min(((v[i])*(dis(i,temp[j]))),mmin);
      }
      sum+=mmin;
    }
  }
  if(sum<mm)
  {
    mm=sum;
    r=temp;
  }
}

void funcion(vector<int>&v,vector<int> &r)
{
  int min=999999;
  vector<int> temp(5);
  foi( i , 0 , 21 )
  {
    temp[0]=i;
    foi( j , i+1 , 22 )
    {
      temp[1]=j;
      foi( k , j+1 , 23 )
      {
        temp[2]=k;
        foi( m , k+1 , 24)
        {
          temp[3]=m;
          foi( n , m+1 , 25 )
          {
            temp[4]=n;
            sumMin(v,r,temp,min);
          }
        }
      }
    }
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int n;
    scanf("%d",&n);
    vector< int> v(25);
    foi( i , 0 , 25 )
      v[i]=0;
    while(n--){
      int i,j;
      scanf("%d%d",&i,&j);
      scanf("%d",&v[((i*5)+j)]);

    }
    vector<int> fin;
    funcion(v,fin);
    foi( i , 0 ,5 ){
      if(i!=0)
        printf(" ");
      printf("%d",fin[i]);
    }
    printf("\n");
  }
  return 0;
}
