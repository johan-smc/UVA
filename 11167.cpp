#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;
#define MAX 400
#define INF 1e9
#define INI 0
#define FIN 399
#define FIRST 1
#define SECOND 105

struct Monkey
{
  int  v , a , b;
  friend istream& operator>>( istream&is, Monkey& m )
  {
    is >> m.v >> m.a >> m.b ;
    return is;
  }
};

typedef pair< int , int > ii;

vector< vector< int > > g;
vector< vector< ii > > res,res2;
int f[ MAX ][ MAX ];
int ft[ MAX ][ MAX ];
int p[ MAX ];
set< int > par;
vector< int > par2;
vector< Monkey > monkeys;
int n , m ;

bool bfs()
{
  memset( p , -1 , sizeof p );
  queue< int > q;
  q.push( INI );
  p[ INI ] = -2;
  int u , v;
  while( !q.empty() )
  {
    u = q.front(); q.pop();
    if( u == FIN )
      return true;
    for( int i = 0 ; i < (int)g[ u ].size() ; ++i )
    {
      v = g[ u ][ i ];
      // cout << "IN " << u << " " << v << " " << p[ v ] << " " << f[ u ][ v ] << "\n";
      if( p[ v ] == -1 && f[ u ][ v ] > 0 )
      {
        // cout <<"I "<<  u << " " << v << "\n";
        q.push( v );
        p[ v ] = u;
      }
    }
  }
  return false;
}

int flujo()
{
  int flow = 0;
  while( bfs() )
  {
      int men = INF ;
      for( int v = FIN , u = p[ v ] ; u != -2 ; v = u , u = p[ v ] )
      {
        // cout << "P " << u << " " << v << "\n";
        men = min( men , f[ u ][ v ] );
      }
      // cout << " MEN " << men << "\n";
      for( int v = FIN , u = p[ v ] ; u != -2 ; v = u , u = p[ v ] )
      {
        f[ u ][ v ] -= men;
        f[ v ][ u ] += men;
      }
      flow += men;
  }
  return flow;
}

void build()
{
  set< int >::iterator it;
  set< int >::iterator it2 ;
  int cont;
  for( int i =  0 ; i < n ; ++i )
  {

    cont = 0;
    for( it2 = par.begin() , it = it2++ ; it2 != par.end() ; ++it2 , ++it )
    {
      // cout << monkeys[ i ].a << " " << (*it) << " # " << monkeys[ i ].b<< " " << (*it2) << "\n";
      if( monkeys[ i ].a <= (*it) && monkeys[ i ].b >= (*it2) )
      {
        cout << "uni " << FIRST+i << " " << SECOND + cont << " "<< ((*it2)-(*it))<<  "\n";
        g[ FIRST + i ].push_back( SECOND + cont );
        g[ SECOND + cont ].push_back( FIRST +  i);
        f[ FIRST + i ][ SECOND + cont ] =((*it2)-(*it));
      }
      ++cont;
    }

  }
  cont = 0;
  for( it2 = par.begin() , it = it2++ ; it2 != par.end() ; ++it2 , ++it )
  {
    g[ SECOND + cont ].push_back( FIN );
    g[ FIN ].push_back( SECOND + cont );

    cout << "uni " << SECOND + cont << " " << FIN << " " << m*((*it2)-(*it))  << "\n";
    f[ SECOND + cont ][ FIN ] = m * ((*it2)-(*it));
    ++cont;
  }
}
void save()
{
  par2.clear();
  set< int >::iterator it;
  for( it = par.begin() ; it != par.end() ; ++it )
  {
    // cout << par2.size() << " " << *it << "#\n";
    par2.push_back( *it );
  }
}

