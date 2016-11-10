#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>


using namespace std;
#define INF 1<<27

int n;

void floyd( int arr[ 27 ][ 27 ] )
{
  for( int k = 0 ; k < 26 ; ++k )
    for( int i = 0 ; i < 26 ; ++i )
      for( int j = 0 ; j < 26 ; ++j )
        arr[ i ][ j ] = min ( arr [ i ][ j ] , arr[ i ][ k ] + arr[ k ][ j ] );
}

int main()
{
  int graphI[ 27 ][ 27 ];
  int graphMiguel[ 27 ][ 27 ];
  while( scanf("%d",&n ), n )
  {
    for( int i = 0 ; i < 27 ; ++i )
      for( int j = 0 ; j < 27 ; ++j )
      {
        graphI[ i ][ j ] = i==j?0:INF;
        graphMiguel[ i ][ j ] = i==j?0:INF;
      }
    char p,d,ini,fin;
    int val;
    for( int i = 0 ; i < n ; ++i )
    {
      scanf(" %c %c %c %c %d",&p,&d,&ini,&fin,&val );
      if( p == 'Y')
      {
          graphI[ ini-'A' ][ fin-'A' ] =  min (graphI[ ini-'A' ][ fin-'A' ],val);
          if( d == 'B' )
            graphI[ fin-'A' ][ ini-'A' ] =  min (graphI[ fin-'A' ][ ini-'A' ],val);

      }
      else
      {
          graphMiguel[ ini-'A' ][ fin-'A' ] = min (graphMiguel[ ini-'A' ][ fin-'A' ],val);
          if( d == 'B' )
            graphMiguel[ fin-'A' ][ ini-'A' ] = min (graphMiguel[ fin-'A' ][ ini-'A' ],val);

      }
      // cout << "estue " << endl;
    }
    // cout << "jaja " << endl;
    scanf(" %c %c",&ini,&fin );
    // cout << "ley" << endl;
    floyd( graphI );
    floyd( graphMiguel );
    int men=INF;
    queue< char > pasos;
    for( int j = 0 ; j < 26 ; ++j )
    {
      int menI, menMiguel;
      menI = menMiguel = INF;
      menI =  graphI[ ini-'A' ][ j ] ;
      menMiguel =  graphMiguel[ fin-'A' ][ j ];
      if( menI != INF && menMiguel != INF )
      {
        if( men > menI + menMiguel )
        {
          men = menI + menMiguel;
          while( !pasos.empty() ) pasos.pop();
          pasos.push( 'A'+j );
        }
        else if( men == menI + menMiguel )
          pasos.push( 'A'+j );
      }
    }
    if( men == INF )
      printf("You will never meet." );
    else
    {
      printf("%d ",men );
      while( !pasos.empty() )
      {
        printf("%c",pasos.front() );
        pasos.pop();
        if( !pasos.empty() )
          printf(" ");
      }
    }
    printf("\n" );
  }
  return 0;
}
