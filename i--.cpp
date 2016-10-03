#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

long A , B;
unsigned int potencia;
unsigned long long numMovimientos = 0;

vector < vector < bool > > visitados;

bool isIn( long x , long y )
{
	if( x >= 0 && y >= 0 )
		if( x <= A && y <= B )
			return true;
	return false;
}

void backtrack( long x , long y , long nmovement )
{
	visitados[x][y] = true;
	numMovimientos++;
	if( isIn( x , y + ( 1L << nmovement  ) ) )
		if( !visitados[x][y + ( 1L << nmovement )] )
		backtrack( x , y + ( 1L << nmovement ) , nmovement + 1 );
	if( isIn( x , y - ( 1L << nmovement  ) ) )
		if( !visitados[x][y - ( 1L << nmovement )] )
		backtrack( x , y - ( 1L << nmovement ) , nmovement + 1 );
	if( isIn( x + ( 1L << nmovement ) , y ) )
		if( !visitados[x + ( 1LL << nmovement )][y] )
		backtrack( x + ( 1LL << nmovement ) , y , nmovement + 1 );
	if( isIn( x - ( 1L << nmovement ) , y ) )
		if( !visitados[x - ( 1LL << nmovement )][y] )
		backtrack( x - ( 1L << nmovement ) , y , nmovement + 1 );
}

int main()
{
	int casos;
	potencia = 1;
	scanf( "%d" , &casos );
	while( casos-- )
	{
		scanf( "%ld %ld" , &A , &B );
		visitados.assign( A + 1 , vector < bool > ( B + 1 , false ) );
		numMovimientos = 0;
		if( isIn( 0 , 1 ) )
			backtrack( 0 , 1 , 1 );
		if( isIn( 1 , 0 ) )
			if( !visitados[1][0] )
				backtrack( 1 , 0 , 1 );
		printf( "%llu\n" , numMovimientos + 1);
	}
	return 0;
}
