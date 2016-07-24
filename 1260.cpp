#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &arr[i]);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j)
        if (arr[i] >= arr[j])
          tot++;
    }
    printf("%d\n", tot);
  }
  return 0;
}