void process()
{
  int u , v ,uu;
  int tot = 0;
  int resta;
  for( int i = 0 ; i < n ; ++i )
  {
    u = i+FIRST;
    tot = monkeys[ i ].v;
    for( int j = 0; j < (int)g[ u ].size() && tot > 0; ++j )
    {
      v = g[ u ][ j ];
      // cout << "AI " << u << " " << v << "\n";
      if( v == INI )  continue;
      for( int k = 0 ; k < (int)g[ v ].size() && tot > 0; ++k )
      {
        uu = g[ v ][ k ];
        // cout << "intente "<< u << " " << v << " " << uu << " " << f[ u ][ v ]<<  "\n";
        if( u == uu  && f[ u ][ v ] != ft[ u  ][ v ] )
        {
          // cout << u << " " << v << " " << par2[ v-SECOND ]<< " " <<par2[(v-SECOND)+1]<<  "\n";
          // tot += (par2[(v-SECOND)+1] -par2[ v-SECOND ]);
          resta = (par2[(v-SECOND)+1] -par2[ v-SECOND ]);
          res2[ i ].push_back( ii(par2[ v-SECOND ] , par2[(v-SECOND)+1]) );
          int pos = res2[ i ].size()-1;
          if( resta > tot )
          {
            // cout << "MAYOR\n";
            res2[ i ][ pos ].second = res2[ i ][ pos ].first + tot;
          }
          tot -= resta;
          break;
        }
      }
    }
  }
  for( int i = 0 ; i < (int)res2.size() ; ++i )
  {
    for( int j = 0 ; j < (int)res2[ i ].size() ; ++j )
    {
      if( j == 0 )
        res[ i ].push_back( res2[ i ][ j ] );
      else
      {
        int pos = res[ i ].size() -1;
        // cout << res[ i ][ pos ].first  << " " << res[ i ][ pos ].second << " ,,, ";
        // cout << res2[ i ][ j ].first  << " " << res2[ i ][ j ].second << " ,, ";
        if( res[ i][ pos ].second == res2[ i ][ j ].first )
          res[ i ][ pos ].second = res2[ i ][ j ].second;
        else
          res[ i ].push_back( res2[ i ][ j ] );
      }
    }
  }
  // for( int i = 0 ; i < (int)res.size() ; ++i )
  // {
  //   for( int j = 0 ; j < (int)res[ i ].size() ; ++j )
  //   {
  //       cout << res[ i ][ j ].first  << " " << res[ i ][ j ].second << " , ";
  //     }
  //     cout << "\n";
  //   }
  // cout <<"tot " << tot << "\n";
  // return tot;
}

void copy()
{
  for( int i = 0 ; i < MAX ; ++i )
    for( int j = 0 ;j < MAX ; ++j )
      ft[ i ][ j ] = f[ i ][ j];
}

void print()
{
  cout << "Yes\n";
  for( int j = 0 ; j < (int)res.size() ; ++j )
  {

    cout << res[ j ].size() ;
    for( int i = 0 ; i < (int)res[ j ].size() ; ++i )
    {
      cout << " (" << res[ j ][ i ].first << ","<<res[ j ][i].second <<")";
    }
    cout << "\n";
  }
}

int main()
{
  int c=0;
  while( cin >> n  && n )
  {
    cin >> m;
    int tot;

    memset( f , 0 , sizeof f );
    memset( ft , 0 , sizeof ft );
    g.assign( MAX , vector< int >() );
    par.clear();
    monkeys.resize( n  );
    tot = 0;
    res.assign( n , vector< ii >() );
    res2.assign( n , vector< ii >() );
    for( int i = 0;  i < n ; ++i )
    {
      cin >> monkeys[ i ];
      par.insert( monkeys[ i ].a );
      par.insert( monkeys[ i ].b );

      tot += monkeys[ i ].v;
      g[ INI ].push_back( i + FIRST );
      g[ i+FIRST ].push_back( INI );
      f[ INI ][ i+FIRST ] = monkeys[ i ].v;
      cout << "uni " << INI << " " << i+FIRST<< " " << monkeys[ i ].v  << "\n";

    }
    // int num = *par.begin();
    // par.erase( par.begin() );
    // par.insert( num-1 );
    save();
    build();
    copy();
     cout << "Case " << ++c << ": ";
    //  process();
    if( tot == flujo() )
    {
      process();
      print();
    }
    else
      cout << "No\n";
  }
  return 0;
}
