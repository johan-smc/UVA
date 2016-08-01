#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

#define foi( i , n , k ) for( int i =  n ; i < k ; ++i)
using namespace std;

pair<int,int> fun(string s,map<char,pair<vector<int>::iterator , vector<int>::iterator > > mpit)
{
  int ini,fin,ant;
  ini=fin=ant=-1;
  foi( i , 0 , (int)s.size() )
  {
    if( mpit[s[i]].first == mpit[s[i]].second )
      return make_pair(-1,-1);
    if( i == 0  )
    {
      ini=(*mpit[s[i]].first);
    }
    else if( i+1==(int)s.size())
    {
      fin=(*mpit[s[i]].first);
    }
    char ss=s[i];
    if( (*mpit[s[i]].first)<ant )
    i--;
    else
    ant=(*mpit[s[i]].first);
    ++mpit[ss].first;

  }
  if((int)s.size() == 1 )
    fin=ini;
  // cout<<ini<<" "<<fin<<endl;
  return make_pair(ini,fin);
}

int main()
{
  string in;
  cin>>in;
  map<char,vector<int> > mp;
  map<char,pair<vector<int>::iterator , vector<int>::iterator > > mpit;
  foi( i , 0 , ( int )in.size() )
  {
    if( mp.find(in[i])==mp.end() )
    {
      mp.insert( make_pair(in[i],std::vector<int> ()) );
    }
    mp[in[i]].push_back(i);
  }
  for( map<char,vector<int> >::iterator it = mp.begin() ; it!=mp.end() ; ++it)
  {
    mpit.insert( make_pair(it->first,make_pair(it->second.begin(),it->second.end())) );
  }
  int n;
  scanf("%d",&n );
  while( n-- )
  {
    string s;
    cin>>s;
    pair<int,int> fin=fun(s,mpit);
    if(fin.first == -1 || fin.second == -1)
    {
      printf("Not matched\n");
    }
    else
    {
      printf("Matched %d %d\n",fin.first,fin.second);
    }
  }
  return 0;
}
