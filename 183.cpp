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
  for( int  i = xi ; i <= xf  ; ++i  )
  {
    for ( int j =  yi ; j <= yf  ; ++j )
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
/*  int sx,sy;
  sx=sy=0;
  if((xi+xf+1&1))
    ++sx;
  if((yi+yf+1)&1)
    ++sy;*/
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
  // cout<<m[n]<<" "<<n<<" "<<xi<<" "<<yi<<" "<<xf<<" "<<yf<<endl;
  if(m[n]=='D')
  {
    ++n;
  /*  int sx,sy;
    sx=sy=0;
    if(((xi+xf+1)&1))
      ++sx;
    if((yi+yf+1)&1)
      ++sy;*/
    llenar(m,n,mat,xi,yi,(xi+xf)/2,(yi+yf)/2);
    llenar(m,n,mat,xi,(yi+yf)/2+1,(xi+xf)/2,yf);
    llenar(m,n,mat,(xi+xf)/2+1,yi,xf,(yi+yf)/2);
    llenar(m,n,mat,(xi+xf)/2+1,(yi+yf)/2+1,xf,yf);
  }
  else
  {
    for( int  i = xi ; i <= xf ; ++i  )
    {
      for ( int j =  yi ; j <= yf ; ++j )
      {
        mat[i][j]=m[n]-'0';
      }
    }
    ++n;
  }
}

using namespace std;

int main()
{
  char c;
  while( scanf(" %c",&c)!=EOF && c!='#')
  {
    int x,y;
    char temp;
    scanf("%d%d",&x,&y);
    vector< vector< bool > > mat(x,std::vector<bool> (y));
    int line=0;
    if(c=='B')
    {
      printf("D" );
      printf("%4d%4d\n",x,y);
      foi( i , 0 , x)
        foi ( j , 0 , y )
        {
          scanf(" %c",&temp);
          mat[i][j]=bool(temp-'0');
        }
      /*foi( i , 0 , x){
        foi ( j , 0 , y )
          printf("%d",(int)mat[i][j] );
        printf("\n" );
      }*/
      string res=imprimir(mat,0,0,x-1,y-1);
      foi( i , 0 , res.size() )
      {
        printf("%c",res[i] );
        ++line;
        if(line==50){
          printf("\n" );
          line=0;
        }
      }
      if(line!=0)
        printf("\n" );
    }
    else if(c=='D')
    {
      printf("B" );
      printf("%4d%4d\n",x,y);
      string m;
      cin>>m;
      int pos=0;
      llenar(m,pos,mat,0,0,x-1,y-1);
      foi( i , 0 , x)
        foi ( j , 0 , y ){
          printf("%d",(bool)mat[i][j]);
          ++line;
          if(line==50){
            printf("\n" );
            line=0;
          }
        }
      if(line!=0)
      printf("\n" );
    }
  }
  return 0;
}
