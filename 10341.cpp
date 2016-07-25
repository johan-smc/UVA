#include <iostream>
#include <cstdio>
#include <cmath>

#define EPS 1e-7

using namespace std;



double p,q,r,s,t,u;

double f( double n )
{
  return (p*exp(-n))+(q*sin(n))+(r*cos(n))+(s*tan(n))+(t*n*n)+(u);
}

double bisection()
{
  double lo=0,hi=1,mid=0;
  while( fabs(lo-hi)>EPS )
  {
    mid=(lo+hi)/2;
    // cout<<f(lo)<<" "<<f(mid)<<endl;
    if( f(lo)*f(mid) <= 0 )
      hi=mid;
    else
      lo=mid;
    // cout<<lo<<" "<<hi<<" "<<fabs(lo-hi)<<" "<<EPS<<endl;
  }
  return (lo+hi)/2;
}

int main()
{
  while( scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)!=EOF )
  {
    // cout<<f(0)<<" "<<f(1)<<endl;
    if( f(0)*f(1)>0 )
      printf("No solution\n");
    else
      printf("%.4lf\n",bisection());
  }
  return 0;
}
