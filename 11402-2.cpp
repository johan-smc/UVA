#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
  vector<int> st;
  vector<int> arr;
  vector<pair<int, char>> lazy;
  int n;
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = arr[L];
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), ((L + R) / 2) + 1, R);
      st[p] = st[left(p)] + st[right(p)];
    }
  }
  int calcular(int valor,char tipe,int L,int R)
  {
    R++;
      if( tipe == 'F')
        return (R-L)-valor;
      if( tipe == 'E')
        return -(valor);
      if( tipe == 'I')
        return ((R-L)-valor)-valor;
      return 0;
  }
  int propagation(int p, int L, int R, char tipe) {
  }
  int rsq(int p, int L, int R, int i, int j) {
    if (i > R || j < L)
      return 0;
    if (lazy[p].second != '')
      propagation(p, L, R);
    if (L >= i && R <= j) {
      return st[p];
    }

    int sum1 = rsq(left(p), L, (R + L) / 2, i, j);
    int sum2 = rsq(right(p), ((R + L) / 2) + 1, R, i, j);
    return sum1 + sum2;
  }
  void upload(int p, int L, int R, int a, int b, char tipe) {
    if (i > R || j < L)
      return ;
    if (L >= i && R <= j) {
      propagation(p,L,R,tipe);
      st[p]+=calcular(st[p],tipe,L,R);
    }
    else{
      if (lazy[p].second != '')
        propagation(p, L, R);


      int sum1 = upload(left(p), L, (R + L) / 2, a, b,tipe);
      int sum2 = upload(right(p), ((R + L) / 2) + 1, R, a, b,tipe);
      st[p] =sum1 + sum2;
    }
  }

public:
  SegmentTree(const vector<int> &arr_) {
    arr = arr_;
    n = arr.size();
    st.assign(n * 4, 0);
    lazy.assign(n * 4, make_pair(0,''));
    build(1, 0, n - 1);
  }
  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }

  void upload(int a, int b, int fun) { upload(1, 0, n - 1, a, b); }

  void printA() {
    for (int i = 0; i < arr.size(); ++i)
      cout << arr[i] << " ";
    cout << endl;
  }
  void printST() {
    for (int i = 0; i < st.size(); ++i)
      cout << st[i] << " ";
    cout << endl;
  }
};

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 0; k < t; ++k) {
    int n, r, a, b;
    scanf("%d", &n);
    char temp[55];
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &r);
      scanf("%s", temp);
      while (r--) {
        for (int j = 0; temp[j] != '\0'; ++j) {
          arr.push_back((int)(temp[j] - '0'));
        }
      }
    }
    SegmentTree st(arr);
    r = 0;
    scanf("%d", &n);
    char tipe;
    printf("Case %d:\n", k + 1);
    for (int i = 0; i < n; ++i) {

      scanf("%c", &tipe);
      scanf("%d%d", &a, &b);

      // st.printA();
      // st.printST();
      // cout<<tipe<<" "<<a<<" "<<b<<endl;

      if (tipe == 'S') {

        printf("Q%d: %d\n", ++r, st.rsq(a, b));
      } else
        st.upload(a, b, tipe);
    }
  }
  return 0;
}
