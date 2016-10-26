#include <iostream>
#include <vector>
#include <cstdio>

#define foi( i , n , k ) for( int i =  n ; i < k ; ++i )
using namespace std;

int sumArr(vector<int> &arr,int tam)
{
  int totMay=-9999999;
  foi( n , 0 , tam )
  {
    int may=-9999999;
    int sum=0;
    foi( i , n , n+tam )
    {
      sum+=arr[i];
      if(may<sum)
        may=sum;
      if(sum<0)
        sum=0;
    }
    if(totMay<may)
      totMay=may;
  }
  return totMay;
}

int maxSum(  vector< vector< int > > &mat,int tam)
{
  int may,mayTot,sum;
  mayTot=-9999999;


        foi( k , 0 , tam )
        {
          vector<int> arr(2*tam,0);
          foi(m , k ,k+ tam )
          {
            foi( n , 0 ,2* tam )
            {
              arr[n]+=mat[m][n];
            }
            may=sumArr(arr,tam);
           if(mayTot<may)
              mayTot=may;

          }

        }


  return mayTot;
}

int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int tam;
    scanf("%d",&tam);
    vector< vector< int > > mat(2*tam,vector<int>(tam*2));
    foi( i , 0 , tam )
    {
      foi( j , 0 , tam )
      {
        int num;
        scanf("%d",&num);
        mat[i][j]=num;
        mat[i][j+tam]=num;
        mat[i+tam][j]=num;
        mat[i+tam][j+tam]=num;
      }
    }
    printf("%d\n",maxSum(mat,tam) );
  }
  return 0;
}
