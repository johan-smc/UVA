#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#define foi( i , n , k ) for( int i =  n ; i < k ; ++i)
using namespace std;

struct unio{

  int pos;
  char c;
  unio(){};
  unio( char a)
  {
    c=a;
  }
  bool  operator<(const unio & other)const
  {
        return ((this->c)<(other.c));
  }
};

pair<int,int> funcion(vector<unio>&v,string q)
{
  int ini=-1,fin=-1;

  // cout<<in<<endl<<q<<endl;
  vector<unio>::iterator it=v.begin();
  // vector<unio>::iterator ant=v.begin();
  vector<unio> qq((int)q.size());
  foi( i , 0 , (int)q.size() )
  {
    unio temp;
    temp.c=q[i];
    temp.pos=i;
    qq[i]=temp;
  }
  int ant=-1;
  stable_sort(qq.begin(),qq.end());
  foi( i , 0 , (int)q.size() )
  {
    cout<<qq[i].c;
    if( !binary_search(it, v.end(), qq[i]) )
      return make_pair(-1,-1);
    it=lower_bound( it , v.end() , qq[i] );
    /*if( (*it).pos < ant )
      break;
    ant=(*it).pos;*/
    if( (qq[i]).pos == 0 )
      ini=(*it).pos;
    if( qq[i].pos == (int)q.size()-1 )
    {
      while( (*it).pos < ant )
      {
        ++it;
        if( !binary_search(it, v.end(), qq[i]) )
          return make_pair(-1,-1);
        it=lower_bound( it , v.end() , qq[i] );
      }
      fin=(*it).pos;
    }
    if(ant<(*it).pos)
      ant=(*it).pos;
    it++;
  }
  return make_pair(ini,fin);
}

int main()
{
  string in;
  cin>>in;
  int n;
  vector<unio> v(in.size());
  foi( i , 0 , (int)in.size() )
  {
    unio temp;
    temp.c=in[i];
    temp.pos=i;
    v[i]=temp;
  }
  stable_sort( v.begin() , v.end() );
  scanf("%d",&n);
  while( n-- )
  {
    string q;
    cin>>q;
    pair<int,int> res=funcion(v,q);
    if(res.first == -1 || res.second == -1)
    {
      printf("Not matched\n");
    }
    else
    {
      printf("Matced %d %d\n",res.first,res.second);
    }
  }
  return 0;
}
