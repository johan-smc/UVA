#include <iostream>
#include <vector>

using namespace std;

typedef pair< long , long > pll;

struct Complejo
{
  long numero;
  int potencia;
}

struct Suma
{
  long numero;
  Complejo complex;
};

Suma base;

int i;
vector< Suma > posiblesSumas;

pll ezProblem( unsigned long numero )
{
  i = 0;
}

int main()
{

  pll answer;
  unsigned long numero;
  base.numero = -1;
  base.complex.numero = 1;
  base.complex.potencia = 1;
  posiblesSumas[0] = 1;
  posiblesSumas[1] = base;
  for( int t = 2 ; t < 34 ; t++ )
  {
    posiblesSumas[t] = multiplicar( base , posiblesSumas[ t - 1 ] );
  }
  while( scanf("%d", &numero ) != EOF )
  {
    answer = ezProblem( numero );
    printf( "%lld %lld\n" , answer.first , answer.second );
  }
  return 0;
}
