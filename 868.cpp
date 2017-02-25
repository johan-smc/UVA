#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef pair< int , int > ii;
typedef pair< ii , ii > result;

// struct result
// {
//   ii first,second;
//   bool operator<(const result &o )const
//   {
//     if( this->first == o.first )
//       return this->second < o.second;
//     return this->first < o.first;
//   }
//   result( ii a , ii b )
//   {
//     this->first = a;
//     this->second = b;
//   }
//   result(){};
// };

int xx[ 4 ] = { -1 , 0 , 0 , 1 };
int yy[ 4 ] = { 0 , -1 , 1 , 0 };

int n,m;
vector< vector< int > > mat;
queue< ii > fin;

int fo( int p )
{
  // cout << "foooo "<< endl;
  int num = 1;
  while( p > num )
  {
    p -= num;
    ++num;
  }
  return p;
}

bool isGood( int x, int y , int p )
{
  // cout << x << " " << y << " iis" << endl;
  if( x < 0 || x >= n || y < 0 || y >= m   )
    return  false;
  // cout << "funciono "<< mat[x] [y] <<endl;
  // cout << "foooo == " << fo(p);
  return mat[ x ][ y ] == fo( p );
}

void back( int x, int y , int p )
{
  // cout << x << " "<< y << " " << p << " " << mat[x][y] << endl;
  if( x == n-1 )
  {
    // cout << "nnn" << endl;
    fin.push( ii(x,y) );
    return;
  }
  for( int i = 0 ; i < 4 ; ++i )
  {
    // cout << x << " " << y << " " << i  << " jjj "<< endl;
     int nextx = x + xx[ i ];
     int nexty = y + yy[ i ];
     if( isGood(nextx,nexty,p+1) )
     {
      //  cout << "entre" << endl;
      // cout << nextx << " " << nexty << " " << p+1 << " " << mat[nextx][nexty] << endl;
      int  aux = mat[ nextx ][ nexty ];
      mat[ nextx ][ nexty ] = -1;
       back( nextx , nexty , p+1 );
       mat[ nextx ][ nexty ] = aux;

     }
  }

}

result fun( )
{
  priority_queue< result , std::vector<result> , greater<result> > f;
  for( int i  = 0 ; i < m ; ++i )
  {
    if( mat[ 0 ][ i ] == 1 )
    {

      // cout << i << " j " << endl;
      mat[ 0 ][ i ] = -1;
      back(0,i,1);
      mat[ 0 ][ i ] = 1;
    }
    while( !fin.empty() )
    {
      f.push(result(ii(0,i),ii(fin.front())));
      fin.pop();
    }
  }
  // result jkl ;
  // while(!f.empty())
  // {
  //   cout<< "jjfkdsla" << endl;
  //   printf("%d %d\n",f.top().first.first+1,f.top().first.second +1);
  //   printf("%d %d\n",f.top().second.first+1,f.top().second.second +1);
  //   jkl = f.top();
  //   f.pop();
  // }
  //
  // return jkl;
   return f.top();
}


int main()
{
  // cout << fo(3) << endl;
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    scanf("%d %d",&n,&m);
    // cout << n << " " << m << " in "<< endl;
    mat.assign( n , vector< int > (m) );
    for( int i = 0 ; i < n ; ++i )
      for( int j = 0 ; j < m ; ++j )
        scanf("%d",&mat[ i ][ j ] );
    result res = fun();
    printf("%d %d\n",res.first.first+1,res.first.second +1);
    printf("%d %d\n",res.second.first+1,res.second.second +1);
    if( t != 0 )
    printf("\n");
  }
  return 0;
}
