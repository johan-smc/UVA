#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

struct Player{
  int id,p,time;
  bool print;
  vector<bool> pro;
  vector<int> timeP;
  bool operator<(const Player&o)const
  {
    if(this->p==o.p && this->time==o.time)
      return this->id<o.id;
    if( this->p==o.p )
      return this->time<o.time;
    return this->p > o.p;
  }
};
int main()
{
  int n;
  string line;
  scanf("%d",&n);
  int c,p,t;
  char pp;
  cin.ignore();
  getline(cin,line);
  vector<Player> players(100);
  while(n--)
  {
    Player temp;
    temp.p=0;
    temp.print=false;
    temp.time=0;
    temp.pro=vector<bool>(10,false);
    temp.timeP=vector<int>(10,0);
    for( int i  =0  ;i < 100 ; ++i )
    {
      temp.id=i+1;
      players[i]=temp;
    }
    while( getline(cin,line) && line!="")
    {
      stringstream s;
      s<<line;
      s>>c>>p>>t>>pp;
      c--;
      // cout<<c<<" num "<<endl;
      players[c].print=true;
      if( pp=='I')
      {
        players[c].timeP[p]+=20;
      }
      else if(pp=='C' && !players[c].pro[p] )
      {
        players[c].pro[p] =true;
        players[c].p++;
        players[c].time+=(players[c].timeP[p]+t);
      }
    }
    sort(players.begin(),players.end());
    for( int i = 0 ; i < 100 ; ++i )
    {
      // cout<<players[c].print<<" -- "<<endl;
      if(players[i].print)
      {
        printf("%d %d %d\n",players[i].id,players[i].p,players[i].time);
      }
    }
    if(n!=0)printf("\n");
  }
  return 0;
}
