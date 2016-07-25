#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <queue>
#include <sstream>

#define foi( i , n , k ) for( int i = n ; i < k ; ++i )

using namespace std;

void funcion(map<string,vector<string> > &mp,string o,string pal)
{

  //  cout<<endl<<o<<" "<<pal<<endl;
    int dif=0;
    foi( i , 0 , (int)o.size() )
    {
      if(o[i]!=pal[i])
        dif++;
    }
    if(dif>1)
      return;
    //  cout<<"pase"<<endl;
    if(mp.find(o)==mp.end())
    {
      mp.insert(make_pair(o,std::vector<string> ()));
    }
    if(mp.find(pal)==mp.end())
    {
      mp.insert(make_pair(pal,std::vector<string> ()));
    }
    mp[o].push_back(pal);
    mp[pal].push_back(o);
}

int bfs(map<string,vector<string> > &mp,map<string,bool>pas,string ini,string fin)
{
  if( ini == fin )
    return 0;
  queue< pair<string,int> > q;
  q.push(make_pair(ini,0));
  while( !q.empty() )
  {
      string x=q.front().first;
      int c=q.front().second;
      pas[x]=true;
      q.pop();
      int n=(int)mp[x].size();
      // cout<<x<<" .. "<<n<<endl;
      foi( i , 0 , n)
      {
        string voy=mp[x][i];
        // cout<<voy<<" "<<!pas[voy]<<endl;
        if( !pas[voy] )
        {
          if(voy==fin)
            return c+1;
          q.push(make_pair(voy,c+1));
        }
      }
  }
  return -1;
}


int main()
{
  int n;
  scanf("%d",&n );
  cin.ignore();
  string fd;
  getline(cin,fd);
  foi( k , 0 , n )
  {
    if( k != 0 )
      printf("\n" );
    map<string,vector<string> > mp;
    map<string, bool> pas;
    vector<string> v;
    string pal;
    while(getline(cin,pal) && pal!="*")
    {
      foi( i , 0 , (int)v.size() )
      {
        if(v[i].size() == pal.size() )
          funcion(mp,v[i],pal);
      }
      v.push_back(pal);
      pas.insert(make_pair(pal,false));
    }
    string line,ini,fin;
    while(getline(cin,line) && line!= "")
    {
      stringstream ss(line);
      ss>>ini>>fin;
      cout<<ini<<" "<<fin;
      printf(" %d\n",bfs(mp,pas,ini,fin));
    }

  }
  return 0;
}
