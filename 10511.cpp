#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

using namespace std;
#define MAX 10000
#define INF 1e9
#define INI 0
#define FIRST 1
#define SECOND 1010
#define THIRD 2020

vector< vector< int > > g;
map< int , map< int , int > > f;
vector< int > p;
map< string , int > clubs,names,partys;
map< int , string > clubsI;
int contName , contParty , contClubs;
vector< string > nam;
vector< string > lines;
int FIN;


bool bfs()
{
    p.assign(  FIN+10 , -1 );
    queue< int > q;
    q.push( INI );
    p[ INI ] = -2;
    int u ,v;
    while( !q.empty() )
    {
      u = q.front() ; q.pop();
      if( u == FIN )
        return true;
      for( int i = 0 ; i < (int)g[ u ].size() ; ++i )
      {
        v = g[ u ][ i ];
        if( p[ v ] == -1 && f[ u ][ v ] > 0 )
        {
          // cout << u << " " << v << "\n";
          q.push( v );
          p[ v] = u ;
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
    // cout << flow << " i\n" ;
    int men = INF ;
    for( int v = FIN , u = p[ v ] ; u != -2 ; v = u , u = p[ v ] )
    {
      men = min( men , f[ u ][ v ] );
    }
    for( int v = FIN , u = p[ v ] ; u != -2 ; v = u , u = p[ v ] )
    {
      f[ u ][ v ] -= men;
      f[ v ][ u ] += men;
    }
    flow += men;
    // cout << flow << " f\n" ;
  }
  return flow;
}

void build( string line )
{
  lines.push_back( line );
  stringstream ss( line );
  string name ;
   ss >> name;
  nam.push_back( name );
  if( names.find(name) == names.end() )
    names[ name ] = SECOND + contName++;
  // int nName = names[ name ];
  string party;
  ss >> party;
  if( partys.find( party ) == partys.end() )
    partys[ party ] = FIRST + contParty++;
  // int nParty = partys[ party ];


  string club;
  while( ss >> club )
  {
    if( clubs.find( club ) == clubs.end() )
    {
      clubsI[ THIRD + contClubs ] = club;
      clubs[ club ] = THIRD + contClubs++;
    }
    // int nClub = clubs[ club ];

  }
}
void build3( string line )
{
  stringstream ss( line );
  string name ;
   ss >> name;
  int nName = names[ name ];
  string party;
  ss >> party;
  int nParty = partys[ party ];

  g[ nName ].push_back( nParty );
  g[ nParty ].push_back( nName );
  f[ nName ][ nParty ] = 1;

  string club;
  while( ss >> club )
  {
    int nClub = clubs[ club ];
    g[ nClub ].push_back( nName );
    g[ nName ].push_back( nClub );
    f[ nClub ][ nName ] = 1;
  }
}

void build2()
{
  map< string , int >::iterator it;
  // int ff = clubs.size() / 2;
  // if( !(clubs.size()&1) )
  //   ff--;
  int ff = (clubs.size()-1)/2;
  int u;
  for( it = partys.begin() ; it != partys.end() ; ++it )
  {
    u = it->second;
    // cout << "UNION "<< INI << " " << u << "\n";
    g[ u ].push_back( FIN );
    // g[ FIN ].push_back( u );
    f[ u ][ FIN ] = ff;
  }
  for( it = clubs.begin() ; it != clubs.end() ; ++it )
  {
    u = it->second;
    g[ INI ].push_back( u );
    // g[ u ].push_back( INI );
    f[ INI ][ u ] = 1;
  }
}

void print()
{
  map< string , int >::iterator it;
  int u , v,vv;
  // for( it = names.begin() ; it != names.end() ; ++it  )
  // {
  //   v= it->second;
  //   for( int i = 0 ; i < (int)g[ v ].size() ; ++i )
  //   {
  //     u = g[ v ][ i ];
  //     if( clubsI.find( u ) != clubsI.end() && f[ u ][ v ] == 0 && f[ v ][ u ] > 0)
  //     {
  //       cout << it->first << " " << clubsI[ u ]<<"\n" ;
  //     }
  //   }
  // }
  for( int i = 0 ; i < (int)nam.size() ; ++i )
  {
    v = names[ nam[ i ] ];
    for( int j = 0 ; j < (int)g[ v ].size() ; ++j )
    {
      u = g[ v ][ j ];
      for( int k = 0 ; k < (int)g[ u ].size(); ++k )
      {
        vv = g[ u ][ k ];
        // cout << u << " " << v << " " << vv << "\n";
        if( vv == v && f[ u ][ v ] == 0 && clubsI.find( u ) != clubsI.end() )
        {
          cout << nam[ i ] << " " << clubsI[ u ] << "\n";
          goto ter;
        }
      }
    }
    ter:;
  }
}

int main()
{
  int t;
  cin >> t;
  string line;
  getline( cin , line );
  getline( cin , line );
  int c =0 ;
  while( t-- )
  {
    if( c++ )
      cout << "\n";
    f.clear();
    names.clear();
    partys.clear();
    clubs.clear();
    clubsI.clear();
    nam.clear();
    lines.clear();
    contParty = contName = contClubs = 0;
    while( getline( cin , line ) && line != "" )
    {
        build( line );
    }
    FIN = THIRD+contClubs +5;
    g.assign( FIN + 10 , vector< int >() );
    for( int i = 0;  i < (int)lines.size() ;++i )
      build3( lines[ i ] );
    build2();
    if(  flujo() ==(int) clubs.size() )
     print();
    else
      cout << "Impossible.\n";
  }
}
