#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define foi( i , n , k ) for( int i =  n ; i <  k ; ++i )
using namespace std;

pair<bool,bool> revisar(vector< vector<bool> > &mat, int xi, int yi ,int xf,int yf)
{
  if (xi>xf||yi>yf) {
    return make_pair(false,false);
  }
  pair<int,int> res;
  res.second=mat[xi][yi];
  for( int  i = xi ; i <= xf ; ++i  )
  {
    for ( int j =  yi ; j < yf ; ++j )
    {
      if(res.second!=mat[i][j])
      {
        res.first=false;
        return res;
      }
    }
  }
  res.first=true;
  return res;
}

string  imprimir(vector< vector<bool> > &mat , int xi, int yi ,int xf,int yf)
{
  if (xi>xf||yi>yf) {
    return "";
  }
  string res="";
  pair<bool,bool> re=revisar(mat,xi,yi,xf,yf);
  if( re.first )
    return res+='0'+(int)re.second;
  res+='D';
  res+=imprimir(mat,xi,yi,(xi+xf)/2,(yi+yf)/2);
  res+=imprimir(mat,xi,(yi+yf)/2+1,(xi+xf)/2,yf);
  res+=imprimir(mat,(xi+xf)/2+1,yi,xf,(yi+yf)/2);
  res+=imprimir(mat,(xi+xf)/2+1,(yi+yf)/2+1,xf,yf);
  return res;
}

void llenar(const string &m,int &n,std::vector<std::vector<bool> > &mat, int xi, int yi ,int xf,int yf)
{
  if (xi>xf||yi>yf)
    return;
  if(m[n]=='D')
  {
    ++n;
    llenar(m,n,mat,xi,yi,(xi+xf)/2,(yi+yf)/2);
    llenar(m,n,mat,xi,(yi+yf)/2+1,(xi+xf)/2,yf);
    llenar(m,n,mat,(xi+xf)/2+1,yi,xf,(yi+yf)/2);
    llenar(m,n,mat,(xi+xf)/2+1,(yi+yf)/2+1,xf,yf);
  }
  else
  {
    for( int  i = xi ; i <= xf ; ++i  )
    {
      for ( int j =  yi ; j < yf ; ++j )
      {
        mat[i][j]=m[n];
      }
    }
    ++n;
  }
}

using namespace std;

int main()
{
  int c;
  while( scanf(" %c",&c)!=EOF && c!='#')
  {
    int x,y,temp;
    scanf("%d%d",&x,&y);
    vector< vector< bool > > mat;
    printf("%c %d %d",c,x,y);
    if(c=='B')
    {
      foi( i , 0 , x)
        foi ( j , 0 , y )
        {
          scanf("%d",&temp);
          mat[i][j]=temp;
        }
        cout<<imprimir(mat,0,0,x-1,y-1)<<endl;;
    }
    else if(c=='D')
    {
      string m;
      cin>>m;
      int pos=0;
      llenar(m,pos,mat,0,0,x-1,y-1);
      foi( i , 0 , x)
        foi ( j , 0 , y )
          printf("%d",(bool)mat[i][j]);
      printf("\n" );
    }
  }
  return 0;
}
