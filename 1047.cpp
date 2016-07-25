#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>

#define foi(i , n , k  )for( int i =  n ; i <  k ; ++i)
using namespace std;

void back( vector<int> &fin,vector<int> temp, int voy,int pos,int &sumMaxima,int r,vector<int> &cos,vector< pair<set<int> , int> >&rr)
{
  if( voy<r)
  {
    foi( i , pos ,(int)cos.size() )
    {
      temp[voy]=i;
      // cout<<voy<<" "<<i<<" voy a "<<voy+1<<" con "<<i+1<<" r="<<r<<endl;
      back(fin,temp,voy+1,i+1,sumMaxima,r,cos,rr);
    }
  }
  else
  {
    int sum=0;
    foi( i , 0, (int)temp.size() )
    {
      sum+=cos[temp[i]];
      // cout<<temp[i]<<" ";
    }
    // cout<<endl;
    // cout<<" nn "<<sum<<endl;
    foi( i , 0 , (int)rr.size() )
    {
      int l=0;
      foi( j , 0 , (int)temp.size() )
      {
        if( rr[i].first.find(temp[j])!=rr[i].first.end())
          l++;
      }
      if( l )
      {
        l--;
        sum-=l*rr[i].second;
        // cout<<"resto "<<l*rr[i].second<<" l "<<l<<endl;
      }
    }
    // cout<<voy<<" sum "<<sum<<" sum m "<<sumMaxima<<endl;
    if(sum>sumMaxima)
    {
      fin=temp;
      sumMaxima=sum;
    }
  }
}

int main()
{
  int p,r,t=0;
  while( scanf("%d%d",&p,&r)!=EOF && (p!=0||r!=0))
  {
    vector<int> cos(p),rep;
    vector< pair<set<int> , int> > rr;
    foi( i , 0 , p )
    {
      scanf("%d",&cos[i]);
    }
    int m;
    scanf("%d",&m);
    foi( i , 0 , m )
    {
      int n;
      scanf("%d",&n);
      rep.assign(n,0);
      rr.push_back(make_pair(set<int>(),0));
      foi( j , 0 , n)
      {
        scanf("%d",&rep[j]);
        rr[rr.size()-1].first.insert(rep[j]-1);
      }
      int c;
      scanf("%d",&c);
      rr[rr.size()-1].second=c;

    }
    vector<int> fin(r);
    int sumM=-9999999;
    back(fin,fin,0,0,sumM,r,cos,rr);
    printf("Case Number  %d\n",++t );
    printf("Number of Customers: %d\n",sumM );
    printf("Locations recommended:");
    foi( i , 0 , fin.size() )
    {
      printf(" %d",fin[i]+1 );
    }
    printf("\n\n" );
  }
  return 0;
}
