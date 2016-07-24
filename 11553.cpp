#include <iostream>
#include <vector>

using namespace std;

int funcion(vector< vector<int> > &mat, vector<int> pasx, vector<int> pasy,
            int niv, int val, int fin,int t) {
  // cout<<niv<<" "<<val<<" "<<fin<<" "<<t<<endl;
  int men = 9999999;
  int i = niv;
    for (int j = 0; j < mat[i].size() && !pasx[i]; ++j) {
      if (!pasx[i] && !pasy[j]) {
        pasx[i] = true;
        pasy[j] = true;
        if (niv == fin)
          return val + mat[i][j];
        else
          men =
              min(funcion(mat, pasx, pasy, niv + 1,val + mat[i][j], fin,t), men);
        pasx[i] = false;
        pasy[j] = false;
      }
    }
  return men;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector< vector<int> > mat(n, vector<int>(n));
    vector<int> pasx(n, false);
    vector<int> pasy(n, false);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%d", &mat[i][j]);
    printf("%d\n", funcion(mat, pasx, pasy, 0, 0, n-1,t));
  }
  return 0;
}
