#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  fstream out("out.out");
  for (double i = 0.01; i < 20.00; i += 0.01) {
    for (double j = i; j < 20.00; j += 0.01) {
      if (i * j > 20.00)
        break;
      for (double k = j; k < 20.00; k += 0.01) {
        if (i * j * k > 20.00)
          break;
        for (double n = k; n < 20.00; n += 0.01) {
          printf("%lf %lf %lf %lf ------… %lf\n", i, j, k, n, i * j * k * n);
          if (i * j * k * n > 20.00)
            break;
          if (i * j * k * n == i + j + k + n) {
            printf("%lf %lf %lf %lf\n", i, j, k, n);
            out << i << " " << j << " " << k << " " << n << endl;
          }
        }
      }
    }
  }
  return 0;
}
