#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool arr[10][7]=
{
  {1,1,1,1,1,1,0},{0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},{1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},{1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},{1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},{1,1,1,1,0,1,1}
};

vector< bitset<7> > ver(10);

void init()
{

  ver[0]=bitset<7>("0111111");
  ver[1]=bitset<7>("0000110");
  ver[2]=bitset<7>("1011011");
  ver[3]=bitset<7>("1001111");
  ver[4]=bitset<7>("1100110");
  ver[5]=bitset<7>("1101101");
  ver[6]=bitset<7>("1111101");
  ver[7]=bitset<7>("0000111");
  ver[8]=bitset<7>("1111111");
  ver[9]=bitset<7>("1101111");
}

bool fun(vector< bitset<7> > &v,vector<bool> &pas)
{
  int pos=9;
  bool yes=true;
  for( int i = 0 ; i < v.size() && yes; ++i )
  {
    yes=false;
    for( int j = pos; j>= 0 ; j--)
    {
      //  printf("%d %d int\n",i,j );
      //  cout<<(!pas[j])<<" "<<((v[i]|ver[j])==ver[j])<<" "<<(v[i]|ver[j])<<" "<<v[i]<< " "<<ver[j]<<endl;
      if((v[i]|ver[j])==ver[j])
      {
        //  printf("%d %d pas\n",i,j );
        pas[j]=true;
        pos=j-1;

          yes=true;
        break;
      }
    }
  }
  return yes;
}

int main()
{
  int n;
  init();
  while(scanf("%d\n",&n)!=EOF && n!=0)
  {
    vector< bitset<7> > v(n,bitset<7>());
    vector< bool > pas(n,false);
    for( int i = 0 ; i <  n ;++i )
    {
      for( int j = 0 ; j < 7 ; ++j )
      {
        char op;
        scanf(" %c",&op );
        if(op=='Y')
          v[i].set(j);
      }
      //  cout<<v[i]<<" "<<pas[i]<<endl;
    }

    if( fun(v,pas) )
    printf("MATCH\n");
    else
    printf("MISMATCH\n" );
  }
  return 0;
}
