#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define foi( i , n , k) for( int i = n ; i < k ; ++i)
using namespace std;

struct Car
{
  string name;
  int min,max;
  bool operator<(const Car&o)const
  {
    if( this->min == o.min )
      return this->max<o.max;
    return this->min<o.min;
  }
};

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int c;
    scanf("%d",&c);
    vector<Car> cc(c);
    foi( i , 0 , c )
    {
      cin>>cc[i].name;
      scanf("%d%d",&cc[i].min,&cc[i].max);
    }
    sort(cc.begin(),cc.end());
    scanf("%d",&c );
    foi( i , 0 , c )
    {
      int value;
      Car tipo;
      tipo.name="";
      bool valid=false;
      scanf("%d",&value );
      for( int j = 0 ; j < cc.size() && cc[j].min <= value ; ++j )
      {
        if( cc[j].min <= value && value <= cc[j].max )
        {
          if(tipo.name!="")
          {
            valid=false;
            break;
          }
          else
          {
            valid=true;
            tipo=cc[j];
          }
        }
      }
      if(valid)
      {
        cout<<tipo.name<<endl;
      }
      else
      {
        printf("UNDETERMINED\n");
      }
    }
    if(t!=0)
    printf("\n" );
  }
  return 0;
}
