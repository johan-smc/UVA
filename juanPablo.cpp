#include <cstdio>
#include <iostream>
#include <vector>



using namespace std;
#define MAX 20000000

void makeCriba(std::vector<bool> & v) {
  for (long long i = 2; i < MAX ; i++) {
    if (v[i]) {
      for (long long j = i*i; j < MAX; j+=i) {
        v[j] = false;
      }
    }
  }
}

int main () {
  vector<bool> criba (MAX,true);
  vector<long long> primos;
  makeCriba(criba);
  criba[0] = criba[1] = false;
  for (long long i = 0; i < MAX; i++) {
    if (criba[i]) primos.push_back(i);
  }
  for (int i = 0; i < 100; i++) {
    cout << primos[i] << " ";
  }
}
