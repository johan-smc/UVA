#include <iostream>
#include <cstdio>
#include <vector>

#define foi( i , n , k ) for( int i =  n ; i <  k ; ++i )

string imprimir(vector< vector<bool> > &mat , int xi, int yi ,int xf,int yf)
{
  if (xi>xf||yi>yf) {
    return "";
  }
  string res="";
  pair<bool,bool> re=revisar(mat);
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

  }
  else
  {
    foi( i = xi ; i <  )
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
        cout<<imprimir(mat)<<endl;;
    }
    else if(c=='D')
    {
      string m;
      cin>>m;
      llenar(m,mat);
      foi( i , 0 , x)
        foi ( j , 0 , y )
          printf("%d",(bool)mat[i][j]);
      printf("\n" );
    }
  }
  return 0;
}
