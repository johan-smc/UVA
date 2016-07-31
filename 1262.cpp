  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <cstdio>
  #include <set>

  #define foi( i , n , k ) for( int i = n  ; i <  k ; ++i )
  using namespace std;

  string back(vector< vector< char > > &pri,vector< vector< char > > &sec,int pos,int &tot,string llevo,int n,set<string>&rep)
  {
    if( pos == 5 )
    {
      if(rep.find(llevo)==rep.end())
      {
        rep.insert(llevo);
          ++tot;
          if(tot==n)
            return llevo;
      }

    }
    else
    {
      string res;
      foi( i , 0 , 6 )
      {
        vector<char> :: iterator it= find(sec[pos].begin(),sec[pos].end(),pri[pos][i]) ;
        if(sec[pos].end()!=it)
        {
          res=back(pri,sec,pos+1,tot,llevo+pri[pos][i],n,rep);
          if(res!="")
            return res;
        }
      }
    }
    return "";
  }

  int main()
  {
    int t;
    scanf("%d",&t);
    vector< vector< char > > pri,sec;
    pri=sec=vector< vector< char > >(5,vector<char>(6));
    while( t-- )
    {
      int n;
      scanf("%d",&n);
      foi( i , 0 , 6)
      {
        foi( j , 0 , 5 )
        {
          scanf(" %c",&pri[j][i]);
        }
      }
      foi( i , 0 , 6)
      {
        foi( j , 0 , 5 )
        {
          scanf(" %c",&sec[j][i]);
        }
      }
      foi( i , 0 , 5 )
      {
        sort(pri[i].begin(),pri[i].end());
        sort(sec[i].begin(),sec[i].end());
      }
      int tot=0;
      set<string> rep;
      string res=back(pri,sec,0,tot,"",n,rep);
      if(res=="")
        printf("NO\n" );
      else
        cout<<res<<endl;
    }
    return 0;
  }
