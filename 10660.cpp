#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define foi( i , n , k ) for( int i =  n ; i < k ; ++i)
using namespace std;

void funcion(vector< vector<int> > &map,int i,int j,queue< pair<pair<int,int>,int > > q,priority_queue< pair< int , int > >& pq)
{
  int sum=0;
  while(!q.empty())
  {
    pair< pair<int , int > ,int>  temp=q.front();
    // cout<<temp.first.first<<" "<<temp.first.second<<" "<<temp.second<<endl;
    sum+=(abs(temp.first.first-i)+abs(temp.first.second-j)*temp.second);
    q.pop();
  }
  map[i][j]=sum;
  cout<<sum<<" "<<((i*5)+j)<<endl;
  pq.push(make_pair(-sum,-((i*5)+j)));
}

int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int p;
    vector< vector<int> > map(5,vector<int>(5,0));
    scanf("%d",&p);
    queue< pair<pair<int,int>,int > > q;
    foi( i , 0 , p )
    {
      int x,y,n;
      scanf("%d%d%d",&x,&y,&n);
      q.push(make_pair(make_pair(x,y),n));
      map[x][y]=n;
    }
    priority_queue< pair< int , int > > pq;
    foi( i , 0 ,5 )
    {
      foi( j , 0 ,5  )
      {
        funcion(map,i,j,q,pq);
      }
    }
    vector<int> fin;
    foi( i , 0 , 5)
    {
      fin.push_back(-pq.top().second);
      pq.pop();
    }
    sort(fin.begin(),fin.end());
    foi( i , 0 ,5 )
    {
      if( i != 0 )
        printf(" ");
      printf("%d",fin[i]);
    }
    printf("\n");
  }
  return 0;
}
