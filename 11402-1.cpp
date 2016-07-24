#include <bitset>
#include <iostream>
#include <vector>

#define LIMIT 1024005

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("Case %d:\n", i + 1);
    int n, r, a, b;
    char fun;
    scanf("%d", &n);
    string temp;
    bitset<LIMIT> bit;
    int pos = 0;
    for (int j = 0; j < n; ++j) {
      scanf("%d ", &r);
      cin >> temp;
      while (r--) {
        for (int k = 0; k < temp.size(); ++k) {
          if (temp[k] == '1')
            bit.flip(pos);
          pos++;
        }
      }
    }

    // cout<<bit<<endl;
    scanf("%d", &n);
    r = 0;
    for (int j = 0; j < n; ++j) {

      cin >> fun;
      scanf("%d%d", &a, &b);
      // ft.print();
      // cout<<by<<" " << ft.rsq(a+1) <<" " <<ft.rsq(b+1)<<" "<<ft.rsq(a)<<endl;
      //  cout<<fun<<" "<<a<<" "<<b<<endl;

      if (fun == 'F') {
        for (; a <= b; ++a) {
          if (!bit[a]) {
            bit.flip(a);
          }
        }
      } else if (fun == 'E') {
        for (; a <= b; ++a) {
          if (bit[a]) {
            bit.flip(a);
          }
        }
      } else if (fun == 'I') {
        for (; a <= b; ++a) {
          bit.flip(a);
        }
      } else if (fun == 'S') {
        int tot = 0;
        for (; a <= b; ++a)
          if (bit[a])
            ++tot;
        // cout<<bit<<endl;
        printf("Q%d: %d\n", ++r, tot);
      }
    }
  }
  return 0;
}
