#include <iostream>
#include <vector>

using namespace std;

int arr[43] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
               15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33,
               34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};
pair<int, int> funcion(int n) {
  int c, p;
  c = p = 0;
  for (int i = 0; i < 43; ++i) {
    for (int j = 0; j < 43; ++j) {
      for (int k = 0; k < 43; ++k) {
        int num = arr[i] + arr[j] + arr[k];
        if (num == n) {
          cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
          c++;
          /*if (arr[i] == arr[j] && arr[i] == arr[k])
            p++;
          else*/
          p += 3;
        }
      }
    }
  }
  return make_pair(c, p);
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF && n > 0) {
    pair<int, int> num = funcion(n);
    if (num.first == 0 && num.second == 0) {
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    } else {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, num.first);
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, num.second);
    }
    printf("*******************************************************************"
           "***\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
