#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Station{
  int d,c;
};

int fun(int mill,int costMill,int g,int c,vector<Station> &stations,int final)
{
      printf("%d -- %d >= %d\n",mill,mill+(costMill*g),final );
  if(mill+(costMill*g)>=final)
  {
    // printf("%d --- a-  -  -s-- - s\n",c );
    return c;
  }
  int minimo=999999999;
  bool pass=true;
  for( int i =  0 ;  i < stations.size() ; ++i )
  {
    if(stations[i].d>= mill+((g*costMill)/2 )&& stations[i].d <= mill+(g*costMill) )
    {
      int gas=((stations[i].d-mill)/costMill);
      int result=fun(stations[i].d,costMill,g,c+(stations[i].c*gas)+200,stations,final);
         printf("%d %d - %d %d\n",minimo,result ,stations[i].d,stations[i].c);
      minimo=min(minimo,result);
      pass=false;
      // printf("%d --d\n",minimo );
    }
  }
  if(pass)
  {
    for( int i =  0 ;  i < stations.size() ; ++i )
    {
      if(mill<stations[i].d&&stations[i].d <= mill+(g*costMill) )
      {
        int gas=((stations[i].d-mill)/costMill);
        int result=fun(stations[i].d,costMill,g,c+(stations[i].c*gas)+200,stations,final);
        //  printf("%d %d - %d %d\n",minimo,result ,stations[i].d,stations[i].c);
        minimo=min(minimo,result);
        pass=false;
        // printf("%lf --d\n",minimo );
      }
    }
  }
  return minimo;
}

int main()
{
  double d;
  int c=0;
  while(scanf("%lf",&d)!=EOF&&d>0)
  {
    double tf,mg,ic;
    int t;
    scanf("%lf%lf%lf%d",&tf,&mg,&ic,&t);
    vector<Station> stations(t);
    for( int i = 0 ; i < t; ++i )
    {
      double a,b;
      scanf("%lf%lf",&a,&b);
      stations[i].d=a*1000000;
      stations[i].c=b*1000000;
    }
    printf("Data Set #%d\n",++c );
    printf("minimum cost = $%.2lf\n", (double)fun(0,mg*1000000,tf*1000000,ic*100000000,stations,d*1000000)/1000000);
  }
  return 0;
}
