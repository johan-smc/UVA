#include <bits/stdc++.h>


using namespace std;

int sumDigit( string n)
{
  int sum=0;
  for( int i = 0 ; i < n.size() ; ++i )
  {
    sum+=n[i]-'0';
  }
  return sum;
}

string itoa( int n )
{
  ostringstream a;
  a << n;
  return a.str();

}

int main()
{
  string num;
  while( cin>>num && num!="END")
  {
    stringstream ss;
    int sumD=0;
    for( int i = 0 ; i < num.size() ; ++i )
    {
      sumD+=num[i]-'0';
    }
    ss<<num;
    int n;
    ss>>n;
    n--;
    int sum=0;
    while(  n )
    {
      sum=sumDigit(itoa(n));
      if( sum < sumD )
        break;
      n--;
    }
    printf("%d\n",n);

  }
}
