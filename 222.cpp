#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


struct Station{
  double d,c;
};

double fun(double mill,double costMill,double g,double c,vector<Station> &stations,double final)
{
      // printf("%lf -- %lf >= %lf\n",mill,mill+(costMill*g),final );
  if(mill+(costMill*g)>=final)
  {
    // printf("%lf --- a-  -  -s-- - s\n",c );
    return c;
  }
  double minimo=999999999;
  bool pass=true;
  for( int i =  0 ;  i < stations.size() ; ++i )
  {
    if(stations[i].d>= mill+((g*costMill)/2 )&& stations[i].d <= mill+(g*costMill) )
    {
      double gas=((stations[i].d-mill)/costMill);
      double cost=stations[i].c*gas;
      cost = ((int)(cost  + .5) / 1.0);
      // gas=((int)(gas * 100 + .5) / 100.0);
      double result=fun(stations[i].d,costMill,g,c+(cost)+200,stations,final);
      // printf("%lf %lf - %lf %lf\n",minimo,result ,stations[i].d,stations[i].c);
      minimo=min(minimo,result);
      pass=false;
      // printf("%lf --d\n",minimo );
    }
  }
  if(pass)
  {
    for( int i =  0 ;  i < stations.size() ; ++i )
    {
      if(mill<stations[i].d&&stations[i].d <= mill+(g*costMill) )
      {
        double gas=((stations[i].d-mill)/costMill);
        double cost=stations[i].c*gas;
        cost = ((int)(cost  + .5) / 1.0);
        // gas=((int)(gas * 100 + .5) / 100.0);
        double result=fun(stations[i].d,costMill,g,c+(cost)+200,stations,final);
        //  printf("%lf %lf - %lf %lf\n",minimo,result ,stations[i].d,stations[i].c);
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
      scanf("%lf%lf",&stations[i].d,&stations[i].c);
    }
    printf("Data Set #%d\n",++c );
    printf("minimum cost = $%.2lf\n", (double)fun(0,mg,tf,ic*100,stations,d)/100);
  }
  return 0;
}
