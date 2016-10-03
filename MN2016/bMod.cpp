#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

#define foi( i , n , k ) for( int  i = n ; i < k ; ++i )


using namespace std;

typedef pair< int , int > ii;

int xx[4]={-1,0,0,1};
int yy[4]={0,1,-1,0};
int xxI[4]={-1,0,0,1};
int yyI[4]={0,-1,1,0};

struct Ping
{
  ii a,b;
  bool operator<( const Ping& o)const
  {
    return o.a==this->a?this->b<o.b:this->a<o.a;
  }
};


bool isGood( std::vector<std::vector<char> > &mapa, Ping &temp , map< Ping , int > &pas , int x , int y, Ping &now)
{
  // cout<< "--. " << temp.a.first <<  " " << temp.a.second << " " << temp.b.first << " " << temp.b.second << endl ;
  // cout<< "--. " <<  (pas.find(temp) != pas.end()) << endl;
  if( pas.find(temp) != pas.end() )
    return false;
  pas[temp]=pas[now]+1;
  if( temp.a.first < 0 )
    return false;
  if( temp.a.first >= x )
    return false;
  if( temp.a.second < 0 )
    return false;
  if( temp.a.second >= y )
    return false;
  if( mapa[temp.a.first][temp.a.second] != '.' )
    return false;
  if( temp.b.first < 0 || temp.b.first >= x || temp.b.second < 0 || temp.b.second >= y ||mapa[temp.b.first][temp.b.second] != '.' ){
    temp.b=now.b;
  }
  return true;
}

void imprimir( std::vector<std::vector<char> > &mapa,Ping &ini , int x , int y , ii fin)
{
  string ab;
  getline(cin,ab);
  foi( i ,  0 , x )
  {
    foi( j , 0 , y )
    {
      if( i == ini.a.first && j == ini.a.second )
        cout<<"*";
      else if( i == ini.b.first && j == ini.b.second )
        cout<<"^";
      else if( i == fin.first && j == fin.second )
        cout<<'c';
      else
        cout<<mapa[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}

int bfs(std::vector<std::vector<char> > &mapa,Ping &ini,ii posFin, int x ,int y )
{
  queue< Ping > q;
  map< Ping , int > pas;
  q.push( ini );
  pas[ini]=0;
  while( ! q.empty() )
  {
    Ping now=q.front();
    q.pop();
    // cout<<now.a.first <<  " " << now.a.second << " " << now.b.first << " " << now.b.second << endl ;
    //  imprimir( mapa , now , x , y ,posFin );
    if( posFin == now.a && posFin == now.b )
      return pas[now];
    foi( i , 0 , 4 )
    {
      Ping temp;
      temp.a.first=now.a.first+xx[i];
      temp.a.second=now.a.second+yy[i];
      temp.b.first=now.b.first+xxI[i];
      temp.b.second=now.b.second+yyI[i];

      if( isGood(mapa,temp,pas,x,y,now) )
      {
        pas[temp]=pas[now]+1;
        // cout<< "confi " << (pas.find(temp) != pas.end()) << endl;
        q.push(temp);
      }
    }
    foi( i , 0 , 4 )
    {
      Ping temp,tempb;
      temp.a.first=now.a.first+xx[i];
      temp.a.second=now.a.second+yy[i];
      temp.b.first=now.b.first+xxI[i];
      temp.b.second=now.b.second+yyI[i];
      tempb.a=temp.b;
      tempb.b=temp.a;
      if( isGood(mapa,tempb,pas,x,y,now) )
      {
        pas[temp]=pas[now]+1;
        // cout<< "confi " << (pas.find(temp) != pas.end()) << endl;
        q.push(temp);
      }
    }
  }
  return -1;

}


int main()
{
  int x,y;
  while( scanf("%d %d",&x,&y ) != EOF )
  {
    Ping ini;
    ii posFin;
    scanf("%d %d",&posFin.first,&posFin.second );
    scanf("%d %d",&ini.a.first,&ini.a.second );
    scanf("%d %d",&ini.b.first,&ini.b.second );
    --posFin.first;
    --posFin.second;
    --ini.a.first;
    --ini.a.second;
    --ini.b.first;
    --ini.b.second;
    std::vector< std::vector<char> > mapa(x,std::vector<char> (y));
    foi( i , 0 , x )
    {
      foi( j , 0 , y )
      {
        scanf(" %c",&mapa[i][j] );
      }
    }
    int num=bfs(mapa,ini,posFin,x,y);
    if(num!=-1)
    {
      printf("%d\n",num);
    }
    else
    {
      printf("NO LOVE\n" );
    }
  }
  return 0;
}
