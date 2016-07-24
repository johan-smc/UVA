#include <iostream>
#include <vector>

using namespace std;
int cont=0;
pair<int,pair< vector<bool> , vector<bool> > >  fun(int index,vector< vector<int> > &gra,vector<bool> pas,vector<bool> color,int ll)
{
  bool col=true;
  pair<int,pair< vector<bool> , vector<bool> > > may,temp;
  may.first=-1;
  if( index >= gra.size() || pas[index] )
    return may;
     printf("%d...... %d .. %d\n",cont++,index,ll );
  may.first=ll;
  may.second.first=color;
  may.second.second=pas;
  for( int i = 0 ; i < gra[index].size() && col ; ++i )
  {
    int next=gra[index][i];
    if( !color[next] )
      col=false;
  }
  pas[index]=true;
  for( int i = 0 ;i < gra[index].size() ; ++i)
  {
    int next=gra[index][i];
    temp=fun(next,gra,pas,color,ll);
    may=((may.first>temp.first)?may:temp);

  }
  if(col)
  {

    color[index]=false;
    for( int i = 0 ;i < gra[index].size() ; ++i)
    {
      int next=gra[index][i];
      temp=fun(next,gra,pas,color,ll+1);
      may=((may.first>temp.first)?may:temp);
    }
  }
  return may;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    vector< vector<int> > gra(n,vector<int>());
    vector<bool> pas(n,false);
    vector<bool> color(n,true);
    for( int i = 0 ; i < m ; ++i )
    {
      int x,y;
      scanf("%d%d",&x,&y);
      x--;
      y--;
      gra[x].push_back(y);
      gra[y].push_back(x);
    }
      pair<int,pair< vector<bool> , vector<bool> > > may,temp;
    may.first=-1;
    may.second.first=color;
    may.second.second=pas;
    for( int i= 0 ; i < m ; ++i )
    {
      temp=fun(i,gra,may.second.second,may.second.first,0);
      may=((may.first>temp.first)?may:temp);
    }
    printf("%d\n",may.first );
    int c=0;
    for( int i = 0 ; i < may.second.first.size() ; ++i )
    {
      if( !may.second.first[i] )
      {
        ++c;
        printf("%d",i+1 );
        if(c==may.first)
          printf("\n" );
        else
          printf(" " );
      }
    }
  }
  return 0;
}
