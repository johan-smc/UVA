#include <iostream>
#include <cstdio>
#include <map>
#include <set>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )
using namespace std;

// int xx[4]={ 1,0, -1,0};
// int yy[4]={ 0, 1,0,-1};
int xx[4]={ 0,1, 0,-1};
int yy[4]={ 1, 0,-1,0};

map<char,int> dd;
map<int,char> ddi;
int main()
{
  int n,m;
  dd['N']=0;
  dd['E']=1;
  dd['S']=2;
  dd['W']=3;
  ddi[0]='N';
  ddi[1]='E';
  ddi[2]='S';
  ddi[3]='W';
  set<pair<int,int> > perdido;
  scanf("%d%d",&n,&m);
  string co;
  int x,y;
  char d;
  while( scanf("%d%d %c",&x,&y,&d)!=EOF )
  {
    cin>>co;
    int pos=dd[d];
    int ant=pos;
    int i=0;
    bool pas=false;
    for( i = 0 ;i< (int)co.size() ;++i)
    {
      int nextx=x;
      int nexty=y;
      if(co[i]=='L')
      {
        ant--;
        if(ant<0)
          ant=3;

      }
      else if( co[i] == 'R' )
      {
        ant++;
        ant%=4;
      }
      else if( co[i]=='F')
      {
        pas=true;
        nextx=x+xx[ant];
        nexty=y+yy[ant];

        if( (nextx <0 || nexty<0||nextx>n||nexty> m )&& perdido.find(make_pair(x,y))==perdido.end()){
          perdido.insert(make_pair(x,y) );
        break;

      }
        pos=ant;
      }
      //  cout<<nextx<<" "<<nexty<<" "<<ant<<" "<<co[i]<<endl;
      if( perdido.find(make_pair(x,y))==perdido.end() || (nextx>= 0 && nexty>=0&& nextx<=n && nexty<=m))
      {  x=nextx;
      y=nexty;
      }
      // if(!pas)
        pos=ant;
    }
    printf("%d %d ",x,y);
    if( i  <  ( int )co.size() )
    {
      printf("%c LOST\n",ddi[pos]);
    }
    else
      printf("%c\n",ddi[ant]);
  }

  return 0;
}
