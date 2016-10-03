#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
  double x;
  double y;
  point(  ) { x = y = 0; }
  point( double _x, double _y ): x(_x), y(_y) {}
};

struct vec
{
  double x,y;
  vec( double _x, double _y ) : x(_x), y(_y) {}
};

vec toVec( point a, point b )
{
  return vec( b.x - a.x, b.y - a.y );
}

vec scale( vec v, double s )
{
  return vec( v.x * s, v.y * s );
}

point translate( point p, vec v )
{
  return point( p.x + v.x, p.y + v.y );
}

double hypot( double dx, double dy )
{
  return sqrt( dx * dx + dy * dy );
}

double dist( point p1, point p2 )
{
  return hypot( p1.x - p2.x, p1.y - p2.y );
}

double dot( vec a, vec b )
{
  return (a.x * b.x + a.y * b.y);
}

double norm_sq( vec v )
{
  return v.x * v.x + v.y * v.y;
}

double distToLine( point p, point a, point b, point &c )
{
  vec ap = toVec( a,p ), ab = toVec( a,b );
  double u = dot( ap,ab ) / norm_sq( ab );
  c = translate( a,scale( ab, u ) );
  return dist( p, c );
}

double distToLineSegment( point p, point a, point b, point &c )
{
  vec ap = toVec( a, p ), ab = toVec( a,b );
  double u = dot( ap, ab ) / norm_sq( ab );
  if( u < 0.0 ) {
    return dist( p,a );
   }
  if( u > 1.0 )
  {
    return dist( p, b );
  }
  return distToLine( p, a, b, c);
}

int att( string a )
{
  int numero = 0;
  for(int i = 0 ; i < a.size() ; i++)
  {
    numero *= 10;
    numero += a[ i ] - '0';
  }
  return numero;
}

int main()
{
  string a;
  while( cin >> a && a != "*" )
  {
    int n = att( a );
    point centro(1,1),basura(1,1);
    cin >> centro.x >> centro.y;
    vector < point > p(n);
    for( int i = 0 ; i < n ; i++ )
    {
      cin >> p[ i ].x >> p[ i ].y;
    }
    p.push_back( p[ 0 ] );
    double minimo = 1000000.0;
    for(int i = 0 ; i < p.size()-1 ; i++)
    {
      minimo = min( minimo, distToLineSegment( centro, p[ i ], p[i+1 ], basura ) );
    }
    printf("%.3lf\n",minimo);
  }
}
