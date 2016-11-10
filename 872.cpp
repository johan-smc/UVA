#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <bitset>
#include <queue>
#include <sstream>
#include <set>

using namespace std;
std::vector< std::vector< int > > graph;
std::vector< char > word;
int cont;

// void dfs( int n , bitset<30> possible ,bitset<30> visited , string voy , priority_queue< string , std::vector<string> , greater<string> >  &imp )
void dfs( int n , bitset<30> possible ,bitset<30> visited , string voy , set<string>  &imp )
{
  // cout<< n << " " << voy << endl;
  // cout << n << possible << endl;
  visited[ n ] = 1;
  bool push = true;
  for( int i = 0; i < graph[n].size() ; ++i ){
    if( visited[ graph[ n ][ i ] ] )
      return;
    possible[ graph[ n ][ i ] ] = 1;
  }
  for( int i = 0 ; i <cont  ; ++i )
  {
    if( !visited[i] && possible[i] )
    {
      push = false;
      dfs( i, possible , visited , voy+" "+word[ i ] , imp );
    }
  }
  if( push  && voy.size() == (cont * 2)-1 )
    // imp.push( voy );
    imp.insert( voy );
}

int main()
{
  int t,aux,aux2;
  cin >> t;
  cin.ignore();
  string firstLine,secondLine;
  char a,b,c;
  word.assign( 30 ,0);
  while( t-- )
  {
    bitset< 30 > possible;
    bitset< 30 > visited;
    map< char , int > map;
    possible.set();
    cont = 0;
      // printf("\n");

    cin.ignore();
    getline( cin , firstLine );
    getline( cin , secondLine );
    // cout << firstLine <<endl;
    // cout << secondLine << endl;
    stringstream ss(firstLine);
    while( ss >> a )
    {
      // cout << "map" << endl;
      word[ cont ] = a;
      map[ a ] = cont++;

    }
    graph.assign( cont , std::vector<int>() );
    ss.clear();
    stringstream sss( secondLine );
    while( sss >> a >> c >> b )
    {
      // cout << a << " " << c << " " << b<< endl;
      aux = map[ b ];
      aux2 = map[ a ];
      // cout << aux2 << " " << aux << endl;
      graph[ aux2 ].push_back( aux ) ;
      possible[ aux ] = 0;
    }
    // cout << "hola" << endl;
    // priority_queue< string , std::vector<string> , greater<string> > imp;
    set< string > imp;
    string pal;
    for( int i = 0; i < cont ; ++i  )
    {

      if( possible[i] )
        dfs( i , possible, visited , pal = word[ i ] , imp );
    }
    if( imp.empty() )
      cout << "NO\n" ;
    else
    for( set<string>::iterator it = imp.begin() ; it != imp.end() ; ++it )
      cout << *it << "\n";

      /*
      while( !imp.empty() )
      {
        cout << imp.top() << "\n";
        imp.pop();
      }*/
      if( t != 0 )
      cout << "\n";
  }

}
